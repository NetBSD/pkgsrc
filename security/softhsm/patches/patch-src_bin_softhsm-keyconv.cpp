$NetBSD: patch-src_bin_softhsm-keyconv.cpp,v 1.1 2014/11/18 13:40:57 he Exp $

Adapt fix for SA59651, similar to CVE-2014-3209, from
https://github.com/bellgrim/SoftHSMv2/commit/492447cd4a2be449e99fb9ad2519ea3277aaad28
Ensure created pkcs8 file is not group- or world-readable.

--- src/bin/softhsm-keyconv.cpp.orig	2014-05-28 05:59:14.000000000 +0000
+++ src/bin/softhsm-keyconv.cpp
@@ -48,6 +48,10 @@
 #include <iostream>
 #include <fstream>
 #include <stdint.h>
+#include <errno.h>
+#include <sys/types.h>
+#include <sys/stat.h>
+#include <fcntl.h>
 
 void usage() {
   printf("Converting between BIND .private-key format and PKCS#8 key file format.\n");
@@ -391,6 +395,15 @@ int to_pkcs8(char *in_path, char *out_pa
     return 1;
   }
 
+  // Create and set file permissions if the file does not exist.
+  int fd = open(out_path, O_CREAT, S_IRUSR | S_IWUSR);
+  if (fd == -1) {
+    fprintf(stderr, "ERROR: Could not open the output file: %s (errno %i)\n",
+	    out_path, errno);
+    return 1;
+  }
+  ::close(fd);
+
   // Save the the key to the disk
   switch(algorithm) {
     case DNS_KEYALG_ERROR:
