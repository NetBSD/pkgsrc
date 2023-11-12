$NetBSD: patch-src_joystick_darwin_SDL__sysjoystick__c.h,v 1.1 2023/11/12 21:28:04 nia Exp $

Restore support for Mac OS X 10.4, from "TigerPorts".

--- src/joystick/darwin/SDL_sysjoystick_c.h.orig	2014-03-16 02:31:41.000000000 +0000
+++ src/joystick/darwin/SDL_sysjoystick_c.h
@@ -1,6 +1,6 @@
 /*
   Simple DirectMedia Layer
-  Copyright (C) 1997-2014 Sam Lantinga <slouken@libsdl.org>
+  Copyright (C) 1997-2013 Sam Lantinga <slouken@libsdl.org>
 
   This software is provided 'as-is', without any express or implied
   warranty.  In no event will the authors be held liable for any damages
@@ -18,23 +18,38 @@
      misrepresented as being the original software.
   3. This notice may not be removed or altered from any source distribution.
 */
-#include "../../SDL_internal.h"
+#include "SDL_config.h"
 
 #ifndef SDL_JOYSTICK_IOKIT_H
 
+
 #include <IOKit/hid/IOHIDLib.h>
+#include <IOKit/hid/IOHIDKeys.h>
+#include <IOKit/IOKitLib.h>
+
 
 struct recElement
 {
-    IOHIDElementRef elementRef;
-    IOHIDElementCookie cookie;
-    uint32_t usagePage, usage;      /* HID usage */
-    SInt32 min;                   /* reported min value possible */
-    SInt32 max;                   /* reported max value possible */
+    IOHIDElementCookie cookie;  /* unique value which identifies element, will NOT change */
+    long usagePage, usage;      /* HID usage */
+    long min;                   /* reported min value possible */
+    long max;                   /* reported max value possible */
+#if 0
+    /* TODO: maybe should handle the following stuff somehow? */
+
+    long scaledMin;             /* reported scaled min value possible */
+    long scaledMax;             /* reported scaled max value possible */
+    long size;                  /* size in bits of data return from element */
+    Boolean relative;           /* are reports relative to last report (deltas) */
+    Boolean wrapping;           /* does element wrap around (one value higher than max is min) */
+    Boolean nonLinear;          /* are the values reported non-linear relative to element movement */
+    Boolean preferredState;     /* does element have a preferred state (such as a button) */
+    Boolean nullState;          /* does element have null state */
+#endif                          /* 0 */
 
     /* runtime variables used for auto-calibration */
-    SInt32 minReport;             /* min returned value */
-    SInt32 maxReport;             /* max returned value */
+    long minReport;             /* min returned value */
+    long maxReport;             /* max returned value */
 
     struct recElement *pNext;   /* next element in list */
 };
@@ -42,17 +57,19 @@ typedef struct recElement recElement;
 
 struct joystick_hwdata
 {
-    IOHIDDeviceRef deviceRef;   /* HIDManager device handle */
     io_service_t ffservice;     /* Interface for force feedback, 0 = no ff */
+    IOHIDDeviceInterface **interface;   /* interface to device, NULL = no interface */
+    IONotificationPortRef notificationPort; /* port to be notified on joystick removal */
+    io_iterator_t portIterator; /* iterator for removal callback */
 
     char product[256];          /* name of product */
-    uint32_t usage;                 /* usage page from IOUSBHID Parser.h which defines general usage */
-    uint32_t usagePage;             /* usage within above page from IOUSBHID Parser.h which defines specific usage */
+    long usage;                 /* usage page from IOUSBHID Parser.h which defines general usage */
+    long usagePage;             /* usage within above page from IOUSBHID Parser.h which defines specific usage */
 
-    int axes;                  /* number of axis (calculated, not reported by device) */
-    int buttons;               /* number of buttons (calculated, not reported by device) */
-    int hats;                  /* number of hat switches (calculated, not reported by device) */
-    int elements;              /* number of total elements (should be total of above) (calculated, not reported by device) */
+    long axes;                  /* number of axis (calculated, not reported by device) */
+    long buttons;               /* number of buttons (calculated, not reported by device) */
+    long hats;                  /* number of hat switches (calculated, not reported by device) */
+    long elements;              /* number of total elements (should be total of above) (calculated, not reported by device) */
 
     recElement *firstAxis;
     recElement *firstButton;
