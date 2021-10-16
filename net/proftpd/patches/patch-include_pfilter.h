$NetBSD: patch-include_pfilter.h,v 1.3 2021/10/16 19:46:42 tm Exp $

Add packet filter

--- /dev/null	Fri Oct 15 10:32:05 2021
+++ include/pfilter.h	Fri Oct 15 10:32:05 2021
@@ -0,0 +1,3 @@
+
+void pfilter_notify(int);
+void pfilter_init(void);
