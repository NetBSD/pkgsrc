$NetBSD: patch-include_ntfs-3g_types.h,v 1.2 2015/11/10 17:45:22 adam Exp $

Fix TRUE and FALSE definitions.

--- include/ntfs-3g/types.h.orig	2013-01-13 06:46:35.000000000 +0000
+++ include/ntfs-3g/types.h
@@ -68,6 +68,16 @@ typedef sle64 leVCN;
 typedef s64 LCN;
 typedef sle64 leLCN;
 
+/* XXX For some reason, including sys/mount.h on osx defines TRUE and FALSE
+ * so clear them here.
+ */
+#ifdef FALSE
+#undef FALSE
+#endif
+#ifdef TRUE
+#undef TRUE
+#endif
+
 /*
  * The NTFS journal $LogFile uses log sequence numbers which are signed 64-bit
  * values.  We define our own type LSN, to allow for type checking and better
