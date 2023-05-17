$NetBSD: patch-src_TimePrint.cxx,v 1.1 2023/05/17 10:45:41 wiz Exp $

Fix build with fmtlib 10. Remove after 0.23.13.

--- src/TimePrint.cxx.orig	2023-01-17 17:54:47.000000000 +0000
+++ src/TimePrint.cxx
@@ -36,5 +36,5 @@ time_print(Response &r, const char *name
 		return;
 	}
 
-	r.Fmt(FMT_STRING("{}: {}\n"), name, s);
+	r.Fmt(FMT_STRING("{}: {}\n"), std::string(name), std::string(s));
 }
