$NetBSD: patch-dissect.h,v 1.1 2013/03/31 00:04:50 dholland Exp $

Replace questionable construction that clang objects to with a
slightly less questionable version that is hopefully equivalent.

--- dissect.h~	2007-05-01 18:30:58.000000000 +0000
+++ dissect.h
@@ -27,13 +27,16 @@ struct reporter
 extern void dissect(struct symbol_list *, struct reporter *);
 
 #define	MK_IDENT(s)	({				\
-	static struct {					\
+	static union {					\
 		struct ident ident;			\
-		char __[sizeof(s)];			\
-	} ident = {{					\
-		.len  = sizeof(s)-1,			\
-		.name = s,				\
-	}};						\
+		struct {				\
+			char id[sizeof(struct ident)];	\
+			char name[sizeof(s)];		\
+		} named;				\
+	} ident = {					\
+		.ident.len  = sizeof(s)-1,		\
+		.named.name = s,			\
+	};						\
 	&ident.ident;					\
 })
 
