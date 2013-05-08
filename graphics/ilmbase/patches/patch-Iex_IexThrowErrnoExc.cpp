$NetBSD: patch-Iex_IexThrowErrnoExc.cpp,v 1.2 2013/05/08 17:48:33 adam Exp $

--- Iex/IexThrowErrnoExc.cpp.orig	Thu Jul 26 10:46:21 2012
+++ Iex/IexThrowErrnoExc.cpp
@@ -419,7 +419,7 @@ void throwErrnoExc (const std::string &t
 	    throw EnametoolongExc (tmp);
       #endif
 
-      #if defined (EOVERFLOW)
+      #if defined (EOVERFLOW) && EOVERFLOW != ERANGE
 	  case EOVERFLOW:
 	    throw EoverflowExc (tmp);
       #endif
