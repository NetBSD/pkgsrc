$NetBSD: patch-markdown.c,v 1.2 2025/05/07 08:31:03 wiz Exp $

Fix isspace() argument.
https://github.com/Orc/discount/pull/293

--- markdown.c.orig	2025-05-05 22:01:49.993582379 +0000
+++ markdown.c
@@ -40,7 +40,7 @@ __mkd_footsort(Footnote *a, Footnote *b)
 	ac = tolower(T(a->tag)[i]);
 	bc = tolower(T(b->tag)[i]);
 
-	if ( isspace(ac) && isspace(bc) )
+	if ( isspace((unsigned char)ac) && isspace((unsigned char)bc) )
 	    continue;
 	if ( ac != bc )
 	    return ac - bc;
@@ -54,7 +54,7 @@ __mkd_footsort(Footnote *a, Footnote *b)
 static int
 nextblank(Line *t, int i)
 {
-    while ( (i < S(t->text)) && !isspace(T(t->text)[i]) )
+    while ( (i < S(t->text)) && !isspace((unsigned char)T(t->text)[i]) )
 	++i;
     return i;
 }
@@ -65,7 +65,7 @@ nextblank(Line *t, int i)
 static int
 nextnonblank(Line *t, int i)
 {
-    while ( (i < S(t->text)) && isspace(T(t->text)[i]) )
+    while ( (i < S(t->text)) && isspace((unsigned char)T(t->text)[i]) )
 	++i;
     return i;
 }
@@ -99,7 +99,7 @@ skipempty(Line *p)
 void
 ___mkd_tidy(Cstring *t)
 {
-    while ( S(*t) && isspace(T(*t)[S(*t)-1]) )
+    while ( S(*t) && isspace((unsigned char)T(*t)[S(*t)-1]) )
 	--S(*t);
 }
 
@@ -131,7 +131,7 @@ isopentag(Line *p)
      */
     for ( i=1; i < len && T(p->text)[i] != '>' 
 		       && T(p->text)[i] != '/'
-		       && !isspace(T(p->text)[i]); ++i )
+		       && !isspace((unsigned char)T(p->text)[i]); ++i )
 	;
 
 
@@ -203,7 +203,7 @@ checkline(Line *l, mkd_flag_t flags)
     
     if (l->dle >= 4) { l->kind=chk_code; return; }
 
-    for ( eol = S(l->text); eol > l->dle && isspace(T(l->text)[eol-1]); --eol )
+    for ( eol = S(l->text); eol > l->dle && isspace((unsigned char)T(l->text)[eol-1]); --eol )
 	;
 
     for (i=l->dle; i<eol; i++) {
@@ -467,7 +467,7 @@ static int
 is_extra_dd(Line *t)
 {
     return (t->dle < 4) && (T(t->text)[t->dle] == ':')
-			&& isspace(T(t->text)[t->dle+1]);
+			&& isspace((unsigned char)T(t->text)[t->dle+1]);
 }
 
 
@@ -522,7 +522,7 @@ islist(Line *t, int *clip, mkd_flag_t fl
 				      && isdefinition(t,clip,list_type,flags) )
 	return DL;
 
-    if ( strchr("*-+", T(t->text)[t->dle]) && isspace(T(t->text)[t->dle+1]) ) {
+    if ( strchr("*-+", T(t->text)[t->dle]) && isspace((unsigned char)T(t->text)[t->dle+1]) ) {
 	i = nextnonblank(t, t->dle+1);
 	*clip = (i > 4) ? 4 : i;
 	*list_type = UL;
@@ -583,7 +583,7 @@ headerblock(Paragraph *pp, int htyp)
 
 	    pp->hnumber = i;
 
-	    while ( (i < S(p->text)) && isspace(T(p->text)[i]) )
+	    while ( (i < S(p->text)) && isspace((unsigned char)T(p->text)[i]) )
 		++i;
 
 	    CLIP(p->text, 0, i);
@@ -592,7 +592,7 @@ headerblock(Paragraph *pp, int htyp)
 	    for (j=S(p->text); (j > 1) && (T(p->text)[j-1] == '#'); --j)
 		;
 
-	    while ( j && isspace(T(p->text)[j-1]) )
+	    while ( j && isspace((unsigned char)T(p->text)[j-1]) )
 		--j;
 
 	    S(p->text) = j;
@@ -1095,7 +1095,7 @@ addfootnote(Line *p, MMIOT* f)
 	return np;
     }
 
-    while ( (j < S(p->text)) && !isspace(T(p->text)[j]) )
+    while ( (j < S(p->text)) && !isspace((unsigned char)T(p->text)[j]) )
 	EXPAND(foot->link) = T(p->text)[j++];
     EXPAND(foot->link) = 0;
     S(foot->link)--;
@@ -1296,7 +1296,7 @@ actually_a_table(MMIOT *f, Line *pp)
     for ( j=r->dle; j < S(r->text); ++j ) {
 	c = T(r->text)[j];
 
-	if ( !(isspace(c)||(c=='-')||(c==':')||(c=='|')) ) {
+	if ( !(isspace((unsigned char)c)||(c=='-')||(c==':')||(c=='|')) ) {
 	    return 0;
 	}
     }
