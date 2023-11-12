$NetBSD: patch-src_joystick_darwin_SDL__sysjoystick.c,v 1.1 2023/11/12 21:28:04 nia Exp $

Restore support for Mac OS X 10.4, from "TigerPorts":
https://raw.githubusercontent.com/evanmiller/TigerPorts/master/devel/libsdl2/files/patch-SDL2-2.0.3_OSX_104.diff

--- src/joystick/darwin/SDL_sysjoystick.c.orig	2014-03-16 02:31:41.000000000 +0000
+++ src/joystick/darwin/SDL_sysjoystick.c
@@ -1,6 +1,6 @@
 /*
   Simple DirectMedia Layer
-  Copyright (C) 1997-2014 Sam Lantinga <slouken@libsdl.org>
+  Copyright (C) 1997-2013 Sam Lantinga <slouken@libsdl.org>
 
   This software is provided 'as-is', without any express or implied
   warranty.  In no event will the authors be held liable for any damages
@@ -18,11 +18,31 @@
      misrepresented as being the original software.
   3. This notice may not be removed or altered from any source distribution.
 */
-#include "../../SDL_internal.h"
+#include "SDL_config.h"
 
 #ifdef SDL_JOYSTICK_IOKIT
 
+/* SDL joystick driver for Darwin / Mac OS X, based on the IOKit HID API */
+/* Written 2001 by Max Horn */
+
+#include <unistd.h>
+#include <ctype.h>
+#include <sysexits.h>
+#include <mach/mach.h>
+#include <mach/mach_error.h>
+#include <IOKit/IOKitLib.h>
+#include <IOKit/IOCFPlugIn.h>
+#ifdef MACOS_10_0_4
+#include <IOKit/hidsystem/IOHIDUsageTables.h>
+#else
+/* The header was moved here in Mac OS X 10.1 */
+#include <Kernel/IOKit/hidsystem/IOHIDUsageTables.h>
+#endif
 #include <IOKit/hid/IOHIDLib.h>
+#include <IOKit/hid/IOHIDKeys.h>
+#include <CoreFoundation/CoreFoundation.h>
+#include <Carbon/Carbon.h>      /* for NewPtrClear, DisposePtr */
+#include <IOKit/IOMessage.h>
 
 /* For force feedback testing. */
 #include <ForceFeedback/ForceFeedback.h>
@@ -33,365 +53,639 @@
 #include "../SDL_joystick_c.h"
 #include "SDL_sysjoystick_c.h"
 #include "SDL_events.h"
-#include "../../haptic/darwin/SDL_syshaptic_c.h"    /* For haptic hot plugging */
 #if !SDL_EVENTS_DISABLED
 #include "../../events/SDL_events_c.h"
 #endif
 
-/* The base object of the HID Manager API */
-static IOHIDManagerRef hidman = NULL;
 
 /* Linked list of all available devices */
 static recDevice *gpDeviceList = NULL;
-
-/* if SDL_TRUE then a device was added since the last update call */
+/* OSX reference to the notification object that tells us about device insertion/removal */
+IONotificationPortRef notificationPort = 0;
+/* if 1 then a device was added since the last update call */
 static SDL_bool s_bDeviceAdded = SDL_FALSE;
 static SDL_bool s_bDeviceRemoved = SDL_FALSE;
 
 /* static incrementing counter for new joystick devices seen on the system. Devices should start with index 0 */
 static int s_joystick_instance_id = -1;
 
-
 static void
-FreeElementList(recElement *pElement)
+HIDReportErrorNum(char *strError, long numError)
 {
-    while (pElement) {
-        recElement *pElementNext = pElement->pNext;
-        SDL_free(pElement);
-        pElement = pElementNext;
-    }
+    SDL_SetError(strError);
 }
 
-static recDevice *
-FreeDevice(recDevice *removeDevice)
-{
-    recDevice *pDeviceNext = NULL;
-    if (removeDevice) {
-        /* save next device prior to disposing of this device */
-        pDeviceNext = removeDevice->pNext;
+static void HIDGetCollectionElements(CFMutableDictionaryRef deviceProperties,
+                                     recDevice * pDevice);
 
-        if ( gpDeviceList == removeDevice ) {
-            gpDeviceList = pDeviceNext;
-        } else {
-            recDevice *device = gpDeviceList;
-            while (device->pNext != removeDevice) {
-                device = device->pNext;
-            }
-            device->pNext = pDeviceNext;
-        }
-        removeDevice->pNext = NULL;
-
-        /* free element lists */
-        FreeElementList(removeDevice->firstAxis);
-        FreeElementList(removeDevice->firstButton);
-        FreeElementList(removeDevice->firstHat);
-
-        SDL_free(removeDevice);
-    }
-    return pDeviceNext;
-}
+/* returns current value for element, polling element
+ * will return 0 on error conditions which should be accounted for by application
+ */
 
 static SInt32
