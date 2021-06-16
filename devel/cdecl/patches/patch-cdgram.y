$NetBSD: patch-cdgram.y,v 1.1 2021/06/16 23:08:42 dholland Exp $

Fix shift/reduce conflict that makes "explain static volatile int foo"
not parse. See PR 51100.

Should really be handled by upstream, but there does not seem to be an
upstream.

--- cdgram.y~	1996-01-12 06:06:58.000000000 +0000
+++ cdgram.y
@@ -84,10 +84,20 @@ stmt		: HELP NL
 			docast(NullCP, $2.left, $2.right, $2.type);
 			}
 
-		| EXPLAIN opt_storage opt_constvol_list type cdecl NL
+		| EXPLAIN opt_constvol_list type cdecl NL
 			{
-			Debug((stderr, "stmt: EXPLAIN opt_storage opt_constvol_list type cdecl\n"));
-			Debug((stderr, "\topt_storage='%s'\n", $2));
+			Debug((stderr, "stmt: EXPLAIN opt_constvol_list type cdecl\n"));
+			Debug((stderr, "\topt_constvol_list='%s'\n", $2));
+			Debug((stderr, "\ttype='%s'\n", $3));
+			Debug((stderr, "\tcdecl='%s'\n", $4));
+			Debug((stderr, "\tprev = '%s'\n", visible(prev)));
+			dodexplain(ds(""), $2, $3, $4);
+			}
+
+		| EXPLAIN storage opt_constvol_list type cdecl NL
+			{
+			Debug((stderr, "stmt: EXPLAIN storage opt_constvol_list type cdecl\n"));
+			Debug((stderr, "\tstorage='%s'\n", $2));
 			Debug((stderr, "\topt_constvol_list='%s'\n", $3));
 			Debug((stderr, "\ttype='%s'\n", $4));
 			Debug((stderr, "\tcdecl='%s'\n", $5));
@@ -105,14 +115,13 @@ stmt		: HELP NL
 			dodexplain($2, $3, NullCP, $4);
 			}
 
-		| EXPLAIN opt_storage constvol_list cdecl NL
+		| EXPLAIN constvol_list cdecl NL
 			{
-			Debug((stderr, "stmt: EXPLAIN opt_storage constvol_list cdecl\n"));
-			Debug((stderr, "\topt_storage='%s'\n", $2));
-			Debug((stderr, "\tconstvol_list='%s'\n", $3));
-			Debug((stderr, "\tcdecl='%s'\n", $4));
+			Debug((stderr, "stmt: EXPLAIN constvol_list cdecl\n"));
+			Debug((stderr, "\tconstvol_list='%s'\n", $2));
+			Debug((stderr, "\tcdecl='%s'\n", $3));
 			Debug((stderr, "\tprev = '%s'\n", visible(prev)));
-			dodexplain($2, $3, NullCP, $4);
+			dodexplain(ds(""), $2, NullCP, $3);
 			}
 
 		| EXPLAIN '(' opt_constvol_list type cast ')' optNAME NL
