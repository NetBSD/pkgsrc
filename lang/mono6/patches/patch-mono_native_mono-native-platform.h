$NetBSD: patch-mono_native_mono-native-platform.h,v 1.1 2019/08/25 16:37:01 maya Exp $

Add netbsd support
https://github.com/mono/mono/pull/15938

--- mono/native/mono-native-platform.h.orig	2019-07-18 07:46:08.000000000 +0000
+++ mono/native/mono-native-platform.h
@@ -11,6 +11,8 @@ typedef enum {
 	MONO_NATIVE_PLATFORM_TYPE_LINUX		= 3,
 	MONO_NATIVE_PLATFORM_TYPE_AIX		= 4,
 	MONO_NATIVE_PLATFORM_TYPE_ANDROID	= 5,
+	MONO_NATIVE_PLATFORM_TYPE_FREEBSD	= 6,
+	MONO_NATIVE_PLATFORM_TYPE_NETBSD	= 8,
 
 	MONO_NATIVE_PLATFORM_TYPE_IPHONE	= 0x100,
 	MONO_NATIVE_PLATFORM_TYPE_TV		= 0x200,
