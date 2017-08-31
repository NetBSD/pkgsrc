$NetBSD: patch-modules_getent_getent-services.c,v 1.1 2017/08/31 12:53:50 fhajny Exp $

Different arg count on SunOS (at least).

--- modules/getent/getent-services.c.orig	2017-07-31 10:40:19.000000000 +0000
+++ modules/getent/getent-services.c
@@ -29,9 +29,17 @@ tf_getent_services(gchar *key, gchar *me
   char buf[4096];
 
   if ((is_num = parse_number(key, &d)) == TRUE)
+#if defined(__sun)
+    res = getservbyport_r((int)ntohs(d), NULL, &serv, buf, sizeof(buf));
+#else
     getservbyport_r((int)ntohs(d), NULL, &serv, buf, sizeof(buf), &res);
+#endif
   else
+#if defined(__sun)
+    res = getservbyname_r(key, NULL, &serv, buf, sizeof(buf));
+#else
     getservbyname_r(key, NULL, &serv, buf, sizeof(buf), &res);
+#endif
 
   if (res == NULL)
     return TRUE;
