$NetBSD: patch-contrib_uuid-ossp_uuid-ossp.c,v 1.1 2016/02/25 21:37:35 tnn Exp $

Explicitly define HAVE_UUID_H and HAVE_UUID_OSSP.

--- contrib/uuid-ossp/uuid-ossp.c.orig	2015-01-14 20:54:38.000000000 +0000
+++ contrib/uuid-ossp/uuid-ossp.c
@@ -26,6 +26,7 @@
  */
 #define uuid_hash bsd_uuid_hash
 
+#define HAVE_UUID_H
 #ifdef HAVE_UUID_H
 #include <uuid.h>
 #endif
@@ -42,6 +43,7 @@
  * Some BSD variants offer md5 and sha1 implementations but Linux does not,
  * so we use a copy of the ones from pgcrypto.  Not needed with OSSP, though.
  */
+#define HAVE_UUID_OSSP
 #ifndef HAVE_UUID_OSSP
 #include "md5.h"
 #include "sha1.h"
