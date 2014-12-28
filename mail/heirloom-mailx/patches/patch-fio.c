$NetBSD: patch-fio.c,v 1.1 2014/12/28 14:16:14 bsiegert Exp $

Imported Debian package fixes:
- fioc: unconditionally require wordexp support
- globname: Invoke wordexp with WRDE_NOCMD (CVE-2004-2771)

--- fio.c.orig	2011-04-26 21:23:22.000000000 +0000
+++ fio.c
@@ -43,12 +43,15 @@ static char sccsid[] = "@(#)fio.c	2.76 (
 #endif /* not lint */
 
 #include "rcv.h"
+
+#ifndef HAVE_WORDEXP
+#error wordexp support is required
+#endif
+
 #include <sys/stat.h>
 #include <sys/file.h>
 #include <sys/wait.h>
-#ifdef	HAVE_WORDEXP
 #include <wordexp.h>
-#endif	/* HAVE_WORDEXP */
 #include <unistd.h>
 
 #if defined (USE_NSS)
@@ -481,7 +484,6 @@ next:
 static char *
 globname(char *name)
 {
-#ifdef	HAVE_WORDEXP
 	wordexp_t we;
 	char *cp;
 	sigset_t nset;
@@ -495,7 +497,7 @@ globname(char *name)
 	sigemptyset(&nset);
 	sigaddset(&nset, SIGCHLD);
 	sigprocmask(SIG_BLOCK, &nset, NULL);
-	i = wordexp(name, &we, 0);
+        i = wordexp(name, &we, WRDE_NOCMD);
 	sigprocmask(SIG_UNBLOCK, &nset, NULL);
 	switch (i) {
 	case 0:
@@ -527,65 +529,6 @@ globname(char *name)
 	}
 	wordfree(&we);
 	return cp;
-#else	/* !HAVE_WORDEXP */
-	char xname[PATHSIZE];
-	char cmdbuf[PATHSIZE];		/* also used for file names */
-	int pid, l;
-	char *cp, *shell;
-	int pivec[2];
-	extern int wait_status;
-	struct stat sbuf;
-
-	if (pipe(pivec) < 0) {
-		perror("pipe");
-		return name;
-	}
-	snprintf(cmdbuf, sizeof cmdbuf, "echo %s", name);
-	if ((shell = value("SHELL")) == NULL)
-		shell = SHELL;
-	pid = start_command(shell, 0, -1, pivec[1], "-c", cmdbuf, NULL);
-	if (pid < 0) {
-		close(pivec[0]);
-		close(pivec[1]);
-		return NULL;
-	}
-	close(pivec[1]);
-again:
-	l = read(pivec[0], xname, sizeof xname);
-	if (l < 0) {
-		if (errno == EINTR)
-			goto again;
-		perror("read");
-		close(pivec[0]);
-		return NULL;
-	}
-	close(pivec[0]);
-	if (wait_child(pid) < 0 && WTERMSIG(wait_status) != SIGPIPE) {
-		fprintf(stderr, catgets(catd, CATSET, 81,
-				"\"%s\": Expansion failed.\n"), name);
-		return NULL;
-	}
-	if (l == 0) {
-		fprintf(stderr, catgets(catd, CATSET, 82,
-					"\"%s\": No match.\n"), name);
-		return NULL;
-	}
-	if (l == sizeof xname) {
-		fprintf(stderr, catgets(catd, CATSET, 83,
-				"\"%s\": Expansion buffer overflow.\n"), name);
-		return NULL;
-	}
-	xname[l] = 0;
-	for (cp = &xname[l-1]; *cp == '\n' && cp > xname; cp--)
-		;
-	cp[1] = '\0';
-	if (strchr(xname, ' ') && stat(xname, &sbuf) < 0) {
-		fprintf(stderr, catgets(catd, CATSET, 84,
-				"\"%s\": Ambiguous.\n"), name);
-		return NULL;
-	}
-	return savestr(xname);
-#endif	/* !HAVE_WORDEXP */
 }
 
 /*
