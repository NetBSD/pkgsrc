NetBSD$

OpenSSH 10 support: https://gitlab.com/libssh/libssh-mirror/-/commit/d758990d392fbbca623afd22186164cb4ccf1743.patch

--- src/misc.c.orig	2024-08-29 13:01:56.000000000 +0000
+++ src/misc.c
@@ -1397,6 +1397,7 @@ int ssh_analyze_banner(ssh_session sessi
         char *tmp = NULL;
         unsigned long int major = 0UL;
         unsigned long int minor = 0UL;
+        int off = 0;
 
         /*
          * The banner is typical:
@@ -1416,8 +1417,9 @@ int ssh_analyze_banner(ssh_session sessi
             }
 
             errno = 0;
-            minor = strtoul(openssh + 10, &tmp, 10);
-            if ((tmp == (openssh + 10)) ||
+            off = major >= 10 ? 11 : 10;
+            minor = strtoul(openssh + off, &tmp, 10);
+            if ((tmp == (openssh + off)) ||
                 ((errno == ERANGE) && (major == ULONG_MAX)) ||
                 ((errno != 0) && (major == 0)) ||
                 (minor > 100)) {
