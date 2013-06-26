$NetBSD: patch-src_dar__suite_command__line.cpp,v 1.1 2013/06/26 15:49:31 joerg Exp $

--- src/dar_suite/command_line.cpp.orig	2013-06-20 19:13:40.000000000 +0000
+++ src/dar_suite/command_line.cpp
@@ -758,7 +758,7 @@ static bool get_args_recursive(recursive
 			try
 			{
 				// trying to read a simple integer
-			    deci tmp = string(optarg);
+			    libdar::deci tmp = string(optarg);
 			    p.fixed_date = tmp.computer();
 			}
 			catch(Edeci & e)
@@ -845,7 +845,7 @@ static bool get_args_recursive(recursive
             case 'p':
 		if(optarg != NULL)
 		{
-		    deci conv = string(optarg);
+		    libdar::deci conv = string(optarg);
 		    p.pause = conv.computer();
 		}
 		else
@@ -1222,7 +1222,7 @@ static bool get_args_recursive(recursive
                 {
                     try
                     {
-                        p.hourshift = deci(string(optarg)).computer();
+                        p.hourshift = libdar::deci(string(optarg)).computer();
                     }
                     catch(Edeci & e)
                     {
