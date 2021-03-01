$NetBSD: patch-OgreMain_include_OgreBitwise.h,v 1.1 2021/03/01 12:12:14 nia Exp $

More than FreeBSD has these defines in libc headers...

--- OgreMain/include/OgreBitwise.h.orig	2021-02-13 01:52:07.000000000 +0000
+++ OgreMain/include/OgreBitwise.h
@@ -30,7 +30,7 @@ THE SOFTWARE.
 
 #include "OgrePrerequisites.h"
 
-#ifdef __FreeBSD__
+#ifdef bswap16
 #undef bswap16
 #undef bswap32
 #undef bswap64
