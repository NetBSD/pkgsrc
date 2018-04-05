$NetBSD: patch-mdoc__validate.c,v 1.1 2018/04/05 09:20:52 wiz Exp $

Style message about bad input encoding of em-dashes as -- instead of \(em.
Suggested by Thomas Klausner <wiz at NetBSD>; discussed with jmc@.

--- mdoc_validate.c.orig	2017-08-05 12:40:22.000000000 +0000
+++ mdoc_validate.c
@@ -2,5 +2,5 @@
 /*
  * Copyright (c) 2008-2012 Kristaps Dzonsons <kristaps@bsd.lv>
- * Copyright (c) 2010-2017 Ingo Schwarze <schwarze@openbsd.org>
+ * Copyright (c) 2010-2018 Ingo Schwarze <schwarze@openbsd.org>
  * Copyright (c) 2010 Joerg Sonnenberger <joerg@netbsd.org>
  *
@@ -54,8 +54,9 @@ typedef	void	(*v_post)(POST_ARGS);
 
 static	int	 build_list(struct roff_man *, int);
-static	void	 check_text(struct roff_man *, int, int, char *);
 static	void	 check_argv(struct roff_man *,
 			struct roff_node *, struct mdoc_argv *);
 static	void	 check_args(struct roff_man *, struct roff_node *);
+static	void	 check_text(struct roff_man *, int, int, char *);
+static	void	 check_text_em(struct roff_man *, int, int, char *);
 static	void	 check_toptext(struct roff_man *, int, int, const char *);
 static	int	 child_an(const struct roff_node *);
@@ -289,5 +290,5 @@ void
 mdoc_node_validate(struct roff_man *mdoc)
 {
-	struct roff_node *n;
+	struct roff_node *n, *np;
 	const v_post *p;
 
@@ -306,11 +307,16 @@ mdoc_node_validate(struct roff_man *mdoc
 	switch (n->type) {
 	case ROFFT_TEXT:
+		np = n->parent;
 		if (n->sec != SEC_SYNOPSIS ||
-		    (n->parent->tok != MDOC_Cd && n->parent->tok != MDOC_Fd))
+		    (np->tok != MDOC_Cd && np->tok != MDOC_Fd))
 			check_text(mdoc, n->line, n->pos, n->string);
-		if (n->parent->tok == MDOC_It ||
-		    (n->parent->type == ROFFT_BODY &&
-		     (n->parent->tok == MDOC_Sh ||
-		      n->parent->tok == MDOC_Ss)))
+		if (np->tok != MDOC_Ql && np->tok != MDOC_Dl &&
+		    (np->tok != MDOC_Bd ||
+		     (mdoc->flags & MDOC_LITERAL) == 0) &&
+		    (np->tok != MDOC_It || np->type != ROFFT_HEAD ||
+		     np->parent->parent->norm->Bl.type != LIST_diag))
+			check_text_em(mdoc, n->line, n->pos, n->string);
+		if (np->tok == MDOC_It || (np->type == ROFFT_BODY &&
+		    (np->tok == MDOC_Sh || np->tok == MDOC_Ss)))
 			check_toptext(mdoc, n->line, n->pos, n->string);
 		break;
@@ -396,4 +402,55 @@ check_text(struct roff_man *mdoc, int ln
 
 static void
+check_text_em(struct roff_man *mdoc, int ln, int pos, char *p)
+{
+	const struct roff_node	*np, *nn;
+	char			*cp;
+
+	np = mdoc->last->prev;
+	nn = mdoc->last->next;
+
+	/* Look for em-dashes wrongly encoded as "--". */
+
+	for (cp = p; *cp != '\0'; cp++) {
+		if (*cp != '-' || *++cp != '-')
+			continue;
+
+		/* Skip input sequences of more than two '-'. */
+
+		if (cp[1] == '-') {
+			while (cp[1] == '-')
+				cp++;
+			continue;
+		}
+
+		/* Skip "--" directly attached to something else. */
+
+		if ((cp - p > 1 && cp[-2] != ' ') ||
+		    (cp[1] != '\0' && cp[1] != ' '))
+			continue;
+
+		/* Require a letter right before or right afterwards. */
+
+		if ((cp - p > 2 ?
+		     isalpha((unsigned char)cp[-3]) :
+		     np != NULL &&
+		     np->type == ROFFT_TEXT &&
+		     np->string != '\0' &&
+		     isalpha((unsigned char)np->string[
+		       strlen(np->string) - 1])) ||
+		    (cp[2] != '\0' ?
+		     isalpha((unsigned char)cp[2]) :
+		     nn != NULL &&
+		     nn->type == ROFFT_TEXT &&
+		     nn->string != '\0' &&
+		     isalpha((unsigned char)*nn->string))) {
+			mandoc_msg(MANDOCERR_DASHDASH, mdoc->parse,
+			    ln, pos + (int)(cp - p) - 1, NULL);
+			break;
+		}
+	}
+}
+
+static void
 check_toptext(struct roff_man *mdoc, int ln, int pos, const char *p)
 {
