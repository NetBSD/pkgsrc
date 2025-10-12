$NetBSD: patch-src_command.c,v 1.1 2025/10/12 02:57:35 mrg Exp $

Include <ctype.h> for everyone, not just windows.
Include "msg.h".
Fix the call to _dvdplay_trace().

--- src/command.c.orig	2025-10-11 19:47:34.491155332 -0700
+++ src/command.c	2025-10-11 19:42:13.513727472 -0700
@@ -38,9 +38,7 @@
 #endif
 #include <assert.h>
 
-#ifdef WIN32
-#   include <ctype.h>
-#endif
+#include <ctype.h>
 
 #include "common.h"
 
@@ -52,6 +50,7 @@
 #include "tools.h"
 #include "command.h"
 #include "vmg.h"
+#include "msg.h"
 
 /* freebsd compatibility */
 #ifndef PRIu8
@@ -739,7 +738,7 @@ static dvdbool_t _SystemSet( dvdplay_ptr
         {
             if( _Bits( &dvdplay->cmd, 2 + i, 0, 1 ) )
             {
-                _dvdplay_trace(  "%s = ", system_reg_table[i] );
+                _dvdplay_trace( dvdplay, "%s = ", system_reg_table[i] );
 
                 i_data = _RegOrData_2( dvdplay,
                             _Bits( &dvdplay->cmd, 0, 3, 1 ), 2 + i );
