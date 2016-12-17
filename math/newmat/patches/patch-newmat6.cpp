$NetBSD: patch-newmat6.cpp,v 1.1 2016/12/17 23:31:35 joerg Exp $

Check pointer for NULLness, not whether it is "positive".

--- newmat6.cpp.orig	2016-12-10 15:33:44.625762128 +0000
+++ newmat6.cpp
@@ -428,7 +428,7 @@ void CroutMatrix::operator=(const CroutM
 {
    if (&gm == this) { REPORT tag_val = -1; return; }
    REPORT
-   if (indx > 0) { delete [] indx; indx = 0; }
+   if (indx) { delete [] indx; indx = 0; }
    ((CroutMatrix&)gm).get_aux(*this);
    Eq(gm);
 }
