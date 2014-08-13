$NetBSD: patch-server.h,v 1.1 2014/08/13 22:35:29 joerg Exp $

--- server.h.orig	2014-08-13 13:24:50.000000000 +0000
+++ server.h
@@ -152,22 +152,22 @@ class LATServer
 	  return (!(type == INACTIVE || type == DISABLED_PTY));
 	}
 
-	bool operator==(int _fd)
+	bool operator==(int _fd) const
 	{
 	    return (type != INACTIVE && fd == _fd);
 	}
 
-	bool operator==(const fdinfo &fdi)
+	bool operator==(const fdinfo &fdi) const
 	{
 	    return (fd == fdi.fd);
 	}
 
-	bool operator!=(const fdinfo &fdi)
+	bool operator!=(const fdinfo &fdi) const
 	{
 	    return (fd != fdi.fd);
 	}
 
-	bool operator!=(int _fd)
+	bool operator!=(int _fd) const
 	{
 	    return (type == INACTIVE || fd != _fd);
 	}
