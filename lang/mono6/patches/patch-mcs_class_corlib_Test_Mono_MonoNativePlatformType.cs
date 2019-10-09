$NetBSD: patch-mcs_class_corlib_Test_Mono_MonoNativePlatformType.cs,v 1.2 2019/10/09 22:46:04 maya Exp $

Add netbsd support
https://github.com/mono/mono/pull/15938

--- mcs/class/corlib/Test/Mono/MonoNativePlatformType.cs.orig	2019-09-19 07:46:06.000000000 +0000
+++ mcs/class/corlib/Test/Mono/MonoNativePlatformType.cs
@@ -38,6 +38,7 @@ namespace Mono
 		MONO_NATIVE_PLATFORM_TYPE_AIX		= 4,
 		MONO_NATIVE_PLATFORM_TYPE_ANDROID	= 5,
 		MONO_NATIVE_PLATFORM_TYPE_FREEBSD	= 6,
+		MONO_NATIVE_PLATFORM_TYPE_NETBSD	= 8,
 
 		MONO_NATIVE_PLATFORM_TYPE_IPHONE	= 0x100,
 		MONO_NATIVE_PLATFORM_TYPE_TV		= 0x200,
