$NetBSD: patch-te__main.c,v 1.1 2012/12/27 06:13:20 dholland Exp $

- use standard headers
- move external function declarations to header file
- avoid implicit int
- declare void functions void
- use C89 some
- apply static to a couple local functions
- silence warnings about assignments in conditionals
- remove unused variables
- don't declare own getenv()

--- te_main.c.orig	1993-08-05 22:29:34.000000000 +0000
+++ te_main.c
@@ -49,20 +49,18 @@
 */
 
 #include "te_defs.h"
+#include <stdlib.h>
 #include <signal.h>
-#ifdef _AIX
 #include <sys/ioctl.h>
-#endif
 
-int cleanup();
+static VOID save_args(int argc, char *argv[], struct qh *q);
+static VOID read_startup(void);
+static VOID print_string(int arg);
 
-main(argc, argv)
+int main(argc, argv)
 	int argc;			/* arg count */
 	char *argv[];		/* array of string pointers */
 {
-	int i;
-	VOID init_wd();
-
 	init_wd();				/* set working directory */
 	save_args(argc, argv, &qreg[36]);		/* copy command line to Qz */
 	read_startup();							/* read startup file */
@@ -74,7 +72,7 @@ main(argc, argv)
 	qsp = &qstack[-1];		/* initialize q-reg stack pointer */
 
 /* set up error restart */
-	if (err = setjmp(xxx))
+	if ((err = setjmp(xxx)) != 0)
 	{
 		if (err == E_EFI) goto quit;		/* EOF from standard input - clean up and exit */
 		crlf();
@@ -125,7 +123,7 @@ main(argc, argv)
 
 /* reset screen state, keyboard state; remove open output files */
 
-cleanup()
+VOID cleanup(void)
 {
 	window(WIN_OFF);			/* restore screen */
 	setup_tty(TTY_OFF);			/* restore terminal */
@@ -137,7 +135,7 @@ cleanup()
 /* print string for error message */
 /* argument is subscript of a qreg qh, prints text from that buffer */
 
-print_string(arg)
+static VOID print_string(arg)
 	int arg;
 {
 	int i, c;
@@ -158,7 +156,7 @@ print_string(arg)
 }
 /* copy invocation command line to a text buffer */
 
-save_args(argc, argv, q)
+static VOID save_args(argc, argv, q)
 	int argc;
 	char *argv[];
 	struct qh *q;
@@ -196,7 +194,7 @@ save_args(argc, argv, q)
 
 char startup_name[] = "/.tecorc";		/* name of startup file */
 
-read_startup()
+static VOID read_startup(void)
 {
 	char *hp, *getenv();
 	char fn[CELLSIZE];		/* filename storage */
@@ -206,7 +204,7 @@ read_startup()
 
 	if (!(eisw = fopen(&startup_name[1], "r")))
 	{
-		if (hp = getenv("HOME"))	/* if not found, look in home directory */
+		if ((hp = getenv("HOME")) != NULL)	/* if not found, look in home directory */
 		{
 			for (i = 0; i < CELLSIZE; i++) if (!(fn[i] = *(hp++))) break;	/* copy until trailing null */
 			for (hp = &startup_name[0]; i < CELLSIZE; i++) if (!(fn[i] = *(hp++))) break;
@@ -242,7 +240,6 @@ VOID update_header()
 	char header_text[HEADER_SIZE+3];
 	char *ps, *pd;
 	char *pdir;
-	int i;
 
 	if (toolsw != 0)				/* if running under SunWindows */
 	{
@@ -281,21 +278,20 @@ VOID update_header()
 /* routine to get terminal height and width from termcap */
 
 #ifdef NO_TERMCAP
-get_term_par()
+VOID get_term_par(void)
 {
 	char *pname;
-	char *getenv();
 	struct winsize ws;
 	if (ioctl(fileno(stdin), TIOCGWINSZ, &ws) == 0) 
 		set_term_par(ws.ws_row, ws.ws_col);
-	if (pname=getenv("TERM")) {
+	if ((pname=getenv("TERM")) != NULL) {
 		make_buffer(&timbuf);		/* put terminal name in q# */
 		for (timbuf.z = 0; *pname != '\0'; )
 			timbuf.f->ch[timbuf.z++] = *pname++;
 	}
 }
 #else   /* USE_TERMCAP */
-get_term_par()
+VOID get_term_par(void)
 {
 	char tbuff[1024];	/* termcap buffer */
 	char *pname;		/* pointer to name of terminal */
