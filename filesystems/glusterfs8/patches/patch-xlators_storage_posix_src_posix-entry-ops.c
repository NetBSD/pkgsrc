$NetBSD: patch-xlators_storage_posix_src_posix-entry-ops.c,v 1.1 2023/03/12 11:55:59 js Exp $

Properly screen the .attribute directory where NetBSD UFS1 stores 
extended attributes.
From upstream https://review.gluster.org/24702

--- xlators/storage/posix/src/posix-entry-ops.c.orig	2020-07-08 09:00:29.350013944 +0200
+++ xlators/storage/posix/src/posix-entry-ops.c	2020-07-08 09:04:15.087789405 +0200
@@ -197,8 +197,22 @@
         op_ret = -1;
         goto out;
     }
 
+#ifdef __NetBSD__
+    /* Same for NetBSD's .attribute directory */
+    if (__is_root_gfid(loc->pargfid) && loc->name &&
+        (strcmp(loc->name, ".attribute") == 0)) {
+        gf_msg(this->name, GF_LOG_WARNING, EPERM, P_MSG_LOOKUP_NOT_PERMITTED,
+               "Lookup issued on .attribute,"
+               " which is not permitted");
+        op_errno = EPERM;
+        op_ret = -1;
+        goto out;
+    }
+#endif /* __NetBSD__ */  
+
+
     op_ret = dict_get_int32_sizen(xdata, GF_GFIDLESS_LOOKUP, &gfidless);
     op_ret = -1;
     if (gf_uuid_is_null(loc->pargfid) || (loc->name == NULL)) {
         /* nameless lookup */
@@ -649,8 +663,21 @@
         op_ret = -1;
         goto out;
     }
 
+#ifdef __NetBSD__
+    /* Same for NetBSD's .attribute directory */
+    if (__is_root_gfid(loc->pargfid) &&
+        (strcmp(loc->name, ".attribute") == 0)) {
+        gf_msg(this->name, GF_LOG_WARNING, EPERM, P_MSG_MKDIR_NOT_PERMITTED,
+               "mkdir issued on .attribute, which"
+               "is not permitted");
+        op_errno = EPERM;
+        op_ret = -1;
+        goto out;
+    }
+#endif
+
     priv = this->private;
     VALIDATE_OR_GOTO(priv, out);
     GFID_NULL_CHECK_AND_GOTO(frame, this, loc, xdata, op_ret, op_errno,
                              uuid_req, out);
@@ -1415,8 +1442,21 @@
         op_ret = -1;
         goto out;
     }
 
+#ifdef __NetBSD__
+    /* Same for NetBSD's .attribute directory */
+    if (__is_root_gfid(loc->pargfid) &&
+        (strcmp(loc->name, ".attribute") == 0)) {
+        gf_msg(this->name, GF_LOG_WARNING, EPERM, P_MSG_RMDIR_NOT_PERMITTED,
+               "rmdir issued on .attribute, which"
+               "is not permitted");
+        op_errno = EPERM;
+        op_ret = -1;
+        goto out;
+    }
+#endif
+
     priv = this->private;
 
     MAKE_ENTRY_HANDLE(real_path, par_path, this, loc, &stbuf);
     if (!real_path || !par_path) {
