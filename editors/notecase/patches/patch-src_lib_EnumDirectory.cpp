$NetBSD: patch-src_lib_EnumDirectory.cpp,v 1.1 2011/12/08 20:41:47 marino Exp $

--- src/lib/EnumDirectory.cpp.orig	2011-12-08 16:39:12.229180000 +0000
+++ src/lib/EnumDirectory.cpp
@@ -113,10 +113,16 @@ int EnumDirectory(const char *szPath, FN
 int EnumDirectory(const char *szPath, FN_ENUMDIR func, void *userdata, int nFilter)
 {
 	struct	dirent *resp;
-	char	buf[sizeof(struct dirent)+MAXNAMLEN];	//dirent struct buffer
 
+#if defined(__DragonFly__)
+	char	buf[sizeof(struct dirent)+256];
+	char	tmp[256];
+	char	dir[256];
+#else
+	char	buf[sizeof(struct dirent)+MAXNAMLEN];	//dirent struct buffer
 	char	tmp[MAXNAMLEN];	//buffer for full path of found file
 	char	dir[MAXNAMLEN]; //buffer for dir name of found file
+#endif
 	struct	stat statbuf;	
 	int		r;
 	