-GetHIDElementState(recDevice *pDevice, recElement *pElement)
+HIDGetElementValue(recDevice * pDevice, recElement * pElement)
 {
-    SInt32 value = 0;
-
-    if (pDevice && pElement) {
-        IOHIDValueRef valueRef;
-        if (IOHIDDeviceGetValue(pDevice->deviceRef, pElement->elementRef, &valueRef) == kIOReturnSuccess) {
-            value = (SInt32) IOHIDValueGetIntegerValue(valueRef);
-
+    IOReturn result = kIOReturnSuccess;
+    IOHIDEventStruct hidEvent;
+    hidEvent.value = 0;
+
+    if (NULL != pDevice && NULL != pElement && NULL != pDevice->interface) {
+        result =
+            (*(pDevice->interface))->getElementValue(pDevice->interface,
+                                                     pElement->cookie,
+                                                     &hidEvent);
+        if (kIOReturnSuccess == result) {
             /* record min and max for auto calibration */
-            if (value < pElement->minReport) {
-                pElement->minReport = value;
-            }
-            if (value > pElement->maxReport) {
-                pElement->maxReport = value;
-            }
+            if (hidEvent.value < pElement->minReport)
+                pElement->minReport = hidEvent.value;
+            if (hidEvent.value > pElement->maxReport)
+                pElement->maxReport = hidEvent.value;
         }
     }
 
-    return value;
+    /* auto user scale */
+    return hidEvent.value;
 }
 
 static SInt32
-GetHIDScaledCalibratedState(recDevice * pDevice, recElement * pElement, SInt32 min, SInt32 max)
+HIDScaledCalibratedValue(recDevice * pDevice, recElement * pElement,
+                         long min, long max)
 {
-    const float deviceScale = max - min;
-    const float readScale = pElement->maxReport - pElement->minReport;
-    const SInt32 value = GetHIDElementState(pDevice, pElement);
-    if (readScale == 0) {
+    float deviceScale = max - min;
+    float readScale = pElement->maxReport - pElement->minReport;
+    SInt32 value = HIDGetElementValue(pDevice, pElement);
+    if (readScale == 0)
         return value;           /* no scaling at all */
-    }
-    return ((value - pElement->minReport) * deviceScale / readScale) + min;
+    else
+        return ((value - pElement->minReport) * deviceScale / readScale) +
+            min;
 }
 
 
 static void
-JoystickDeviceWasRemovedCallback(void *ctx, IOReturn result, void *sender)
+HIDRemovalCallback(void *target, IOReturn result, void *refcon, void *sender)
 {
-    recDevice *device = (recDevice *) ctx;
+    recDevice *device = (recDevice *) refcon;
     device->removed = 1;
-#if SDL_HAPTIC_IOKIT
-    MacHaptic_MaybeRemoveDevice(device->ffservice);
-#endif
     s_bDeviceRemoved = SDL_TRUE;
 }
 
 
-static void AddHIDElement(const void *value, void *parameter);
+/* Called by the io port notifier on removal of this device
+ */
+void JoystickDeviceWasRemovedCallback( void * refcon, io_service_t service, natural_t messageType, void * messageArgument )
+{
+    if( messageType == kIOMessageServiceIsTerminated && refcon )
+    {
+        recDevice *device = (recDevice *) refcon;
+        device->removed = 1;
+        s_bDeviceRemoved = SDL_TRUE;
+    }
+}
+
+
+/* Create and open an interface to device, required prior to extracting values or building queues.
+ * Note: application now owns the device and must close and release it prior to exiting
+ */
 
-/* Call AddHIDElement() on all elements in an array of IOHIDElementRefs */
-static void
-AddHIDElements(CFArrayRef array, recDevice *pDevice)
+static IOReturn
+HIDCreateOpenDeviceInterface(io_object_t hidDevice, recDevice * pDevice)
 {
-    const CFRange range = { 0, CFArrayGetCount(array) };
-    CFArrayApplyFunction(array, range, AddHIDElement, pDevice);
+    IOReturn result = kIOReturnSuccess;
+    HRESULT plugInResult = S_OK;
+    SInt32 score = 0;
+    IOCFPlugInInterface **ppPlugInInterface = NULL;
+
+    if (NULL == pDevice->interface) {
+        result =
+            IOCreatePlugInInterfaceForService(hidDevice,
+                                              kIOHIDDeviceUserClientTypeID,
+                                              kIOCFPlugInInterfaceID,
+                                              &ppPlugInInterface, &score);
+        if (kIOReturnSuccess == result) {
+            /* Call a method of the intermediate plug-in to create the device interface */
+            plugInResult =
+                (*ppPlugInInterface)->QueryInterface(ppPlugInInterface,
+                                                     CFUUIDGetUUIDBytes
+                                                     (kIOHIDDeviceInterfaceID),
+                                                     (void *)
+                                                     &(pDevice->interface));
+            if (S_OK != plugInResult)
+                HIDReportErrorNum
+                    ("Couldn't query HID class device interface from plugInInterface",
+                     plugInResult);
+            (*ppPlugInInterface)->Release(ppPlugInInterface);
+        } else
+            HIDReportErrorNum
+                ("Failed to create **plugInInterface via IOCreatePlugInInterfaceForService.",
+                 result);
+    }
+    if (NULL != pDevice->interface) {
+        result = (*(pDevice->interface))->open(pDevice->interface, 0);
+        if (kIOReturnSuccess != result)
+            HIDReportErrorNum
+                ("Failed to open pDevice->interface via open.", result);
+        else
+        {
+            pDevice->portIterator = 0;
+
+            /* It's okay if this fails, we have another detection method below */
+            (*(pDevice->interface))->setRemovalCallback(pDevice->interface,
+                                                        HIDRemovalCallback,
+                                                        pDevice, pDevice);
+
+            /* now connect notification for new devices */
+            pDevice->notificationPort = IONotificationPortCreate(kIOMasterPortDefault);
+
+            CFRunLoopAddSource(CFRunLoopGetCurrent(),
+                               IONotificationPortGetRunLoopSource(pDevice->notificationPort),
+                               kCFRunLoopDefaultMode);
+
+            /* Register for notifications when a serial port is added to the system */
+            result = IOServiceAddInterestNotification(pDevice->notificationPort,
+                                                      hidDevice,
+                                                      kIOGeneralInterest,
+                                                      JoystickDeviceWasRemovedCallback,
+                                                      pDevice,
+                                                      &pDevice->portIterator);
+            if (kIOReturnSuccess != result) {
+                HIDReportErrorNum
+                    ("Failed to register for removal callback.", result);
+            }
+        }
+
+    }
+    return result;
 }
 
-static SDL_bool
-ElementAlreadyAdded(const IOHIDElementCookie cookie, const recElement *listitem) {
-    while (listitem) {
-        if (listitem->cookie == cookie) {
-            return SDL_TRUE;
+/* Closes and releases interface to device, should be done prior to exiting application
+ * Note: will have no affect if device or interface do not exist
+ * application will "own" the device if interface is not closed
+ * (device may have to be plug and re-plugged in different location to get it working again without a restart)
+ */
+
+static IOReturn
+HIDCloseReleaseInterface(recDevice * pDevice)
+{
+    IOReturn result = kIOReturnSuccess;
+
+    if ((NULL != pDevice) && (NULL != pDevice->interface)) {
+        /* close the interface */
+        result = (*(pDevice->interface))->close(pDevice->interface);
+        if (kIOReturnNotOpen == result) {
+            /* do nothing as device was not opened, thus can't be closed */
+        } else if (kIOReturnSuccess != result)
+            HIDReportErrorNum("Failed to close IOHIDDeviceInterface.",
+                              result);
+        /* release the interface */
+        result = (*(pDevice->interface))->Release(pDevice->interface);
+        if (kIOReturnSuccess != result)
+            HIDReportErrorNum("Failed to release IOHIDDeviceInterface.",
+                              result);
+        pDevice->interface = NULL;
+
+        if ( pDevice->portIterator )
+        {
+            IOObjectRelease( pDevice->portIterator );
+            pDevice->portIterator = 0;
         }
-        listitem = listitem->pNext;
     }
-    return SDL_FALSE;
+    return result;
 }
 
-/* See if we care about this HID element, and if so, note it in our recDevice. */
+/* extracts actual specific element information from each element CF dictionary entry */
+
 static void
-AddHIDElement(const void *value, void *parameter)
+HIDGetElementInfo(CFTypeRef refElement, recElement * pElement)
 {
-    recDevice *pDevice = (recDevice *) parameter;
-    IOHIDElementRef refElement = (IOHIDElementRef) value;
-    const CFTypeID elementTypeID = refElement ? CFGetTypeID(refElement) : 0;
-
-    if (refElement && (elementTypeID == IOHIDElementGetTypeID())) {
-        const IOHIDElementCookie cookie = IOHIDElementGetCookie(refElement);
-        const uint32_t usagePage = IOHIDElementGetUsagePage(refElement);
-        const uint32_t usage = IOHIDElementGetUsage(refElement);
-        recElement *element = NULL;
-        recElement **headElement = NULL;
+    long number;
+    CFTypeRef refType;
 
-        /* look at types of interest */
-        switch (IOHIDElementGetType(refElement)) {
-            case kIOHIDElementTypeInput_Misc:
-            case kIOHIDElementTypeInput_Button:
-            case kIOHIDElementTypeInput_Axis: {
-                switch (usagePage) {    /* only interested in kHIDPage_GenericDesktop and kHIDPage_Button */
-                    case kHIDPage_GenericDesktop:
-                        switch (usage) {
-                            case kHIDUsage_GD_X:
-                            case kHIDUsage_GD_Y:
-                            case kHIDUsage_GD_Z:
-                            case kHIDUsage_GD_Rx:
-                            case kHIDUsage_GD_Ry:
-                            case kHIDUsage_GD_Rz:
-                            case kHIDUsage_GD_Slider:
-                            case kHIDUsage_GD_Dial:
-                            case kHIDUsage_GD_Wheel:
-                                if (!ElementAlreadyAdded(cookie, pDevice->firstAxis)) {
-                                    element = (recElement *) SDL_calloc(1, sizeof (recElement));
-                                    if (element) {
-                                        pDevice->axes++;
-                                        headElement = &(pDevice->firstAxis);
-                                    }
-                                }
-                                break;
-
-                            case kHIDUsage_GD_Hatswitch:
-                                if (!ElementAlreadyAdded(cookie, pDevice->firstHat)) {
-                                    element = (recElement *) SDL_calloc(1, sizeof (recElement));
-                                    if (element) {
-                                        pDevice->hats++;
-                                        headElement = &(pDevice->firstHat);
-                                    }
-                                }
-                                break;
-                        }
-                        break;
+    refType = CFDictionaryGetValue(refElement, CFSTR(kIOHIDElementCookieKey));
+    if (refType && CFNumberGetValue(refType, kCFNumberLongType, &number))
+        pElement->cookie = (IOHIDElementCookie) number;
+    refType = CFDictionaryGetValue(refElement, CFSTR(kIOHIDElementMinKey));
+    if (refType && CFNumberGetValue(refType, kCFNumberLongType, &number))
+        pElement->minReport = pElement->min = number;
+    pElement->maxReport = pElement->min;
+    refType = CFDictionaryGetValue(refElement, CFSTR(kIOHIDElementMaxKey));
+    if (refType && CFNumberGetValue(refType, kCFNumberLongType, &number))
+        pElement->maxReport = pElement->max = number;
+/*
+    TODO: maybe should handle the following stuff somehow?
 
-                    case kHIDPage_Simulation:
-                        switch (usage) {
-                            case kHIDUsage_Sim_Rudder:
-                            case kHIDUsage_Sim_Throttle:
-                                if (!ElementAlreadyAdded(cookie, pDevice->firstAxis)) {
-                                    element = (recElement *) SDL_calloc(1, sizeof (recElement));
-                                    if (element) {
-                                        pDevice->axes++;
-                                        headElement = &(pDevice->firstAxis);
-                                    }
-                                }
-                                break;
+    refType = CFDictionaryGetValue (refElement, CFSTR(kIOHIDElementScaledMinKey));
+    if (refType && CFNumberGetValue (refType, kCFNumberLongType, &number))
+        pElement->scaledMin = number;
+    refType = CFDictionaryGetValue (refElement, CFSTR(kIOHIDElementScaledMaxKey));
+    if (refType && CFNumberGetValue (refType, kCFNumberLongType, &number))
+        pElement->scaledMax = number;
+    refType = CFDictionaryGetValue (refElement, CFSTR(kIOHIDElementSizeKey));
+    if (refType && CFNumberGetValue (refType, kCFNumberLongType, &number))
+        pElement->size = number;
+    refType = CFDictionaryGetValue (refElement, CFSTR(kIOHIDElementIsRelativeKey));
+    if (refType)
+        pElement->relative = CFBooleanGetValue (refType);
+    refType = CFDictionaryGetValue (refElement, CFSTR(kIOHIDElementIsWrappingKey));
+    if (refType)
+        pElement->wrapping = CFBooleanGetValue (refType);
+    refType = CFDictionaryGetValue (refElement, CFSTR(kIOHIDElementIsNonLinearKey));
+    if (refType)
+        pElement->nonLinear = CFBooleanGetValue (refType);
+    refType = CFDictionaryGetValue (refElement, CFSTR(kIOHIDElementHasPreferedStateKey));
+    if (refType)
+        pElement->preferredState = CFBooleanGetValue (refType);
+    refType = CFDictionaryGetValue (refElement, CFSTR(kIOHIDElementHasNullStateKey));
+    if (refType)
+        pElement->nullState = CFBooleanGetValue (refType);
+*/
+}
 
-                            default:
-                                break;
-                        }
-                        break;
+/* examines CF dictionary value in device element hierarchy to determine if it is element of interest or a collection of more elements
+ * if element of interest allocate storage, add to list and retrieve element specific info
+ * if collection then pass on to deconstruction collection into additional individual elements
+ */
 
-                    case kHIDPage_Button:
-                        if (!ElementAlreadyAdded(cookie, pDevice->firstButton)) {
-                            element = (recElement *) SDL_calloc(1, sizeof (recElement));
+static void
+HIDAddElement(CFTypeRef refElement, recDevice * pDevice)
+{
+    recElement *element = NULL;
+    recElement **headElement = NULL;
+    long elementType, usagePage, usage;
+    CFTypeRef refElementType =
+        CFDictionaryGetValue(refElement, CFSTR(kIOHIDElementTypeKey));
+    CFTypeRef refUsagePage =
+        CFDictionaryGetValue(refElement, CFSTR(kIOHIDElementUsagePageKey));
+    CFTypeRef refUsage =
+        CFDictionaryGetValue(refElement, CFSTR(kIOHIDElementUsageKey));
+
+
+    if ((refElementType)
+        &&
+        (CFNumberGetValue(refElementType, kCFNumberLongType, &elementType))) {
+        /* look at types of interest */
+        if ((elementType == kIOHIDElementTypeInput_Misc)
+            || (elementType == kIOHIDElementTypeInput_Button)
+            || (elementType == kIOHIDElementTypeInput_Axis)) {
+            if (refUsagePage
+                && CFNumberGetValue(refUsagePage, kCFNumberLongType,
+                                    &usagePage) && refUsage
+                && CFNumberGetValue(refUsage, kCFNumberLongType, &usage)) {
+                switch (usagePage) {    /* only interested in kHIDPage_GenericDesktop and kHIDPage_Button */
+                case kHIDPage_GenericDesktop:
+                    {
+                        switch (usage) {        /* look at usage to determine function */
+                        case kHIDUsage_GD_X:
+                        case kHIDUsage_GD_Y:
+                        case kHIDUsage_GD_Z:
+                        case kHIDUsage_GD_Rx:
+                        case kHIDUsage_GD_Ry:
+                        case kHIDUsage_GD_Rz:
+                        case kHIDUsage_GD_Slider:
+                        case kHIDUsage_GD_Dial:
+                        case kHIDUsage_GD_Wheel:
+                            element = (recElement *)
+                                NewPtrClear(sizeof(recElement));
                             if (element) {
-                                pDevice->buttons++;
-                                headElement = &(pDevice->firstButton);
+                                pDevice->axes++;
+                                headElement = &(pDevice->firstAxis);
                             }
+                            break;
+                        case kHIDUsage_GD_Hatswitch:
+                            element = (recElement *)
+                                NewPtrClear(sizeof(recElement));
+                            if (element) {
+                                pDevice->hats++;
+                                headElement = &(pDevice->firstHat);
+                            }
+                            break;
                         }
-                        break;
-
-                    default:
-                        break;
-                }
-            }
-            break;
+                    }
+                    break;
+                case kHIDPage_Simulation:
+                    switch (usage) {
+                        case kHIDUsage_Sim_Rudder:
+                        case kHIDUsage_Sim_Throttle:
+                            element = (recElement *)
+                                NewPtrClear(sizeof(recElement));
+                            if (element) {
+                                pDevice->axes++;
+                                headElement = &(pDevice->firstAxis);
+                            }
+                            break;
 
-            case kIOHIDElementTypeCollection: {
-                CFArrayRef array = IOHIDElementGetChildren(refElement);
-                if (array) {
-                    AddHIDElements(array, pDevice);
+                        default:
+                            break;
+                    }
+                    break;
+                case kHIDPage_Button:
+                    element = (recElement *)
+                        NewPtrClear(sizeof(recElement));
+                    if (element) {
+                        pDevice->buttons++;
+                        headElement = &(pDevice->firstButton);
+                    }
+                    break;
+                default:
+                    break;
                 }
             }
-            break;
+        } else if (kIOHIDElementTypeCollection == elementType)
+            HIDGetCollectionElements((CFMutableDictionaryRef) refElement,
+                                     pDevice);
+    }
 
-            default:
-                break;
+    if (element && headElement) {       /* add to list */
+        recElement *elementPrevious = NULL;
+        recElement *elementCurrent = *headElement;
+        while (elementCurrent && usage >= elementCurrent->usage) {
+            elementPrevious = elementCurrent;
+            elementCurrent = elementCurrent->pNext;
+        }
+        if (elementPrevious) {
+            elementPrevious->pNext = element;
+        } else {
+            *headElement = element;
         }
+        element->usagePage = usagePage;
+        element->usage = usage;
+        element->pNext = elementCurrent;
+        HIDGetElementInfo(refElement, element);
+        pDevice->elements++;
+    }
+}
 
-        if (element && headElement) {       /* add to list */
-            recElement *elementPrevious = NULL;
-            recElement *elementCurrent = *headElement;
-            while (elementCurrent && usage >= elementCurrent->usage) {
-                elementPrevious = elementCurrent;
-                elementCurrent = elementCurrent->pNext;
-            }
-            if (elementPrevious) {
-                elementPrevious->pNext = element;
-            } else {
-                *headElement = element;
-            }
+/* collects information from each array member in device element list (each array member = element) */
 
-            element->elementRef = refElement;
-            element->usagePage = usagePage;
-            element->usage = usage;
-            element->pNext = elementCurrent;
+static void
+HIDGetElementsCFArrayHandler(const void *value, void *parameter)
+{
+    if (CFGetTypeID(value) == CFDictionaryGetTypeID())
+        HIDAddElement((CFTypeRef) value, (recDevice *) parameter);
+}
 
-            element->minReport = element->min = (SInt32) IOHIDElementGetLogicalMin(refElement);
-            element->maxReport = element->max = (SInt32) IOHIDElementGetLogicalMax(refElement);
-            element->cookie = IOHIDElementGetCookie(refElement);
+/* handles retrieval of element information from arrays of elements in device IO registry information */
 
-            pDevice->elements++;
-        }
+static void
+HIDGetElements(CFTypeRef refElementCurrent, recDevice * pDevice)
+{
+    CFTypeID type = CFGetTypeID(refElementCurrent);
+    if (type == CFArrayGetTypeID()) {   /* if element is an array */
+        CFRange range = { 0, CFArrayGetCount(refElementCurrent) };
+        /* CountElementsCFArrayHandler called for each array member */
+        CFArrayApplyFunction(refElementCurrent, range,
+                             HIDGetElementsCFArrayHandler, pDevice);
     }
 }
 
-static SDL_bool
-GetDeviceInfo(IOHIDDeviceRef hidDevice, recDevice *pDevice)
+/* handles extracting element information from element collection CF types
+ * used from top level element decoding and hierarchy deconstruction to flatten device element list
+ */
+
+static void
+HIDGetCollectionElements(CFMutableDictionaryRef deviceProperties,
+                         recDevice * pDevice)
 {
-    Uint32 *guid32 = NULL;
-    CFTypeRef refCF = NULL;
-    CFArrayRef array = NULL;
+    CFTypeRef refElementTop =
+        CFDictionaryGetValue(deviceProperties, CFSTR(kIOHIDElementKey));
+    if (refElementTop)
+        HIDGetElements(refElementTop, pDevice);
+}
 
-    /* get usage page and usage */
-    refCF = IOHIDDeviceGetProperty(hidDevice, CFSTR(kIOHIDPrimaryUsagePageKey));
-    if (refCF) {
-        CFNumberGetValue(refCF, kCFNumberSInt32Type, &pDevice->usagePage);
-    }
-    if (pDevice->usagePage != kHIDPage_GenericDesktop) {
-        return SDL_FALSE; /* Filter device list to non-keyboard/mouse stuff */
-    }
+/* use top level element usage page and usage to discern device usage page and usage setting appropriate vlaues in device record */
 
-    refCF = IOHIDDeviceGetProperty(hidDevice, CFSTR(kIOHIDPrimaryUsageKey));
-    if (refCF) {
-        CFNumberGetValue(refCF, kCFNumberSInt32Type, &pDevice->usage);
-    }
+static void
+HIDTopLevelElementHandler(const void *value, void *parameter)
+{
+    CFTypeRef refCF = 0;
+    if (CFGetTypeID(value) != CFDictionaryGetTypeID())
+        return;
+    refCF = CFDictionaryGetValue(value, CFSTR(kIOHIDElementUsagePageKey));
+    if (!CFNumberGetValue
+        (refCF, kCFNumberLongType, &((recDevice *) parameter)->usagePage))
+        SDL_SetError("CFNumberGetValue error retrieving pDevice->usagePage.");
+    refCF = CFDictionaryGetValue(value, CFSTR(kIOHIDElementUsageKey));
+    if (!CFNumberGetValue
+        (refCF, kCFNumberLongType, &((recDevice *) parameter)->usage))
+        SDL_SetError("CFNumberGetValue error retrieving pDevice->usage.");
+}
 
-    if ((pDevice->usage != kHIDUsage_GD_Joystick &&
-         pDevice->usage != kHIDUsage_GD_GamePad &&
-         pDevice->usage != kHIDUsage_GD_MultiAxisController)) {
-        return SDL_FALSE; /* Filter device list to non-keyboard/mouse stuff */
-    }
+/* extracts device info from CF dictionary records in IO registry */
 
-    pDevice->deviceRef = hidDevice;
+static void
+HIDGetDeviceInfo(io_object_t hidDevice, CFMutableDictionaryRef hidProperties,
+                 recDevice * pDevice)
+{
+    CFMutableDictionaryRef usbProperties = 0;
+    io_registry_entry_t parent1, parent2;
 
-    /* get device name */
-    refCF = IOHIDDeviceGetProperty(hidDevice, CFSTR(kIOHIDProductKey));
-    if (!refCF) {
-        /* Maybe we can't get "AwesomeJoystick2000", but we can get "Logitech"? */
-        refCF = IOHIDDeviceGetProperty(hidDevice, CFSTR(kIOHIDManufacturerKey));
-    }
-    if ((!refCF) || (!CFStringGetCString(refCF, pDevice->product, sizeof (pDevice->product), kCFStringEncodingUTF8))) {
-        SDL_strlcpy(pDevice->product, "Unidentified joystick", sizeof (pDevice->product));
-    }
+    /* Mac OS X currently is not mirroring all USB properties to HID page so need to look at USB device page also
+     * get dictionary for USB properties: step up two levels and get CF dictionary for USB properties
+     */
+    if ((KERN_SUCCESS == IORegistryEntryGetParentEntry(hidDevice, kIOServicePlane, &parent1))
+        && (KERN_SUCCESS == IORegistryEntryGetParentEntry(parent1, kIOServicePlane, &parent2))
+        && (KERN_SUCCESS == IORegistryEntryCreateCFProperties(parent2, &usbProperties, kCFAllocatorDefault, kNilOptions))) {
+        if (usbProperties) {
+            CFTypeRef refCF = 0;
+            /* get device info
+             * try hid dictionary first, if fail then go to usb dictionary
+             */
 
-    refCF = IOHIDDeviceGetProperty(hidDevice, CFSTR(kIOHIDVendorIDKey));
-    if (refCF) {
-        CFNumberGetValue(refCF, kCFNumberSInt32Type, &pDevice->guid.data[0]);
-    }
+            /* get product name */
+            refCF = CFDictionaryGetValue(hidProperties, CFSTR(kIOHIDProductKey));
+            if (!refCF) {
+                refCF = CFDictionaryGetValue(usbProperties, CFSTR("USB Product Name"));
+            }
+            if (refCF) {
+                if (!CFStringGetCString(refCF, pDevice->product, 256, CFStringGetSystemEncoding())) {
+                    SDL_SetError("CFStringGetCString error retrieving pDevice->product.");
+                }
+            }
 
-    refCF = IOHIDDeviceGetProperty(hidDevice, CFSTR(kIOHIDProductIDKey));
-    if (refCF) {
-        CFNumberGetValue(refCF, kCFNumberSInt32Type, &pDevice->guid.data[8]);
-    }
+            /* get usage page and usage */
+            refCF = CFDictionaryGetValue(hidProperties, CFSTR(kIOHIDPrimaryUsagePageKey));
+            if (refCF) {
+                if (!CFNumberGetValue (refCF, kCFNumberLongType, &pDevice->usagePage)) {
+                    SDL_SetError("CFNumberGetValue error retrieving pDevice->usagePage.");
+                }
 
-    /* Check to make sure we have a vendor and product ID
-       If we don't, use the same algorithm as the Linux code for Bluetooth devices */
-    guid32 = (Uint32*)pDevice->guid.data;
-    if (!guid32[0] && !guid32[1]) {
-        /* If we don't have a vendor and product ID this is probably a Bluetooth device */
-        const Uint16 BUS_BLUETOOTH = 0x05;
-        Uint16 *guid16 = (Uint16 *)guid32;
-        *guid16++ = BUS_BLUETOOTH;
-        *guid16++ = 0;
-        SDL_strlcpy((char*)guid16, pDevice->product, sizeof(pDevice->guid.data) - 4);
-    }
+                refCF = CFDictionaryGetValue(hidProperties, CFSTR(kIOHIDPrimaryUsageKey));
+                if (refCF) {
+                    if (!CFNumberGetValue (refCF, kCFNumberLongType, &pDevice->usage)) {
+                        SDL_SetError("CFNumberGetValue error retrieving pDevice->usage.");
+                    }
+                }
+            }
 
-    array = IOHIDDeviceCopyMatchingElements(hidDevice, NULL, kIOHIDOptionsTypeNone);
-    if (array) {
-        AddHIDElements(array, pDevice);
-        CFRelease(array);
+            refCF = CFDictionaryGetValue(hidProperties, CFSTR(kIOHIDVendorIDKey));
+            if (refCF) {
+                if (!CFNumberGetValue(refCF, kCFNumberLongType, &pDevice->guid.data[0])) {
+                    SDL_SetError("CFNumberGetValue error retrieving pDevice->guid[0]");
+                }
+            }
+
+            refCF = CFDictionaryGetValue(hidProperties, CFSTR(kIOHIDProductIDKey));
+            if (refCF) {
+                if (!CFNumberGetValue(refCF, kCFNumberLongType, &pDevice->guid.data[8])) {
+                    SDL_SetError("CFNumberGetValue error retrieving pDevice->guid[8]");
+                }
+            }
+
+            /* Check to make sure we have a vendor and product ID
+               If we don't, use the same algorithm as the Linux code for Bluetooth devices */
+            {
+                Uint32 *guid32 = (Uint32*)pDevice->guid.data;
+                if (!guid32[0] && !guid32[1]) {
+                    const Uint16 BUS_BLUETOOTH = 0x05;
+                    Uint16 *guid16 = (Uint16 *)guid32;
+                    *guid16++ = BUS_BLUETOOTH;
+                    *guid16++ = 0;
+                    SDL_strlcpy((char*)guid16, pDevice->product, sizeof(pDevice->guid.data) - 4);
+                }
+            }
+
+            /* If we don't have a vendor and product ID this is probably a Bluetooth device */
+
+            if (NULL == refCF) {    /* get top level element HID usage page or usage */
+                /* use top level element instead */
+                CFTypeRef refCFTopElement = 0;
+                refCFTopElement = CFDictionaryGetValue(hidProperties, CFSTR(kIOHIDElementKey));
+                {
+                    /* refCFTopElement points to an array of element dictionaries */
+                    CFRange range = { 0, CFArrayGetCount(refCFTopElement) };
+                    CFArrayApplyFunction(refCFTopElement, range, HIDTopLevelElementHandler, pDevice);
+                }
+            }
+
+            CFRelease(usbProperties);
+        } else {
+            SDL_SetError("IORegistryEntryCreateCFProperties failed to create usbProperties.");
+        }
+
+        if (kIOReturnSuccess != IOObjectRelease(parent2)) {
+            SDL_SetError("IOObjectRelease error with parent2");
+        }
+        if (kIOReturnSuccess != IOObjectRelease(parent1)) {
+            SDL_SetError("IOObjectRelease error with parent1");
+        }
     }
+}
 
-    return SDL_TRUE;
+
+static recDevice *
+HIDBuildDevice(io_object_t hidDevice)
+{
+    recDevice *pDevice = (recDevice *) NewPtrClear(sizeof(recDevice));
+    if (pDevice) {
+        /* get dictionary for HID properties */
+        CFMutableDictionaryRef hidProperties = 0;
+        kern_return_t result =
+            IORegistryEntryCreateCFProperties(hidDevice, &hidProperties,
+                                              kCFAllocatorDefault,
+                                              kNilOptions);
+        if ((result == KERN_SUCCESS) && hidProperties) {
+            /* create device interface */
+            result = HIDCreateOpenDeviceInterface(hidDevice, pDevice);
+            if (kIOReturnSuccess == result) {
+                HIDGetDeviceInfo(hidDevice, hidProperties, pDevice);    /* hidDevice used to find parents in registry tree */
+                HIDGetCollectionElements(hidProperties, pDevice);
+            } else {
+                DisposePtr((Ptr) pDevice);
+                pDevice = NULL;
+            }
+            CFRelease(hidProperties);
+        } else {
+            DisposePtr((Ptr) pDevice);
+            pDevice = NULL;
+        }
+    }
+    return pDevice;
 }
 
+/* disposes of the element list associated with a device and the memory associated with the list
+ */
 
 static void
-JoystickDeviceWasAddedCallback(void *ctx, IOReturn res, void *sender, IOHIDDeviceRef ioHIDDeviceObject)
+HIDDisposeElementList(recElement ** elementList)
 {
-    if (res != kIOReturnSuccess) {
-        return;
+    recElement *pElement = *elementList;
+    while (pElement) {
+        recElement *pElementNext = pElement->pNext;
+        DisposePtr((Ptr) pElement);
+        pElement = pElementNext;
     }
+    *elementList = NULL;
+}
 
-    recDevice *device = (recDevice *) SDL_calloc(1, sizeof(recDevice));
+/* disposes of a single device, closing and releaseing interface, freeing memory fro device and elements, setting device pointer to NULL
+ * all your device no longer belong to us... (i.e., you do not 'own' the device anymore)
+ */
 
-    if (!device) {
-        SDL_OutOfMemory();
-        return;
-    }
+static recDevice *
+HIDDisposeDevice(recDevice ** ppDevice)
+{
+    kern_return_t result = KERN_SUCCESS;
+    recDevice *pDeviceNext = NULL;
+    if (*ppDevice) {
+        /* save next device prior to disposing of this device */
+        pDeviceNext = (*ppDevice)->pNext;
 
-    if (!GetDeviceInfo(ioHIDDeviceObject, device)) {
-        SDL_free(device);
-        return;   /* not a device we care about, probably. */
+        /* free posible io_service_t */
+        if ((*ppDevice)->ffservice) {
+            IOObjectRelease((*ppDevice)->ffservice);
+            (*ppDevice)->ffservice = 0;
+        }
+
+        /* free element lists */
+        HIDDisposeElementList(&(*ppDevice)->firstAxis);
+        HIDDisposeElementList(&(*ppDevice)->firstButton);
+        HIDDisposeElementList(&(*ppDevice)->firstHat);
+
+        result = HIDCloseReleaseInterface(*ppDevice);   /* function sanity checks interface value (now application does not own device) */
+        if (kIOReturnSuccess != result)
+            HIDReportErrorNum
+                ("HIDCloseReleaseInterface failed when trying to dipose device.",
+                 result);
+        DisposePtr((Ptr) * ppDevice);
+        *ppDevice = NULL;
     }
+    return pDeviceNext;
+}
+
+
+/* Given an io_object_t from OSX adds a joystick device to our list if appropriate
+ */
+int
+AddDeviceHelper( io_object_t ioHIDDeviceObject )
+{
+    recDevice *device;
 
-    /* Get notified when this device is disconnected. */
-    IOHIDDeviceRegisterRemovalCallback(ioHIDDeviceObject, JoystickDeviceWasRemovedCallback, device);
-    IOHIDDeviceScheduleWithRunLoop(ioHIDDeviceObject, CFRunLoopGetCurrent(), kCFRunLoopDefaultMode);
+    /* build a device record */
+    device = HIDBuildDevice(ioHIDDeviceObject);
+    if (!device)
+        return 0;
+
+    /* Filter device list to non-keyboard/mouse stuff */
+    if ((device->usagePage != kHIDPage_GenericDesktop) ||
+        ((device->usage != kHIDUsage_GD_Joystick &&
+          device->usage != kHIDUsage_GD_GamePad &&
+          device->usage != kHIDUsage_GD_MultiAxisController))) {
+
+        /* release memory for the device */
+        HIDDisposeDevice(&device);
+        DisposePtr((Ptr) device);
+        return 0;
+    }
 
     /* Allocate an instance ID for this device */
     device->instance_id = ++s_joystick_instance_id;
 
-    /* We have to do some storage of the io_service_t for SDL_HapticOpenFromJoystick */
-    if (IOHIDDeviceGetService != NULL) {  /* weak reference: available in 10.6 and later. */
-        const io_service_t ioservice = IOHIDDeviceGetService(ioHIDDeviceObject);
-        if ((ioservice) && (FFIsForceFeedback(ioservice) == FF_OK)) {
-            device->ffservice = ioservice;
-#if SDL_HAPTIC_IOKIT
-            MacHaptic_MaybeAddDevice(ioservice);
-#endif
-        }
+    /* We have to do some storage of the io_service_t for
+     * SDL_HapticOpenFromJoystick */
+    if (FFIsForceFeedback(ioHIDDeviceObject) == FF_OK) {
+        device->ffservice = ioHIDDeviceObject;
+    } else {
+        device->ffservice = 0;
     }
 
     device->send_open_event = 1;
@@ -413,93 +707,25 @@ JoystickDeviceWasAddedCallback(void *ctx
         }
         curdevice->pNext = device;
     }
-}
-
-static SDL_bool
-ConfigHIDManager(CFArrayRef matchingArray)
-{
-    CFRunLoopRef runloop = CFRunLoopGetCurrent();
-
-    /* Run in a custom RunLoop mode just while initializing,
-       so we can detect sticks without messing with everything else. */
-    CFStringRef tempRunLoopMode = CFSTR("SDLJoystickInit");
-
-    if (IOHIDManagerOpen(hidman, kIOHIDOptionsTypeNone) != kIOReturnSuccess) {
-        return SDL_FALSE;
-    }
-
-    IOHIDManagerRegisterDeviceMatchingCallback(hidman, JoystickDeviceWasAddedCallback, NULL);
-    IOHIDManagerScheduleWithRunLoop(hidman, runloop, tempRunLoopMode);
-    IOHIDManagerSetDeviceMatchingMultiple(hidman, matchingArray);
 
-    while (CFRunLoopRunInMode(tempRunLoopMode,0,TRUE)==kCFRunLoopRunHandledSource) {
-        /* no-op. Callback fires once per existing device. */
-    }
-
-    /* Put this in the normal RunLoop mode now, for future hotplug events. */
-    IOHIDManagerUnscheduleFromRunLoop(hidman, runloop, tempRunLoopMode);
-    IOHIDManagerScheduleWithRunLoop(hidman, runloop, kCFRunLoopDefaultMode);
-
-    return SDL_TRUE;  /* good to go. */
+    return 1;
 }
 
 
-static CFDictionaryRef
-CreateHIDDeviceMatchDictionary(const UInt32 page, const UInt32 usage, int *okay)
-{
-    CFDictionaryRef retval = NULL;
-    CFNumberRef pageNumRef = CFNumberCreate(kCFAllocatorDefault, kCFNumberIntType, &page);
-    CFNumberRef usageNumRef = CFNumberCreate(kCFAllocatorDefault, kCFNumberIntType, &usage);
-    const void *keys[2] = { (void *) CFSTR(kIOHIDDeviceUsagePageKey), (void *) CFSTR(kIOHIDDeviceUsageKey) };
-    const void *vals[2] = { (void *) pageNumRef, (void *) usageNumRef };
-
-    if (pageNumRef && usageNumRef) {
-        retval = CFDictionaryCreate(kCFAllocatorDefault, keys, vals, 2, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
-    }
-
-    if (pageNumRef) {
-        CFRelease(pageNumRef);
-    }
-    if (usageNumRef) {
-        CFRelease(usageNumRef);
-    }
-
-    if (!retval) {
-        *okay = 0;
-    }
-
-    return retval;
-}
-
-static SDL_bool
-CreateHIDManager(void)
+/* Called by our IO port notifier on the master port when a HID device is inserted, we iterate
+ *  and check for new joysticks
+ */
+void JoystickDeviceWasAddedCallback( void *refcon, io_iterator_t iterator )
 {
-    SDL_bool retval = SDL_FALSE;
-    int okay = 1;
-    const void *vals[] = {
-        (void *) CreateHIDDeviceMatchDictionary(kHIDPage_GenericDesktop, kHIDUsage_GD_Joystick, &okay),
-        (void *) CreateHIDDeviceMatchDictionary(kHIDPage_GenericDesktop, kHIDUsage_GD_GamePad, &okay),
-        (void *) CreateHIDDeviceMatchDictionary(kHIDPage_GenericDesktop, kHIDUsage_GD_MultiAxisController, &okay),
-    };
-    const size_t numElements = SDL_arraysize(vals);
-    CFArrayRef array = okay ? CFArrayCreate(kCFAllocatorDefault, vals, numElements, &kCFTypeArrayCallBacks) : NULL;
-    size_t i;
+    io_object_t ioHIDDeviceObject = 0;
 
-    for (i = 0; i < numElements; i++) {
-        if (vals[i]) {
-            CFRelease((CFTypeRef) vals[i]);
-        }
-    }
-
-    if (array) {
-        hidman = IOHIDManagerCreate(kCFAllocatorDefault, kIOHIDOptionsTypeNone);
-        if (hidman != NULL) {
-            retval = ConfigHIDManager(array);
+    while ( ( ioHIDDeviceObject = IOIteratorNext(iterator) ) )
+    {
+        if ( ioHIDDeviceObject )
+        {
+            AddDeviceHelper( ioHIDDeviceObject );
         }
-        CFRelease(array);
     }
-
-    return retval;
 }
 
 
@@ -511,13 +737,81 @@ CreateHIDManager(void)
 int
 SDL_SYS_JoystickInit(void)
 {
+    IOReturn result = kIOReturnSuccess;
+    mach_port_t masterPort = 0;
+    io_iterator_t hidObjectIterator = 0;
+    CFMutableDictionaryRef hidMatchDictionary = NULL;
+    io_object_t ioHIDDeviceObject = 0;
+    io_iterator_t portIterator = 0;
+
     if (gpDeviceList) {
         return SDL_SetError("Joystick: Device list already inited.");
     }
 
-    if (!CreateHIDManager()) {
-        return SDL_SetError("Joystick: Couldn't initialize HID Manager");
-    }
+    result = IOMasterPort(bootstrap_port, &masterPort);
+    if (kIOReturnSuccess != result) {
+        return SDL_SetError("Joystick: IOMasterPort error with bootstrap_port.");
+    }
+
+    /* Set up a matching dictionary to search I/O Registry by class name for all HID class devices. */
+    hidMatchDictionary = IOServiceMatching(kIOHIDDeviceKey);
+    if (hidMatchDictionary) {
+        /* Add key for device type (joystick, in this case) to refine the matching dictionary. */
+
+        /* NOTE: we now perform this filtering later
+           UInt32 usagePage = kHIDPage_GenericDesktop;
+           UInt32 usage = kHIDUsage_GD_Joystick;
+           CFNumberRef refUsage = NULL, refUsagePage = NULL;
+
+           refUsage = CFNumberCreate (kCFAllocatorDefault, kCFNumberIntType, &usage);
+           CFDictionarySetValue (hidMatchDictionary, CFSTR (kIOHIDPrimaryUsageKey), refUsage);
+           refUsagePage = CFNumberCreate (kCFAllocatorDefault, kCFNumberIntType, &usagePage);
+           CFDictionarySetValue (hidMatchDictionary, CFSTR (kIOHIDPrimaryUsagePageKey), refUsagePage);
+         */
+    } else {
+        return SDL_SetError
+            ("Joystick: Failed to get HID CFMutableDictionaryRef via IOServiceMatching.");
+    }
+
+    /* Now search I/O Registry for matching devices. */
+    result =
+        IOServiceGetMatchingServices(masterPort, hidMatchDictionary,
+                                     &hidObjectIterator);
+    /* Check for errors */
+    if (kIOReturnSuccess != result) {
+        return SDL_SetError("Joystick: Couldn't create a HID object iterator.");
+    }
+    if (!hidObjectIterator) {   /* there are no joysticks */
+        gpDeviceList = NULL;
+        return 0;
+    }
+    /* IOServiceGetMatchingServices consumes a reference to the dictionary, so we don't need to release the dictionary ref. */
+
+    /* build flat linked list of devices from device iterator */
+
+    gpDeviceList = NULL;
+
+    while ((ioHIDDeviceObject = IOIteratorNext(hidObjectIterator))) {
+        AddDeviceHelper( ioHIDDeviceObject );
+    }
+    result = IOObjectRelease(hidObjectIterator);        /* release the iterator */
+
+    /* now connect notification for new devices */
+    notificationPort = IONotificationPortCreate(masterPort);
+    hidMatchDictionary = IOServiceMatching(kIOHIDDeviceKey);
+
+    CFRunLoopAddSource(CFRunLoopGetCurrent(),
+                       IONotificationPortGetRunLoopSource(notificationPort),
+                       kCFRunLoopDefaultMode);
+
+    /* Register for notifications when a serial port is added to the system */
+    result = IOServiceAddMatchingNotification(notificationPort,
+                                                            kIOFirstMatchNotification,
+                                                            hidMatchDictionary,
+                                                            JoystickDeviceWasAddedCallback,
+                                                            NULL,
+                                                            &portIterator);
+    while (IOIteratorNext(portIterator)) {}; /* Run out the iterator or notifications won't start (you can also use it to iterate the available devices). */
 
     return SDL_SYS_NumJoysticks();
 }
@@ -529,10 +823,10 @@ SDL_SYS_NumJoysticks()
     recDevice *device = gpDeviceList;
     int nJoySticks = 0;
 
-    while (device) {
-        if (!device->removed) {
+    while ( device )
+    {
+        if ( !device->removed )
             nJoySticks++;
-        }
         device = device->pNext;
     }
 
@@ -544,16 +838,18 @@ SDL_SYS_NumJoysticks()
 void
 SDL_SYS_JoystickDetect()
 {
-    if (s_bDeviceAdded || s_bDeviceRemoved) {
+    if ( s_bDeviceAdded || s_bDeviceRemoved )
+    {
         recDevice *device = gpDeviceList;
         s_bDeviceAdded = SDL_FALSE;
         s_bDeviceRemoved = SDL_FALSE;
         int device_index = 0;
         /* send notifications */
-        while (device) {
-            if (device->send_open_event) {
+        while ( device )
+        {
+            if ( device->send_open_event )
+            {
                 device->send_open_event = 0;
-/* !!! FIXME: why isn't there an SDL_PrivateJoyDeviceAdded()? */
 #if !SDL_EVENTS_DISABLED
                 SDL_Event event;
                 event.type = SDL_JOYDEVICEADDED;
@@ -569,25 +865,43 @@ SDL_SYS_JoystickDetect()
 
             }
 
-            if (device->removed) {
-                const int instance_id = device->instance_id;
-                device = FreeDevice(device);
+            if ( device->removed )
+            {
+                recDevice *removeDevice = device;
+                if ( gpDeviceList == removeDevice )
+                {
+                    device = device->pNext;
+                    gpDeviceList = device;
+                }
+                else
+                {
+                    device = gpDeviceList;
+                    while ( device->pNext != removeDevice )
+                    {
+                        device = device->pNext;
+                    }
+
+                    device->pNext = removeDevice->pNext;
+                }
 
-/* !!! FIXME: why isn't there an SDL_PrivateJoyDeviceRemoved()? */
 #if !SDL_EVENTS_DISABLED
                 SDL_Event event;
                 event.type = SDL_JOYDEVICEREMOVED;
 
                 if (SDL_GetEventState(event.type) == SDL_ENABLE) {
-                    event.jdevice.which = instance_id;
+                    event.jdevice.which = removeDevice->instance_id;
                     if ((SDL_EventOK == NULL)
                         || (*SDL_EventOK) (SDL_EventOKParam, &event)) {
                         SDL_PushEvent(&event);
                     }
                 }
+
+                DisposePtr((Ptr) removeDevice);
 #endif /* !SDL_EVENTS_DISABLED */
 
-            } else {
+            }
+            else
+            {
                 device = device->pNext;
                 device_index++;
             }
@@ -607,9 +921,8 @@ SDL_SYS_JoystickNameForDeviceIndex(int d
 {
     recDevice *device = gpDeviceList;
 
-    while (device_index-- > 0) {
+    for (; device_index > 0; device_index--)
         device = device->pNext;
-    }
 
     return device->product;
 }
@@ -622,9 +935,8 @@ SDL_SYS_GetInstanceIdOfDeviceIndex(int d
     recDevice *device = gpDeviceList;
     int index;
 
-    for (index = device_index; index > 0; index--) {
+    for (index = device_index; index > 0; index--)
         device = device->pNext;
-    }
 
     return device->instance_id;
 }
@@ -640,9 +952,8 @@ SDL_SYS_JoystickOpen(SDL_Joystick * joys
     recDevice *device = gpDeviceList;
     int index;
 
-    for (index = device_index; index > 0; index--) {
+    for (index = device_index; index > 0; index--)
         device = device->pNext;
-    }
 
     joystick->instance_id = device->instance_id;
     joystick->hwdata = device;
@@ -663,10 +974,11 @@ SDL_SYS_JoystickAttached(SDL_Joystick * 
 {
     recDevice *device = gpDeviceList;
 
-    while (device) {
-        if (joystick->instance_id == device->instance_id) {
+    while ( device )
+    {
+        if ( joystick->instance_id == device->instance_id )
             return SDL_TRUE;
-        }
+
         device = device->pNext;
     }
 
@@ -686,24 +998,53 @@ SDL_SYS_JoystickUpdate(SDL_Joystick * jo
     SInt32 value, range;
     int i;
 
-    if (!device) {
+    if ( !device )
         return;
-    }
 
     if (device->removed) {      /* device was unplugged; ignore it. */
+        recDevice *devicelist = gpDeviceList;
         joystick->closed = 1;
         joystick->uncentered = 1;
+
+        if ( devicelist == device )
+        {
+            gpDeviceList = device->pNext;
+        }
+        else
+        {
+            while ( devicelist->pNext != device )
+            {
+                devicelist = devicelist->pNext;
+            }
+
+            devicelist->pNext = device->pNext;
+        }
+
+        DisposePtr((Ptr) device);
         joystick->hwdata = NULL;
+
+#if !SDL_EVENTS_DISABLED
+        SDL_Event event;
+        event.type = SDL_JOYDEVICEREMOVED;
+
+        if (SDL_GetEventState(event.type) == SDL_ENABLE) {
+            event.jdevice.which = joystick->instance_id;
+            if ((SDL_EventOK == NULL)
+                || (*SDL_EventOK) (SDL_EventOKParam, &event)) {
+                SDL_PushEvent(&event);
+            }
+        }
+#endif /* !SDL_EVENTS_DISABLED */
+
         return;
     }
 
     element = device->firstAxis;
     i = 0;
     while (element) {
-        value = GetHIDScaledCalibratedState(device, element, -32768, 32767);
-        if (value != joystick->axes[i]) {
+        value = HIDScaledCalibratedValue(device, element, -32768, 32767);
+        if (value != joystick->axes[i])
             SDL_PrivateJoystickAxis(joystick, i, value);
-        }
         element = element->pNext;
         ++i;
     }
@@ -711,13 +1052,11 @@ SDL_SYS_JoystickUpdate(SDL_Joystick * jo
     element = device->firstButton;
     i = 0;
     while (element) {
-        value = GetHIDElementState(device, element);
-        if (value > 1) {          /* handle pressure-sensitive buttons */
+        value = HIDGetElementValue(device, element);
+        if (value > 1)          /* handle pressure-sensitive buttons */
             value = 1;
-        }
-        if (value != joystick->buttons[i]) {
+        if (value != joystick->buttons[i])
             SDL_PrivateJoystickButton(joystick, i, value);
-        }
         element = element->pNext;
         ++i;
     }
@@ -728,12 +1067,11 @@ SDL_SYS_JoystickUpdate(SDL_Joystick * jo
         Uint8 pos = 0;
 
         range = (element->max - element->min + 1);
-        value = GetHIDElementState(device, element) - element->min;
-        if (range == 4) {         /* 4 position hatswitch - scale up value */
+        value = HIDGetElementValue(device, element) - element->min;
+        if (range == 4)         /* 4 position hatswitch - scale up value */
             value *= 2;
-        } else if (range != 8) {    /* Neither a 4 nor 8 positions - fall back to default position (centered) */
+        else if (range != 8)    /* Neither a 4 nor 8 positions - fall back to default position (centered) */
             value = -1;
-        }
         switch (value) {
         case 0:
             pos = SDL_HAT_UP;
@@ -767,14 +1105,13 @@ SDL_SYS_JoystickUpdate(SDL_Joystick * jo
             pos = SDL_HAT_CENTERED;
             break;
         }
-
-        if (pos != joystick->hats[i]) {
+        if (pos != joystick->hats[i])
             SDL_PrivateJoystickHat(joystick, i, pos);
-        }
-
         element = element->pNext;
         ++i;
     }
+
+    return;
 }
 
 /* Function to close a joystick after use */
@@ -788,17 +1125,14 @@ SDL_SYS_JoystickClose(SDL_Joystick * joy
 void
 SDL_SYS_JoystickQuit(void)
 {
-    while (FreeDevice(gpDeviceList)) {
-        /* spin */
-    }
+    while (NULL != gpDeviceList)
+        gpDeviceList = HIDDisposeDevice(&gpDeviceList);
 
-    if (hidman) {
-        IOHIDManagerClose(hidman, kIOHIDOptionsTypeNone);
-        CFRelease(hidman);
-        hidman = NULL;
+    if ( notificationPort )
+    {
+        IONotificationPortDestroy( notificationPort );
+        notificationPort = 0;
     }
-
-    s_bDeviceAdded = s_bDeviceRemoved = SDL_FALSE;
 }
 
 
@@ -807,9 +1141,8 @@ SDL_JoystickGUID SDL_SYS_JoystickGetDevi
     recDevice *device = gpDeviceList;
     int index;
 
-    for (index = device_index; index > 0; index--) {
+    for (index = device_index; index > 0; index--)
         device = device->pNext;
-    }
 
     return device->guid;
 }
