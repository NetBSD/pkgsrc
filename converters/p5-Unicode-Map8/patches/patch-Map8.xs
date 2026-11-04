$NetBSD: patch-Map8.xs,v 1.1 2026/11/04 06:29:04 wiz Exp $

Map8.xs: In function 'XS_Unicode__Map8_recode8':
Map8.xs:358:13: error: implicit declaration of function 'map8_recode8'; did you mean 'map8_recode_8'? [-Wimplicit-function-declaration]
  358 |             map8_recode8(m1, m2, str, res, len, &rlen);
      |             ^~~~~~~~~~~~
      |             map8_recode_8

--- Map8.xs.orig	2010-01-18 21:09:20.000000000 +0000
+++ Map8.xs
@@ -355,7 +355,7 @@ recode8(m1, m2, str)
 	    RETVAL = newSV(len + 1);
 	    SvPOK_on(RETVAL);
 	    res = SvPVX(RETVAL);
-	    map8_recode8(m1, m2, str, res, len, &rlen);
+	    map8_recode_8(m1, m2, str, res, len, &rlen);
 	    res[rlen] = '\0';
 	    SvCUR_set(RETVAL, rlen);
 	OUTPUT:
