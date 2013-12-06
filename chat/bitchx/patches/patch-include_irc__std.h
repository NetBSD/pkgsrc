$NetBSD: patch-include_irc__std.h,v 1.1 2013/12/06 15:35:53 seanb Exp $

Later gcc have a string optimization pass at -O2 which
will swap combinations strcat to stpcpy if it sees a
stpcpy prototype.  This leads to undefined references 
if it's not actually present.

--- include/irc_std.h.orig	2003-04-11 01:09:07.000000000 +0000
+++ include/irc_std.h
@@ -190,7 +190,7 @@ extern  char    *sys_errlist[];
 extern	int	gettimeofday(struct timeval *tv, struct timezone *tz);
 #endif
 
-#ifndef STPCPY_DECLARED
+#if defined(HAVE_STPCPY) && !defined(STPCPY_DECLARED)
 char *  stpcpy (char *to, const char *from);
 #endif
 
