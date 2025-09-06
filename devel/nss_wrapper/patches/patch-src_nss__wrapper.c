$NetBSD: patch-src_nss__wrapper.c,v 1.1 2025/09/06 18:27:52 riastradh Exp $

Add NetBSD support.  See https://wiki.NetBSD.org/symbol_versions for
reference about symbol versioning.

Avoid ctype(3) abuse.

--- src/nss_wrapper.c.orig	2024-07-05 08:31:02.000000000 +0000
+++ src/nss_wrapper.c
@@ -87,6 +87,31 @@
 
 #include <dlfcn.h>
 
+#ifdef __NetBSD__
+static void *
+wrap_dlsym(void *handle, const char *symbol)
+{
+	static const struct {
+		const char *public, *internal;
+	} renames[] = {
+		{ "getpwent", "__getpwent50" },
+		{ "getpwent_r", "__getpwent_r50" },
+		{ "getpwnam", "__getpwnam50" },
+		{ "getpwnam_r", "__getpwnam_r50" },
+		{ "getpwuid", "__getpwuid50" },
+		{ "getpwuid_r", "__getpwuid_r50" },
+	};
+	size_t i;
+
+	for (i = 0; i < sizeof(renames)/sizeof(renames[0]); i++) {
+		if (strcmp(symbol, renames[i].public) == 0)
+			return dlsym(handle, renames[i].internal);
+	}
+	return dlsym(handle, symbol);
+}
+#define	dlsym		wrap_dlsym
+#endif
+
 #if defined(HAVE_NSS_H)
 /* Linux and BSD */
 #include <nss.h>
@@ -104,6 +129,16 @@ typedef nss_status_t NSS_STATUS;
 # define NSS_STATUS_NOTFOUND    NSS_NOTFOUND
 # define NSS_STATUS_UNAVAIL     NSS_UNAVAIL
 # define NSS_STATUS_TRYAGAIN    NSS_TRYAGAIN
+#elif defined(HAVE_NSSWITCH_H)
+/* NetBSD */
+#include <nsswitch.h>
+
+typedef int NSS_STATUS;
+
+# define NSS_STATUS_SUCCESS     NS_SUCCESS
+# define NSS_STATUS_NOTFOUND    NS_NOTFOUND
+# define NSS_STATUS_UNAVAIL     NS_UNAVAIL
+# define NSS_STATUS_TRYAGAIN    NS_TRYAGAIN
 #else
 # error "No nsswitch support detected"
 #endif
@@ -1394,7 +1429,7 @@ static inline void str_tolower(char *dst
 	register char *dst_tmp = dst;
 
 	while (*src_tmp != '\0') {
-		*dst_tmp = tolower(*src_tmp);
+		*dst_tmp = tolower((unsigned char)*src_tmp);
 		++src_tmp;
 		++dst_tmp;
 	}
@@ -5317,6 +5352,7 @@ int initgroups(const char *user, gid_t g
 		return libc_initgroups(user, group);
 	}
 
+
 	return nwrap_initgroups(user, group);
 }
 
@@ -5612,7 +5648,7 @@ static int nwrap_getgrouplist(const char
 			      gid_t **groupsp,
 			      long int limit)
 {
-	enum nss_status status = NSS_STATUS_UNAVAIL;
+	NSS_STATUS status = NSS_STATUS_UNAVAIL;
 	/* Start is one, because we have the first group as parameter.  */
 	long int start = 1;
 	size_t i;
@@ -5960,6 +5996,10 @@ struct hostent *gethostbyaddr(const void
 	return nwrap_gethostbyaddr(addr, len, type);
 }
 
+#ifndef AI_V4MAPPED
+#define	AI_V4MAPPED	0
+#endif
+
 static const struct addrinfo default_hints =
 {
 	.ai_flags = AI_ADDRCONFIG|AI_V4MAPPED,
