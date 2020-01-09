$NetBSD: patch-mcs_class_corlib_Test_Mono_MonoNativePlatformType.cs,v 1.3 2020/01/09 15:26:36 ryoon Exp $

Add netbsd support
https://github.com/mono/mono/pull/15938

--- mcs/class/corlib/Test/Mono/MonoNativePlatformType.cs.orig	2019-12-10 07:50:31.000000000 +0000
+++ mcs/class/corlib/Test/Mono/MonoNativePlatformType.cs
@@ -39,6 +39,7 @@ namespace Mono
 		MONO_NATIVE_PLATFORM_TYPE_ANDROID	= 5,
 		MONO_NATIVE_PLATFORM_TYPE_FREEBSD	= 6,
 		MONO_NATIVE_PLATFORM_TYPE_HAIKU		= 7,
+		MONO_NATIVE_PLATFORM_TYPE_NETBSD	= 8,
 
 		MONO_NATIVE_PLATFORM_TYPE_IPHONE	= 0x100,
 		MONO_NATIVE_PLATFORM_TYPE_TV		= 0x200,
