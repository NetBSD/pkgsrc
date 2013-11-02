$NetBSD: patch-src_File.cc,v 1.1 2013/11/02 18:27:39 dholland Exp $

Don't call closedir() on NULL. From PR 48357.

--- src/File.cc~	2007-09-03 12:12:21.000000000 +0000
+++ src/File.cc
@@ -490,8 +490,8 @@ FXint isEmptyDir(const FXString director
 			ret=1;
 		else
 			ret=0;
+		closedir(dir);
 	}
-	closedir(dir);
 	return ret;
 }
 		
