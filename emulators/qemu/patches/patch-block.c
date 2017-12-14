$NetBSD: patch-block.c,v 1.1 2017/12/14 08:01:11 adam Exp $

Remove block driver whitelisting logic; reasons being:
- PkgSrc does not configure Qemu to use whitelisting
- sometimes CONFIG...WHITELIST macros contain ["", NULL],
  and bdrv_is_whitelisted() fails.

--- block.c.orig	2017-12-04 12:07:17.000000000 +0000
+++ block.c
@@ -369,31 +369,7 @@ BlockDriver *bdrv_find_format(const char
 
 static int bdrv_is_whitelisted(BlockDriver *drv, bool read_only)
 {
-    static const char *whitelist_rw[] = {
-        CONFIG_BDRV_RW_WHITELIST
-    };
-    static const char *whitelist_ro[] = {
-        CONFIG_BDRV_RO_WHITELIST
-    };
-    const char **p;
-
-    if (!whitelist_rw[0] && !whitelist_ro[0]) {
-        return 1;               /* no whitelist, anything goes */
-    }
-
-    for (p = whitelist_rw; *p; p++) {
-        if (!strcmp(drv->format_name, *p)) {
-            return 1;
-        }
-    }
-    if (read_only) {
-        for (p = whitelist_ro; *p; p++) {
-            if (!strcmp(drv->format_name, *p)) {
-                return 1;
-            }
-        }
-    }
-    return 0;
+    return 1;
 }
 
 bool bdrv_uses_whitelist(void)
