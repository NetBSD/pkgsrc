$NetBSD: patch-src_dar__suite_dar__xform.cpp,v 1.1 2013/06/26 15:49:31 joerg Exp $

--- src/dar_suite/dar_xform.cpp.orig	2013-06-20 19:18:01.000000000 +0000
+++ src/dar_suite/dar_xform.cpp
@@ -314,7 +314,7 @@ static bool command_line(user_interactio
             case 'p':
 		if(optarg != NULL)
 		{
-		    deci conv = string(optarg);
+		    libdar::deci conv = string(optarg);
 		    pause = conv.computer();
 		}
 		else
