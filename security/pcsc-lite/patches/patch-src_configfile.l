$NetBSD: patch-src_configfile.l,v 1.1 2024/06/10 09:33:58 jperkin Exp $

SunOS has no dirent d_type.

--- src/configfile.l.orig	2024-06-10 09:29:24.980256046 +0000
+++ src/configfile.l
@@ -301,9 +301,11 @@ int DBGetReaderListDir(const char *reade
 			snprintf(filename, sizeof(filename), "%s/%s",
 				readerconf_dir, direntry->d_name);
 
+#ifndef __sun
 			/* skip non regular files */
 			if (direntry->d_type == DT_UNKNOWN)
 			{
+#endif
 				struct stat st;
 
 				if (lstat(filename, &st) != 0)
@@ -319,6 +321,7 @@ int DBGetReaderListDir(const char *reade
 						direntry->d_name);
 					continue;
 				}
+#ifndef __sun
 			}
 			else
 				if (direntry->d_type != DT_REG)
@@ -327,6 +330,7 @@ int DBGetReaderListDir(const char *reade
 						direntry->d_name);
 					continue;
 				}
+#endif
 
 			/* skip files starting with . like ., .., .svn, etc */
 			if ('.' == direntry->d_name[0])
