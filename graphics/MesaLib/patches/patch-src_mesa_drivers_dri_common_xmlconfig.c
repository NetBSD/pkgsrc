$NetBSD: patch-src_mesa_drivers_dri_common_xmlconfig.c,v 1.3 2016/02/23 11:16:55 jperkin Exp $

PR pkg/50202.
Provide compat strndup for older Darwin.

--- src/mesa/drivers/dri/common/xmlconfig.c.orig	2016-01-29 12:21:30.000000000 +0000
+++ src/mesa/drivers/dri/common/xmlconfig.c
@@ -50,12 +50,17 @@ extern char *program_invocation_name, *p
 #    define GET_PROGRAM_NAME() program_invocation_short_name
 #elif defined(__CYGWIN__)
 #    define GET_PROGRAM_NAME() program_invocation_short_name
+/*
 #elif defined(__FreeBSD__) && (__FreeBSD__ >= 2)
 #    include <osreldate.h>
 #    if (__FreeBSD_version >= 440000)
 #        include <stdlib.h>
 #        define GET_PROGRAM_NAME() getprogname()
 #    endif
+*/
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+#    include <stdlib.h>
+#    define GET_PROGRAM_NAME() getprogname()
 #elif defined(__NetBSD__) && defined(__NetBSD_Version__) && (__NetBSD_Version__ >= 106000100)
 #    include <stdlib.h>
 #    define GET_PROGRAM_NAME() getprogname()
@@ -111,6 +116,24 @@ static const char *__getProgramName () {
 #    endif
 #endif
 
+#if (defined(__APPLE__) && __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__-0 < 1070)
+static char *
+strndup(const char *str, size_t n)
+{
+  size_t len;
+  char *copy;
+
+  for (len = 0; len < n && str[len]; len++)
+    continue;
+
+  if ((copy = (char *)malloc(len + 1)) == NULL)
+    return (NULL);
+  memcpy(copy, str, len);
+  copy[len] = '\0';
+  return (copy);
+}
+#endif
+
 /** \brief Find an option in an option cache with the name as key */
 static uint32_t findOption (const driOptionCache *cache, const char *name) {
     uint32_t len = strlen (name);
