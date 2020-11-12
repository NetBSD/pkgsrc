$NetBSD: patch-source4_torture_libsmbclient_libsmbclient.c,v 1.1 2020/11/12 06:37:18 adam Exp $

Compatibility fix.

--- source4/torture/libsmbclient/libsmbclient.c.orig	2020-11-11 15:11:03.000000000 +0000
+++ source4/torture/libsmbclient/libsmbclient.c
@@ -1231,8 +1231,13 @@ static bool torture_libsmbclient_utimes(
 	ret = smbc_fstat(fhandle, &st);
 	torture_assert_int_not_equal(tctx, ret, -1, "smbc_fstat failed");
 
+#if defined(__APPLE__) || defined(__NetBSD__)
+	tbuf[0] = convert_timespec_to_timeval(st.st_atimespec);
+	tbuf[1] = convert_timespec_to_timeval(st.st_mtimespec);
+#else
 	tbuf[0] = convert_timespec_to_timeval(st.st_atim);
 	tbuf[1] = convert_timespec_to_timeval(st.st_mtim);
+#endif
 
 	tbuf[1] = timeval_add(&tbuf[1], 0, 100000); /* 100 msec */
 
@@ -1244,7 +1249,11 @@ static bool torture_libsmbclient_utimes(
 
 	torture_assert_int_equal(
 		tctx,
+#if defined(__APPLE__) || defined(__NetBSD__)
+		st.st_mtimespec.tv_nsec / 1000,
+#else
 		st.st_mtim.tv_nsec / 1000,
+#endif
 		tbuf[1].tv_usec,
 		"smbc_utimes did not update msec");
 
