$NetBSD: patch-contrib_uuid-ossp_uuid-ossp.c,v 1.2 2017/02/11 10:18:52 adam Exp $

Explicitly define HAVE_UUID_H and HAVE_UUID_OSSP.

--- contrib/uuid-ossp/uuid-ossp.c.orig	2017-02-06 21:49:02.000000000 +0000
+++ contrib/uuid-ossp/uuid-ossp.c
@@ -30,6 +30,7 @@
  */
 #define uuid_hash bsd_uuid_hash
 
+#define HAVE_UUID_H
 #if defined(HAVE_UUID_H)
 #include <uuid.h>
 #elif defined(HAVE_OSSP_UUID_H)
@@ -46,6 +47,7 @@
  * Some BSD variants offer md5 and sha1 implementations but Linux does not,
  * so we use a copy of the ones from pgcrypto.  Not needed with OSSP, though.
  */
+#define HAVE_UUID_OSSP
 #ifndef HAVE_UUID_OSSP
 #include "md5.h"
 #include "sha1.h"
