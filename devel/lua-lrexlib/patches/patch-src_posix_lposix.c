$NetBSD: patch-src_posix_lposix.c,v 1.1 2018/10/26 12:03:49 jperkin Exp $

Avoid unsupported REG_* flags on SunOS.

--- src/posix/lposix.c.orig	2013-01-08 11:41:58.000000000 +0000
+++ src/posix/lposix.c
@@ -234,7 +234,7 @@ static flag_pair posix_error_flags[] = {
   { "ERANGE",   REG_ERANGE },
   { "ESPACE",   REG_ESPACE },
   { "BADRPT",   REG_BADRPT },
-#ifdef REX_POSIX_EXT
+#if defined(REX_POSIX_EXT) && !defined(__sun)
   { "EMPTY",    REG_EMPTY },
   { "ASSERT",   REG_ASSERT },
   { "INVARG",   REG_INVARG },
