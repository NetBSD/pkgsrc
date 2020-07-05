$NetBSD: patch-parsedate.y,v 1.1 2020/07/05 13:35:31 rhialto Exp $

Add date grammar rules for old articles from olduse.net.

--- parsedate.y.orig	2000-05-27 00:31:17.000000000 +0000
+++ parsedate.y
@@ -134,6 +134,10 @@ item	: time {
 	| rel {
 	    yyHaveRel = 1;
 	}
+	| unixdatestamp {
+	    yyHaveTime++;
+	    yyHaveDate++;
+	}
 	;
 
 time	: tUNUMBER o_merid {
@@ -259,6 +263,24 @@ date	: tUNUMBER '/' tUNUMBER {
 	    yyMonth = $4;
 	    yyYear = $5;
 	}
+	/* Sun, 5-May-85 13:39:01 EDT */
+	| tDAY ',' tUNUMBER tMONTH tSNUMBER {
+	    /* a loose '-' disappears, and -85 becomes a single number */
+	    yyDay = $3;
+	    yyMonth = $4;
+	    yyYear = -$5;
+	    if (yyYear < 0)
+		yyYear = -yyYear;
+	}
+	/* 5-May-85 13:39:01 EDT */
+	| tUNUMBER tMONTH tSNUMBER {
+	    /* a loose '-' disappears, and -85 becomes a single number */
+	    yyDay = $1;
+	    yyMonth = $2;
+	    yyYear = -$3;
+	    if (yyYear < 0)
+		yyYear = -yyYear;
+	}
 	;
 
 rel	: tSNUMBER tSEC_UNIT {
@@ -283,6 +305,21 @@ o_merid	: /* NULL */ {
 	}
 	;
 
+	/* Sat Apr 24 10:49:30 1982 */
+unixdatestamp: tDAY tMONTH tUNUMBER udtime tUNUMBER {
+	    yyDay = $3;
+	    yyMonth = $2;
+	    yyYear = $5;
+	}
+	;
+
+udtime	: tUNUMBER ':' tUNUMBER ':' tUNUMBER {
+	    yyHour = $1;
+	    yyMinutes = $3;
+	    yySeconds = $5;
+	    yyMeridian = MER24;
+	    yyDSTmode = DSToff;
+	}
 %%
 
 /* Month and day table. */
@@ -692,6 +729,9 @@ date_lex()
 	if (isdigit(c) || c == '-' || c == '+') {
 	    if (c == '-' || c == '+') {
 		sign = c == '-' ? -1 : 1;
+#ifdef TEST
+		printf(" A number? %s\n", yyInput);
+#endif
 		yyInput++;
 		if (!isdigit(*yyInput))
 		    /* Skip the plus or minus sign. */
@@ -703,6 +743,9 @@ date_lex()
 		i = 10 * i + c - '0';
 	    yyInput--;
 	    yylval.Number = sign < 0 ? -i : i;
+#ifdef TEST
+	    printf(" A number? => %d %s\n", yylval.Number, yyInput);
+#endif
 	    return sign ? tSNUMBER : tUNUMBER;
 	}
 
@@ -713,9 +756,15 @@ date_lex()
 		    *p++ = isupper(c) ? tolower(c) : c;
 	    *p = '\0';
 	    yyInput--;
+#ifdef TEST
+	    printf(" A word: %s %s\n", buff, yyInput);
+#endif
 	    return LookupWord(buff, p - buff);
 	}
 
+#ifdef TEST
+	printf(" A char: %s\n", yyInput);
+#endif
 	return *yyInput++;
     }
 }
@@ -799,7 +848,7 @@ main(ac, av)
 	    continue;
 	}
 #endif /* YYDEBUG */
-	d = parsedate(buff, (TIMEINFO *)NULL);
+	d = parsedate(buff);
 	if (d == -1)
 	    (void)printf("Bad format - couldn't convert.\n");
 	else
