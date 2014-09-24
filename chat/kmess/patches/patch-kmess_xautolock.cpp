$NetBSD: patch-kmess_xautolock.cpp,v 1.1 2014/09/24 16:28:40 jperkin Exp $

Avoid "error: call of overloaded <func> is ambiguous".

--- kmess/xautolock.cpp.orig	2005-07-13 14:47:59.000000000 +0000
+++ kmess/xautolock.cpp
@@ -78,7 +78,7 @@ void XAutoLock::checkIdle()
 
   now = time( 0 );
 
-  if ( abs( lastCheck_ - now ) > 120 )
+  if ( abs( (int)lastCheck_ - (int)now ) > 120 )
   {
     /*
       Whoah, two minutes since we were last called?  Something strange is happenning...
