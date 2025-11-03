$NetBSD: patch-parse.y,v 1.2 2025/11/03 15:56:55 vins Exp $

* Prevent implicit declaration of bcopy.
* Initialize table with zero to prevent uninitialized memory
  from being written. See https://bugs.debian.org/778862

--- parse.y.orig	2021-01-09 21:12:35.277053695 +0000
+++ parse.y
@@ -133,6 +133,7 @@ static char Rcs_Id[] =
  */
 
 #include <ctype.h>
+#include <strings.h>
 #include "config.h"
 #include "ispell.h"
 #include "proto.h"
@@ -957,16 +958,16 @@ table		:	flagdef
 				tblsize = centnum + TBLINC;
 				tblnum = 0;
 				table = (struct flagent *)
-				  malloc (tblsize * (sizeof (struct flagent)));
+				  calloc (tblsize, (sizeof (struct flagent)));
 				if (table == NULL)
 				    {
 				    yyerror (PARSE_Y_NO_SPACE);
 				    exit (1);
 				    }
 				}
-			    else if (tblnum + centnum >= tblsize)
+			    else if (centnum >= tblsize)
 				{
-				tblsize = tblnum + centnum + TBLINC;
+				tblsize = centnum + TBLINC;
 				table = (struct flagent *)
 				  realloc ((char *) table,
 				    tblsize * (sizeof (struct flagent)));
@@ -975,6 +976,7 @@ table		:	flagdef
 				    yyerror (PARSE_Y_NO_SPACE);
 				    exit (1);
 				    }
+				memset((char*)table, 0, tblsize * sizeof(struct flagent));
 				}
 			    for (tblnum = 0;  tblnum < centnum;  tblnum++)
 				table[tblnum] = curents[tblnum];
@@ -995,6 +997,8 @@ table		:	flagdef
 				    yyerror (PARSE_Y_NO_SPACE);
 				    exit (1);
 				    }
+				memset((char*)table + tblnum * sizeof(struct flagent), 0,
+					(tblsize - tblnum) * sizeof(struct flagent));
 				}
 			    for (i = 0;  i < centnum;  i++)
 				table[tblnum + i] = curents[i];
@@ -1260,7 +1264,7 @@ conditions	:	char_set
 			    int			i;
 
 			    ent = (struct flagent *)
-			      malloc (sizeof (struct flagent));
+			      calloc (1, sizeof (struct flagent));
 			    if (ent == NULL)
 				{
 				yyerror (PARSE_Y_NO_SPACE);
