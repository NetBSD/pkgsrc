$NetBSD: patch-config.cpp,v 1.1 2017/02/08 00:04:53 joerg Exp $

Fix format string to match argument.

--- config.cpp.orig	2017-01-08 19:37:40.160134851 +0000
+++ config.cpp
@@ -228,7 +228,7 @@ void file_config::read_config( string& f
         port = ( strlen( v ) ? v : DEFAULT_PORT );
       }
       else {
-        fprintf( stderr," Unknown key/value pair (%s/%s) on line %u\n", key.c_str(), v, linenum );
+        fprintf( stderr," Unknown key/value pair (%s/%s) on line %zu\n", key.c_str(), v, linenum );
       }
     }
     /*
