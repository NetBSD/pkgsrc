$NetBSD: patch-mono_native_mono-native-platform.h,v 1.3 2020/01/09 15:26:36 ryoon Exp $

Add netbsd support
https://github.com/mono/mono/pull/15938

--- mono/native/mono-native-platform.h.orig	2019-12-10 07:50:32.000000000 +0000
+++ mono/native/mono-native-platform.h
@@ -13,6 +13,7 @@ typedef enum {
 	MONO_NATIVE_PLATFORM_TYPE_ANDROID	= 5,
 	MONO_NATIVE_PLATFORM_TYPE_FREEBSD	= 6,
 	MONO_NATIVE_PLATFORM_TYPE_HAIKU		= 7,
+	MONO_NATIVE_PLATFORM_TYPE_NETBSD	= 8,
 
 	MONO_NATIVE_PLATFORM_TYPE_IPHONE	= 0x100,
 	MONO_NATIVE_PLATFORM_TYPE_TV		= 0x200,
