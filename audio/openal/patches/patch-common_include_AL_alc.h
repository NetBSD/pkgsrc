$NetBSD: patch-common_include_AL_alc.h,v 1.1 2011/08/22 13:36:31 wiz Exp $

gcc-4.5 doesn't like this.

--- common/include/AL/alc.h.orig	2006-02-11 09:36:55.000000000 +0000
+++ common/include/AL/alc.h
@@ -187,7 +187,7 @@ ALC_API void            ALC_APIENTRY alc
 
 ALC_API void            ALC_APIENTRY alcDestroyContext( ALCcontext *context );
 
-ALC_API ALCcontext *    ALC_APIENTRY alcGetCurrentContext( ALCvoid );
+ALC_API ALCcontext *    ALC_APIENTRY alcGetCurrentContext( void );
 
 ALC_API ALCdevice*      ALC_APIENTRY alcGetContextsDevice( ALCcontext *context );
 
@@ -238,7 +238,7 @@ ALC_API void            ALC_APIENTRY alc
 
 ALC_API void            ALC_APIENTRY alcCaptureStop( ALCdevice *device );
 
-ALC_API void            ALC_APIENTRY alcCaptureSamples( ALCdevice *device, ALCvoid *buffer, ALCsizei samples );
+ALC_API void            ALC_APIENTRY alcCaptureSamples( ALCdevice *device, void *buffer, ALCsizei samples );
 
 /*
  * Pointer-to-function types, useful for dynamically getting ALC entry points.
@@ -248,7 +248,7 @@ typedef ALCboolean     (ALC_APIENTRY *LP
 typedef void           (ALC_APIENTRY *LPALCPROCESSCONTEXT)( ALCcontext *context );
 typedef void           (ALC_APIENTRY *LPALCSUSPENDCONTEXT)( ALCcontext *context );
 typedef void           (ALC_APIENTRY *LPALCDESTROYCONTEXT)( ALCcontext *context );
-typedef ALCcontext *   (ALC_APIENTRY *LPALCGETCURRENTCONTEXT)( ALCvoid );
+typedef ALCcontext *   (ALC_APIENTRY *LPALCGETCURRENTCONTEXT)( void );
 typedef ALCdevice *    (ALC_APIENTRY *LPALCGETCONTEXTSDEVICE)( ALCcontext *context );
 typedef ALCdevice *    (ALC_APIENTRY *LPALCOPENDEVICE)( const ALCchar *devicename );
 typedef ALCboolean     (ALC_APIENTRY *LPALCCLOSEDEVICE)( ALCdevice *device );
@@ -262,7 +262,7 @@ typedef ALCdevice *    (ALC_APIENTRY *LP
 typedef ALCboolean     (ALC_APIENTRY *LPALCCAPTURECLOSEDEVICE)( ALCdevice *device );
 typedef void           (ALC_APIENTRY *LPALCCAPTURESTART)( ALCdevice *device );
 typedef void           (ALC_APIENTRY *LPALCCAPTURESTOP)( ALCdevice *device );
-typedef void           (ALC_APIENTRY *LPALCCAPTURESAMPLES)( ALCdevice *device, ALCvoid *buffer, ALCsizei samples );
+typedef void           (ALC_APIENTRY *LPALCCAPTURESAMPLES)( ALCdevice *device, void *buffer, ALCsizei samples );
 
 #if defined(TARGET_OS_MAC) && TARGET_OS_MAC
  #pragma export off
