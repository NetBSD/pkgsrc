$NetBSD: patch-mono_metadata_icall.c,v 1.1 2015/05/21 14:38:08 kefren Exp $

strtod hack until someone has time to debug mono_strtod

--- mono/metadata/icall.c.orig	2015-05-21 14:20:36.000000000 +0300
+++ mono/metadata/icall.c	2015-05-21 14:22:00.000000000 +0300
@@ -127,10 +127,15 @@ mono_double_ParseImpl (char *ptr, double
 	*result = 0.0;
 
 	if (*ptr){
+#if defined(__NetBSD__)
+		/* XXX WIP: mono_strtod spins 100% CPU on NetBSD */
+		*result = strtod(ptr, &endptr);
+#else
 		/* mono_strtod () is not thread-safe */
 		mono_mutex_lock (&mono_strtod_mutex);
 		*result = mono_strtod (ptr, &endptr);
 		mono_mutex_unlock (&mono_strtod_mutex);
+#endif
 	}
 
 	if (!*ptr || (endptr && *endptr))
