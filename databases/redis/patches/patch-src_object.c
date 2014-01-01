$NetBSD: patch-src_object.c,v 1.1 2014/01/01 16:08:24 bsiegert Exp $

--- src/object.c.orig	Wed Aug 28 09:36:00 2013
+++ src/object.c
@@ -450,7 +450,11 @@ int getLongDoubleFromObject(robj *o, lon
         redisAssertWithInfo(NULL,o,o->type == REDIS_STRING);
         if (o->encoding == REDIS_ENCODING_RAW) {
             errno = 0;
+#ifdef __MirBSD__
+            value = (long double)strtod(o->ptr, &eptr);
+#else
             value = strtold(o->ptr, &eptr);
+#endif
             if (isspace(((char*)o->ptr)[0]) || eptr[0] != '\0' ||
                 errno == ERANGE || isnan(value))
                 return REDIS_ERR;
