$NetBSD: patch-modules_getent_getent-protocols.c,v 1.1 2017/08/31 12:53:50 fhajny Exp $

Different arg count on SunOS (at least).

--- modules/getent/getent-protocols.c.orig	2017-07-31 10:40:19.000000000 +0000
+++ modules/getent/getent-protocols.c
@@ -29,9 +29,17 @@ tf_getent_protocols(gchar *key, gchar *m
   char buf[4096];
 
   if ((is_num = parse_number(key, &d)) == TRUE)
+#if defined(__sun)
+    res = getprotobynumber_r((int) d, &proto, buf, sizeof(buf));
+#else
     getprotobynumber_r((int) d, &proto, buf, sizeof(buf), &res);
+#endif
   else
+#if defined(__sun)
+    res = getprotobyname_r(key, &proto, buf, sizeof(buf));
+#else
     getprotobyname_r(key, &proto, buf, sizeof(buf), &res);
+#endif
 
   if (res == NULL)
     return TRUE;
