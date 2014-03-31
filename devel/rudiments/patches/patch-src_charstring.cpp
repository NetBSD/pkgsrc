$NetBSD: patch-src_charstring.cpp,v 1.2 2014/03/31 14:42:20 fhajny Exp $

Remove ambiguity (fixes build with GCC>=4.7).
--- src/charstring.cpp.orig	2014-03-07 05:54:23.000000000 +0000
+++ src/charstring.cpp
@@ -349,7 +349,7 @@ char *charstring::convertAmount(int64_t
 	}
 	negative[1]='\0';
 	char	*amountstr=new char[length];
-	int64_t	amt=abs(amount);
+	int64_t	amt=abs((int)amount);
 	printf(amountstr,length,
 			"$%s%lld.%02lld",negative,
 			(long long)(amt/100),
