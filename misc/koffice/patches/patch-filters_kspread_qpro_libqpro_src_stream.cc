$NetBSD: patch-filters_kspread_qpro_libqpro_src_stream.cc,v 1.1 2013/05/25 23:44:47 joerg Exp $

--- filters/kspread/qpro/libqpro/src/stream.cc.orig	2007-05-30 21:39:27.000000000 +0000
+++ filters/kspread/qpro/libqpro/src/stream.cc
@@ -114,13 +114,13 @@ QpIStream::operator void* ()
    if( cIn == 0 )
       return 0;
    else
-      return *cIn;
+      return cIn->fail() ? NULL : cIn;
 }
 
 int
 QpIStream::operator !()
 {
-   return ( cIn ? !*cIn : -1 );
+   return cIn == 0 || cIn->fail();
 }
 
 
