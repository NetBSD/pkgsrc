$NetBSD: patch-src_dar__suite_crit__action__cmd__line.cpp,v 1.1 2013/06/26 15:49:31 joerg Exp $

--- src/dar_suite/crit_action_cmd_line.cpp.orig	2013-06-20 19:17:02.000000000 +0000
+++ src/dar_suite/crit_action_cmd_line.cpp
@@ -413,7 +413,7 @@ static const criterium * criterium_creat
 		case 'r':
 		    try
 		    {
-			deci tmp = sub_arg;
+			libdar::deci tmp = sub_arg;
 			date = tmp.computer();
 		    }
 		    catch(Edeci & e)
