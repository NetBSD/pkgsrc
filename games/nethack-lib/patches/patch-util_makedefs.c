$NetBSD: patch-util_makedefs.c,v 1.1 2012/12/16 20:34:08 dholland Exp $

Remove illegal casts, avoiding undefined behavior and resulting
SIGSEGV during build.

--- util/makedefs.c~	2003-12-07 23:39:13.000000000 +0000
+++ util/makedefs.c
@@ -543,7 +543,7 @@ const char *build_date;
 void
 do_date()
 {
-	long clocktim = 0;
+	time_t clocktim = 0;
 	char *c, cbuf[60], buf[BUFSZ];
 	const char *ul_sfx;
 
@@ -559,13 +559,8 @@ do_date()
 	Fprintf(ofp,"/*\tSCCS Id: @(#)date.h\t3.4\t2002/02/03 */\n\n");
 	Fprintf(ofp,Dont_Edit_Code);
 
-#ifdef KR1ED
 	(void) time(&clocktim);
 	Strcpy(cbuf, ctime(&clocktim));
-#else
-	(void) time((time_t *)&clocktim);
-	Strcpy(cbuf, ctime((time_t *)&clocktim));
-#endif
 	for (c = cbuf; *c; c++) if (*c == '\n') break;
 	*c = '\0';	/* strip off the '\n' */
 	Fprintf(ofp,"#define BUILD_DATE \"%s\"\n", cbuf);
@@ -595,7 +590,7 @@ do_date()
 	Fprintf(ofp,"\n");
 #ifdef AMIGA
 	{
-	struct tm *tm = localtime((time_t *) &clocktim);
+	struct tm *tm = localtime(&clocktim);
 	Fprintf(ofp,"#define AMIGA_VERSION_STRING ");
 	Fprintf(ofp,"\"\\0$VER: NetHack %d.%d.%d (%d.%d.%d)\"\n",
 		VERSION_MAJOR, VERSION_MINOR, PATCHLEVEL,
