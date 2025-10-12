$NetBSD: patch-metamail_metamail.h,v 1.1 2025/10/12 00:57:39 mrg Exp $

Add a place for shared function headers.


--- /dev/null	2025-10-11 17:19:02.891264465 -0700
+++ metamail/metamail.h	2025-10-11 17:20:20.705329874 -0700
@@ -0,0 +1,16 @@
+/*
+ * Header for metamail stuff.  Public domain.
+ * --mrg 2025-10-11
+ */
+
+int lc2strncmp();
+int lc2strcmp();
+int ExceptionalNewline();
+void from64();
+void fromqp();
+void fromuue();
+void to64();
+void toqp();
+int PendingBoundary();
+int DoesNeedPortableNewlines();
+char *getmyname();
