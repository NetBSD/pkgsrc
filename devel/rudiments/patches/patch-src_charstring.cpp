$NetBSD: patch-src_charstring.cpp,v 1.1 2013/09/14 09:14:08 fhajny Exp $

Remove ambiguity (fixes build with GCC>=4.7).
--- src/charstring.cpp.orig	2013-08-01 02:43:39.000000000 +0000
+++ src/charstring.cpp
@@ -309,7 +309,7 @@ char *charstring::convertAmount(int64_t
 	}
 	negative[1]='\0';
 	char	*amountstr=new char[length];
-	int64_t	amt=abs(amount);
+	int64_t	amt=abs((int)amount);
 	sprintf(amountstr,"$%s%lld.%02lld",negative,
 				(long long)(amt/100),
 				(long long)(amt-(amt/100*100)));
