$NetBSD: patch-gcr_test-secure-memory.c,v 1.1 2020/11/17 12:25:16 nia Exp $

Skip test on platforms without RLIMIT_MEMLOCK (illumos).

--- gcr/test-secure-memory.c.orig	2020-09-28 05:33:20.870133200 +0000
+++ gcr/test-secure-memory.c
@@ -66,6 +66,7 @@ get_rlimit_memlock (void)
 		return 0;
 	}
 
+#ifdef RLIMIT_MEMLOCK
 	if (getrlimit (RLIMIT_MEMLOCK, &memlock) != 0)
 		g_error ("getrlimit() failed: %s", strerror (errno));
 
@@ -83,6 +84,10 @@ get_rlimit_memlock (void)
 	}
 
 	return memlock.rlim_cur;
+#else
+	g_test_skip ("platform lacks RLIMIT_MEMLOCK");
+	return 0;
+#endif
 }
 
 static void
