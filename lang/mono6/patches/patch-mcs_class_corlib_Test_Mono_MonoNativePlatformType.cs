$NetBSD: patch-mcs_class_corlib_Test_Mono_MonoNativePlatformType.cs,v 1.1 2019/08/25 16:37:01 maya Exp $

Add netbsd support
https://github.com/mono/mono/pull/15938

--- mcs/class/corlib/Test/Mono/MonoNativePlatformType.cs.orig	2019-07-18 07:46:07.000000000 +0000
+++ mcs/class/corlib/Test/Mono/MonoNativePlatformType.cs
@@ -36,6 +36,7 @@ namespace Mono
 		MONO_NATIVE_PLATFORM_TYPE_IOS		= 2,
 		MONO_NATIVE_PLATFORM_TYPE_LINUX		= 3,
 		MONO_NATIVE_PLATFORM_TYPE_AIX		= 4,
+		MONO_NATIVE_PLATFORM_TYPE_NETBSD	= 8,
 
 		MONO_NATIVE_PLATFORM_TYPE_IPHONE	= 0x100,
 		MONO_NATIVE_PLATFORM_TYPE_TV		= 0x200,
