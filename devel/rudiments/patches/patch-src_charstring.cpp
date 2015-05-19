$NetBSD: patch-src_charstring.cpp,v 1.3 2015/05/19 14:12:40 ryoon Exp $

Remove ambiguity (fixes build with GCC>=4.7).
--- src/charstring.cpp.orig	2015-04-12 01:27:08.000000000 +0000
+++ src/charstring.cpp
@@ -356,7 +356,7 @@ char *charstring::convertAmount(int64_t 
 	}
 	negative[1]='\0';
 	char	*amountstr=new char[length];
-	int64_t	amt=abs(amount);
+	int64_t	amt=abs((int)amount);
 	printf(amountstr,length,
 			"$%s%lld.%02lld",negative,
 			amt/100,amt-(amt/100*100));
