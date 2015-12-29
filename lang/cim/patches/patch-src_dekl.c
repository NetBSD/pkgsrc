$NetBSD: patch-src_dekl.c,v 1.2 2015/12/29 23:34:44 dholland Exp $

Avoid implicit int.
Use C89.
Call own functions correctly.

--- src/dekl.c.orig	2012-10-26 12:55:39.000000000 +0000
+++ src/dekl.c
@@ -522,8 +522,7 @@ subordinate (rda, rdb)
 
 /* Kalles fra  syntakssjekkeren hver gang en ny blokk entres */
 
-beginBlock (kind)
-     char kind;
+void beginBlock (char kind)
 {
   static int cblno = STARTBLNO;
   static struct BLOCK *lblock;
@@ -650,9 +649,7 @@ beginBlock (kind)
 /* Kalles  fra  syntakssjekkeren hver gang en blokk terminerer */
 
 /*VARARGS0 */
-endBlock (rtname, codeclass)
-     char *rtname;
-     char codeclass;
+void endBlock (char *rtname, char codeclass)
 {
 #ifdef DEBUG
   if (option_input)
@@ -688,8 +685,7 @@ endBlock (rtname, codeclass)
 /* RegDecl kalles fra syntakssjekkeren
  * hver gang  vi leser  en deklarasjon */
 
-regDecl (ident, type, kind, categ)
-     char *ident, type, kind, categ;
+void regDecl (char *ident, char type, char kind, char categ)
 {
   struct DECL *pd,
    *pdx = NULL;
@@ -858,7 +854,7 @@ regDecl (ident, type, kind, categ)
 	}
       break;
     default:
-      d1error (37);
+      d1error (37, NULL);
       break;
     }
 #ifdef DEBUG
@@ -881,11 +877,11 @@ regInner ()
 	    ,lineno, cblev);
 #endif
   if (cblock->quant.kind != KCLASS)
-    d1error (38);
+    d1error (38, NULL);
   else
     {
       if (cblock->inner)
-	d1error (39);
+	d1error (39, NULL);
       else
 	cblock->inner = TRUE;
     }
@@ -1233,13 +1229,13 @@ setqualprefchain (rd, param)
 	  rd->plev = 0;
 	  if (rdx->categ == CNEW)
 	    {
-	      d2error (53, rd);
+	      d2error (53, rd, NULL);
 	      rdx->categ = CERROR;
 	    }
 	  else if (rdx->kind != KCLASS)
 	    {
 	      if (rdx->categ != CERROR)
-		d2error (54, rd);
+		d2error (54, rd, NULL);
 	      rdx->categ = CERROR;
 	      rd->type = TERROR;
 	    }
@@ -1259,8 +1255,7 @@ setqualprefchain (rd, param)
  * Prefikskjeden og kvalifikasjoner settes ved kall på setqualprefchain 
  * den sjekker også konsistensen for type kind og categ */
 
-static sjekkdekl (rb)
-     struct BLOCK *rb;
+static void sjekkdekl (struct BLOCK *rb)
 {
   struct DECL *rd = NULL,
    *rdx = NULL,
@@ -1344,11 +1339,11 @@ static sjekkdekl (rb)
 		  obstack_free (&osDecl, s);
 		}
 	      else
-		d2error (55, rd);
+		d2error (55, rd, NULL);
 	    }
 	}
       if (rd->kind == KNOKD && rd->type != TVARARGS)
-	d2error (63, rd);
+	d2error (63, rd, NULL);
       if (rd->kind == KARRAY && rd->type == TNOTY)
 	rd->type = TREAL;
       switch (rd->categ)
@@ -1369,12 +1364,12 @@ static sjekkdekl (rb)
 	  if (rd->type == TVARARGS)
 	    {
 	      if (rd->next != NULL)
-		d2error (80, rd);
+		d2error (80, rd, NULL);
 	      if (kind != KPROC || rb->quant.categ != CCPROC)
-		d2error (81, rd);
+		d2error (81, rd, NULL);
 	    }
 	  if (rd->type == TLABEL && rb->quant.categ == CCPROC)
-	    d2error (82, rd);
+	    d2error (82, rd, NULL);
 	  break;
 	case CVALUE:
 	  /* Sjekker om lovlig valueoverføring */
@@ -1388,14 +1383,14 @@ static sjekkdekl (rb)
 	  else if (rd->type == TVARARGS)
 	    {
 	      if (rd->next != NULL)
-		d2error (80, rd);
+		d2error (80, rd, NULL);
 	      if (kind != KPROC || rb->quant.categ != CCPROC)
-		d2error (81, rd);
+		d2error (81, rd, NULL);
 	    }
 	  else
-	    d2error (57, rd);
+	    d2error (57, rd, NULL);
 	  if (rd->type == TLABEL && rb->quant.categ == CCPROC)
