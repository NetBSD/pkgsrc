$NetBSD: patch-common_Endianness.h,v 1.1 2014/08/26 10:44:15 wiz Exp $

Avoid bswap32 re-definition on NetBSD.

In file included from ./soundlib/plugins/PlugInterface.h:25:0,
                 from ./soundlib/Sndfile.h:47,
                 from libopenmpt/libopenmpt_impl.cpp:28:
./soundlib/plugins/../../common/Endianness.h:26:0: warning: "bswap32" redefined [enabled by default]
 #define bswap32 __builtin_bswap32
 ^

http://bugs.openmpt.org/view.php?id=579

--- common/Endianness.h.orig	2014-06-10 16:27:31.000000000 +0000
+++ common/Endianness.h
@@ -23,8 +23,10 @@ OPENMPT_NAMESPACE_BEGIN
 
 #if MPT_COMPILER_GCC
 #if MPT_GCC_AT_LEAST(4,3,0)
+#ifndef bswap32
 #define bswap32 __builtin_bswap32
 #endif
+#endif
 #elif MPT_COMPILER_MSVC
 #include <intrin.h>
 #define bswap16 _byteswap_ushort
