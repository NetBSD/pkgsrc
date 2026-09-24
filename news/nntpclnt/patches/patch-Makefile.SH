$NetBSD: patch-Makefile.SH,v 1.1 2026/09/24 17:09:17 rhialto Exp $

Use $(LDFLAGS) and $(CFLAGS)

--- Makefile.SH.orig	2026-09-23 18:08:11.257094438 +0000
+++ Makefile.SH
@@ -26,8 +26,8 @@ $cat >Makefile <<!GROK!THIS!
 CC	=	$cc 
 MANSRC	=	$mansrc
 MANEXT	=	$manext
-CFLAGS	=	$posix $iandd $addcflags -O $include -DNNTPSRC
-LDFLAGS	=	$posix $iandd
+CFLAGS	+=	$posix $iandd $addcflags -O $include -DNNTPSRC
+LDFLAGS	+=	$posix $iandd
 LIBS	=	$ndirlib $termlib $jobslib $socketlib 
 NEWSUSR	=	$newsadmin
 DESTDIR	=	$lib
@@ -42,7 +42,7 @@ README	= 	README README.DECNET README.PC
 MAN	=	nntpclnt.3
 
 inews:  $(OBJS) nntp.h nntpclnt.h
-	$(CC) $(CFLAGS) $(OBJS) -o inews $(LIBS)
+	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o inews $(LIBS)
 
 uname.o: uname.c config.h 
 