-	    d2error (82, rd);
+	    d2error (82, rd, NULL);
 	  break;
 	case CVAR:
 	  if (rd->type == TREF && (rd->kind == KSIMPLE | rd->kind == KARRAY))
@@ -1408,27 +1403,27 @@ static sjekkdekl (rb)
 	    d2error (58, rd);*/
 	  if (kind == KPROC && rb->quant.categ == CCPROC &&
 	      (rd->type == TTEXT || rd->type == TREF))
-	    d2error (77, rd);
+	    d2error (77, rd, NULL);
 	  if (rd->type == TVARARGS)
 	    {
 	      if (rd->next != NULL)
-		d2error (80, rd);
+		d2error (80, rd, NULL);
 	      if (kind != KPROC || rb->quant.categ != CCPROC)
-		d2error (81, rd);
+		d2error (81, rd, NULL);
 	    }
 	  if (rd->type == TLABEL && rb->quant.categ == CCPROC)
-	    d2error (82, rd);
+	    d2error (82, rd, NULL);
 	  break;
 	case CEXTR:
 	case CEXTRMAIN:
 	  break;
 	case CCPROC:
 	  if (rd->type == TREF)
-	    d2error (78, rd);
+	    d2error (78, rd, NULL);
 	  break;
 	default:
 	  /* ULOVLIG CATEG */
-	  d2error (59, rd);
+	  d2error (59, rd, NULL);
 	}
     }
   if (rb->quant.kind == KCLASS || rb->quant.kind == KPRBLK)
@@ -1474,7 +1469,7 @@ static sjekkdekl (rb)
 		   va->protected == TRUE; va = va->next);
 	      if (va != vc)
 		{
-		  d2error (60, vc);
+		  d2error (60, vc, NULL);
 		  while (va->next != vc)
 		    va = va->next;
 		  va->next = vc->next;
@@ -1485,7 +1480,7 @@ static sjekkdekl (rb)
 		  /* Sjekker om det er lovlig virtuell */
 		  if (vc->kind != KPROC && vc->type != TLABEL)
 		    {
-		      d2error (61, vc);
+		      d2error (61, vc, NULL);
 		      vc->type = TERROR;
 		      vc->kind = KERROR;
 		    }
@@ -1560,7 +1555,7 @@ static sjekkdekl (rb)
 	      vc->prefqual = va->prefqual;
 	    }
 	  else
-	    d2error (62, va);
+	    d2error (62, va, NULL);
 	}
       else if (vc->match == vc)
 	vc->match = NULL;
@@ -1573,11 +1568,11 @@ static sjekkdekl (rb)
 	  rdx = findLocal (rd->ident, &rb->quant, TRUE);
 	  if (rdx->categ == CNEW)
 	    {
-	      d2error (74, rd);
+	      d2error (74, rd, NULL);
 	      rdx->categ = CERROR;
 	    }
 	  else if (rd->categ != CHIDEN && rdx->encl != rb)
-	    d2error (75, rd);
+	    d2error (75, rd, NULL);
 	  else if (rd->categ != CHIDEN && rdx->categ == CVIRT)
 	    {
 	      if (rb->quant.plev == 0)
@@ -1587,7 +1582,7 @@ static sjekkdekl (rb)
 	      else
 		vno = rb->quant.prefqual->descr->navirtlab;
 	      if (rdx->virtno <= vno)
-		d2error (75, rd);
+		d2error (75, rd, NULL);
 	      else
 		rd->match = rdx;
 	    }
@@ -1607,7 +1602,7 @@ static sjekkdekl (rb)
       for (rd = rb->hiprot; rd != NULL; rd = rd->next)
 	if (rd->categ == CHIDEN && rd->match != NULL &&
 	    rd->match->protected == FALSE)
-	  d2error (76, rd);
+	  d2error (76, rd, NULL);
     }
 }
 
@@ -1710,7 +1705,7 @@ reginsp (rb, rd) struct BLOCK *rb; struc
 {
   if (rd == NULL)
     {
-      d2error (73, &rb->quant);
+      d2error (73, &rb->quant, NULL);
       rd = findGlobal (tag ("Noqual"), FALSE);
       rd->categ = CERROR;
     }
@@ -1755,7 +1750,7 @@ regThis (ident)
 		if (rd->ident == ident)
 		  {
 		    if (rd->descr->thisused == MAYBEE)
-		      d2error (72, rd);
+		      d2error (72, rd, NULL);
 		    rd->descr->thisused |= TRUE;
 #ifdef DEBUG
 		    if (option_input)
@@ -1776,7 +1771,7 @@ regThis (ident)
   if (option_input)
     printf ("---end\n");
 #endif
-  d2error (79, rd = findGlobal (ident, FALSE));
+  d2error (79, rd = findGlobal (ident, FALSE), NULL);
   return (rd);
 }
 
