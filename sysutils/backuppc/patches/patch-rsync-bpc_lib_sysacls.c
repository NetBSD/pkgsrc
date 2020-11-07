$NetBSD: patch-rsync-bpc_lib_sysacls.c,v 1.3 2020/11/07 14:53:31 tnn Exp $

No ACL support on NetBSD and probably other platforms

--- ../rsync-bpc-3.1.2.2/lib/sysacls.c.orig	2018-12-01 22:25:23.000000000 +0000
+++ ../rsync-bpc-3.1.2.2/lib/sysacls.c
@@ -24,6 +24,8 @@
 #include "rsync.h"
 #include "sysacls.h"
 
+#ifdef SUPPORT_ACLS
+
 #ifdef DEBUG
 #undef DEBUG
 #endif
@@ -2790,3 +2792,5 @@ int no_acl_syscall_error(int err)
 	}
 	return 0;
 }
+
+#endif /* SUPPORT_ACLS */
