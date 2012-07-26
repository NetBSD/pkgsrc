$NetBSD: patch-Iex_IexThrowErrnoExc.cpp,v 1.1 2012/07/26 10:58:47 bsiegert Exp $

--- Iex/IexThrowErrnoExc.cpp.orig	Thu Jul 26 10:46:21 2012
+++ Iex/IexThrowErrnoExc.cpp
@@ -410,7 +410,7 @@ void throwErrnoExc (const std::string &t
 	    throw EnametoolongExc (tmp);
       #endif
 
-      #if defined (EOVERFLOW)
+      #if defined (EOVERFLOW) && EOVERFLOW != ERANGE
 	  case EOVERFLOW:
 	    throw EoverflowExc (tmp);
       #endif
