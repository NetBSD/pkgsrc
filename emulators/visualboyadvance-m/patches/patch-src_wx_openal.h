$NetBSD: patch-src_wx_openal.h,v 1.1 2024/04/29 09:18:40 nia Exp $

Fix build against openal-soft.

--- src/wx/openal.h.orig	2024-04-29 08:29:39.129850245 +0000
+++ src/wx/openal.h
@@ -1,14 +1,3 @@
-// on win32 and mac, pointer typedefs only happen with AL_NO_PROTOTYPES
-// on mac, ALC_NO_PROTOTYPES as well
-
-#define AL_NO_PROTOTYPES 1
-
-// on mac, alc pointer typedefs ony happen for ALC if ALC_NO_PROTOTYPES
-// unfortunately, there is a bug in the system headers (use of ALCvoid when
-// void should be used; shame on Apple for introducing this error, and shame
-// on Creative for making a typedef to void in the first place)
-//#define ALC_NO_PROTOTYPES 1
-
 #include <al.h>
 #include <alc.h>
 
