$NetBSD: patch-src_diff.h,v 1.1 2014/08/13 22:39:10 joerg Exp $

--- src/diff.h.orig	2014-08-13 20:34:57.000000000 +0000
+++ src/diff.h
@@ -118,7 +118,7 @@ struct Diff3Line
       pFineAB=0; pFineBC=0; pFineCA=0;
    }
 
-   bool operator==( const Diff3Line& d3l )
+   bool operator==( const Diff3Line& d3l ) const
    {
       return lineA == d3l.lineA  &&  lineB == d3l.lineB  &&  lineC == d3l.lineC  
          && bAEqB == d3l.bAEqB  && bAEqC == d3l.bAEqC  && bBEqC == d3l.bBEqC;
