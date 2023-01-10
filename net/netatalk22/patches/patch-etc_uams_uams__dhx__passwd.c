$NetBSD: patch-etc_uams_uams__dhx__passwd.c,v 1.3 2023/01/10 22:07:33 hauke Exp $

Don't include headers that are not shipped

--- etc/uams/uams_dhx_passwd.c.orig	2022-07-12 04:08:24.000000000 +0000
+++ etc/uams/uams_dhx_passwd.c
@@ -37,7 +37,6 @@
 #include <openssl/bn.h>
 #include <openssl/dh.h>
 #include <openssl/cast.h>
-#include "openssl_compat.h"
 #else /* OPENSSL_DHX */
 #include <bn.h>
 #include <dh.h>
