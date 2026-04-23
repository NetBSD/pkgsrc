$NetBSD: patch-dialects_n+obsd_dproc.c,v 1.1 2026/04/23 21:23:11 kim Exp $

Do not include _STABLE, _RC, etc. suffixes in version comparison.

--- dialects/n+obsd/dproc.c.orig	2005-05-11 15:54:00.000000000 +0300
+++ dialects/n+obsd/dproc.c	2025-07-18 11:02:20.123676193 +0300
@@ -81,6 +81,19 @@
 		Pn, strerror(errno));
 	    Exit(1);
 	}
+
+#ifdef __NetBSD__
+/*
+ * Major release version indicates ABI compatibility.
+ */
+	{
+	    char *vp;
+	    vp = strchr(v, '_');
+	    if (vp != NULL)
+		*vp = '\0';
+	}
+#endif
+
 /*
  * Warn if the actual and expected releases don't match.
  */
