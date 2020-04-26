$NetBSD: patch-text_troff_tdef.h,v 1.1 2020/04/26 20:23:39 rillig Exp $

Fix error message about unfinished macro argument to sprintf.

--- text/troff/tdef.h.orig	2015-05-17 16:28:51.000000000 +0000
+++ text/troff/tdef.h
@@ -51,10 +51,10 @@ typedef	struct	Wcache	Wcache;
 /* the BSD goo is because SunOS sprintf doesn't return anything useful */
 
 #if 0 /* def BSD4_2 */
-#define	OUT		(obufp += strlen((char *)sprintf(obufp,
+#define	OUT		(obufp += strlen((char *)(sprintf)(obufp,
 #define	PUT		))) > obuf+BUFSIZ ? flusho() : 1
 #else
-#define	OUT		(obufp += sprintf(obufp,
+#define	OUT		(obufp += (sprintf)(obufp,
 #define	PUT		)) > obuf+BUFSIZ ? flusho() : 1
 #endif
 
@@ -62,7 +62,7 @@ typedef	struct	Wcache	Wcache;
 #define	oput(c)		( *obufp++ = (c), obufp > obuf+BUFSIZ ? flusho() : 1 )
 
 extern	char	errbuf[];
-#define	ERROR	sprintf(errbuf,
+#define	ERROR	(sprintf)(errbuf,
 #define	WARN	), errprint()
 #define	FATAL	), errprint(), exit(1)
 
