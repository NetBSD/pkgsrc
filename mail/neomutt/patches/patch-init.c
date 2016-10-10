$NetBSD: patch-init.c,v 1.1 2016/10/10 19:26:31 wiz Exp $

forgotten-attachment: fix empty regex expression

The original regex was of the form "abc(|def)" to check for both "abc"
and "abcdef".  Unfortunately, the regex libraries on BSDs/MacOS don't
like this use of an empty sub-expression.

Expanding the regex to: "(abc|abcdef)" fixes the problem.

https://github.com/neomutt/neomutt/commit/3bc69ca25077b171f1ae9beee484629c5b5c6482

--- init.c.orig	2016-10-03 11:27:32.000000000 +0000
+++ init.c
@@ -1704,6 +1704,7 @@ static void mutt_restore_default (struct
 
 	if (p->init)
 	{
+	  int retval;
 	  char *s = (char *) p->init;
 
 	  pp->rx = safe_calloc (1, sizeof (regex_t));
@@ -1715,10 +1716,15 @@ static void mutt_restore_default (struct
 	    s++;
 	    pp->not = 1;
 	  }
-	  if (REGCOMP (pp->rx, s, flags) != 0)
+	  retval = REGCOMP (pp->rx, s, flags);
+	  if (retval != 0)
 	  {
+	    char msgbuf[STRING];
+	    regerror (retval, pp->rx, msgbuf, sizeof (msgbuf));
 	    fprintf (stderr, _("mutt_restore_default(%s): error in regexp: %s\n"),
 		     p->option, pp->pattern);
+	    fprintf (stderr, "%s\n", msgbuf);
+	    mutt_sleep (0);
 	    FREE (&pp->pattern);
 	    FREE (&pp->rx);
 	  }
