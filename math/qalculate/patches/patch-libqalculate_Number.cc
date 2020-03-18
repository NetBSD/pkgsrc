$NetBSD: patch-libqalculate_Number.cc,v 1.1 2020/03/18 17:57:31 joerg Exp $

Ensure that the third argument is the base type of the string,
so that insert is unambigous from the iterator variation.

--- libqalculate/Number.cc.orig	2020-03-15 17:27:02.908147193 +0000
+++ libqalculate/Number.cc
@@ -7723,7 +7723,7 @@ string Number::print(const PrintOptions 
 			nra *= 26;
 			nra = nr - nra;
 			nr = nri;
-			str.insert(0, 1, ('A' + nra.intValue() - 1));
+			str.insert(0, 1, char('A' + nra.intValue() - 1));
 		} while(!nr.isZero());
 		if(ips.minus) {
 			*ips.minus = neg;
