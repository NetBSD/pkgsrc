$NetBSD: patch-ackstring.h,v 1.1 2012/12/26 21:21:38 dholland Exp $

- declare own functions

--- ackstring.h~	1994-04-25 16:43:46.000000000 +0000
+++ ackstring.h
@@ -11,6 +11,5 @@ extern unsigned char	__code_map[];
 #define	IsCtrl(code)	(__code_map[code]&8)
 #define	IsKana(code)	(__code_map[code]&16)
 
-extern char	*SearchExtPosition();
-extern int	*strcmpalp();
-
+char *SearchExtPosition(char *ptr);
+int StrCmpAL( const char *ptr1, const char *ptr2 );
