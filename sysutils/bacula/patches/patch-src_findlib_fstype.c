$NetBSD: patch-src_findlib_fstype.c,v 1.1 2022/10/06 02:58:17 markd Exp $

--- src/findlib/fstype.c.orig	2022-09-23 04:23:23.100122245 +0000
+++ src/findlib/fstype.c
@@ -159,7 +159,7 @@ static uint64_t fstypeid(char *fname, FF
    struct statvfs st;
 
    if (statvfs(fname, &st) == 0) {
-      return st.f_type;
+      return (((uint64_t)st.f_fsidx.__fsid_val[0])<<32) | st.f_fsidx.__fsid_val[1];
    }
    return 0;
 }
