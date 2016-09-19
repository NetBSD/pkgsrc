$NetBSD: patch-tests_mini-server-name.c,v 1.1 2016/09/19 15:32:47 wiz Exp $

Only test DNS UTF-8 support when building with libidn.
https://gitlab.com/gnutls/gnutls/commit/480c9f572c511230699a1d35d3053515058584c2

--- tests/mini-server-name.c.orig	2016-09-03 08:29:22.000000000 +0000
+++ tests/mini-server-name.c
@@ -341,8 +341,10 @@ void doit(void)
 	start(0, "", 0, "", 0);
 	start(0, "test.example.com", strlen("test.example.com"), "test.example.com", strlen("test.example.com"));
 	start(0, "longtest.example.com.", strlen("longtest.example.com"), "longtest.example.com.", strlen("longtest.example.com"));
+#ifdef HAVE_LIBIDN
 	/* test invalid UTF8 */
 	start(1, "invalid\xff.example.com.", sizeof("invalid\xff.example.com")-1, NULL, 0);
+#endif
 	/* test embedded NULL */
 	start(1, "invalid\x00.example.com.", sizeof("invalid\x00.example.com")-1, NULL, 0);
 }
