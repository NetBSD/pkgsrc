$NetBSD: patch-src_Config.cpp,v 1.1 2016/03/01 20:16:17 joerg Exp $

Inverse of new[] is delete[].

--- src/Config.cpp.orig	2016-03-01 12:34:43.478519419 +0000
+++ src/Config.cpp
@@ -125,7 +125,7 @@ for (cur_node = a_node; cur_node; cur_no
 				includes.push_back(*filter);
 				}
 			else excludes.push_back(*filter);
-			delete buffer;
+			delete[] buffer;
 			}		
     		}
 		
