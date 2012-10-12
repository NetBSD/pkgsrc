$NetBSD: patch-lib_krb5_krb_deltat.c,v 1.1 2012/10/12 08:06:25 marino Exp $

Required for gcc 4.7 (taken from upstream)

--- lib/krb5/krb/deltat.c.orig	2012-08-08 22:27:56.000000000 +0000
+++ lib/krb5/krb/deltat.c
@@ -77,6 +77,7 @@
 #ifdef __GNUC__
 #pragma GCC diagnostic push
 #pragma GCC diagnostic ignored "-Wuninitialized"
+#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
 #endif
 
 #include <ctype.h>
@@ -163,7 +164,7 @@ static int yyparse (void *);
 
 
 /* Line 189 of yacc.c  */
-#line 167 "deltat.c"
+#line 168 "deltat.c"
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
@@ -204,12 +205,12 @@ typedef union YYSTYPE
 {
 
 /* Line 214 of yacc.c  */
-#line 134 "x-deltat.y"
+#line 135 "x-deltat.y"
  int val;
 
 
 /* Line 214 of yacc.c  */
-#line 213 "deltat.c"
+#line 214 "deltat.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -221,7 +222,7 @@ typedef union YYSTYPE
 
 
 /* Line 264 of yacc.c  */
-#line 225 "deltat.c"
+#line 226 "deltat.c"
 
 #ifdef short
 # undef short
@@ -512,9 +513,9 @@ static const yytype_int8 yyrhs[] =
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint8 yyrline[] =
 {
-       0,   145,   145,   146,   146,   147,   147,   148,   148,   149,
-     150,   152,   153,   154,   155,   156,   157,   158,   159,   163,
-     164,   167,   168,   171,   172
+       0,   146,   146,   147,   147,   148,   148,   149,   149,   150,
+     151,   153,   154,   155,   156,   157,   158,   159,   160,   164,
+     165,   168,   169,   172,   173
 };
 #endif
 
@@ -1442,84 +1443,84 @@ yyreduce:
         case 6:
 
 /* Line 1464 of yacc.c  */
-#line 147 "x-deltat.y"
+#line 148 "x-deltat.y"
     { (yyval.val) = - (yyvsp[(2) - (2)].val); ;}
     break;
 
   case 9:
 
 /* Line 1464 of yacc.c  */
-#line 149 "x-deltat.y"
+#line 150 "x-deltat.y"
     { (yyval.val) = (yyvsp[(2) - (2)].val); ;}
     break;
 
   case 10:
 
 /* Line 1464 of yacc.c  */
-#line 150 "x-deltat.y"
+#line 151 "x-deltat.y"
     { YYERROR; ;}
     break;
 
   case 11:
 
 /* Line 1464 of yacc.c  */
-#line 152 "x-deltat.y"
+#line 153 "x-deltat.y"
     { DO ((yyvsp[(1) - (3)].val),  0,  0, (yyvsp[(3) - (3)].val)); ;}
     break;
 
   case 12:
 
 /* Line 1464 of yacc.c  */
-#line 153 "x-deltat.y"
+#line 154 "x-deltat.y"
     { DO ( 0, (yyvsp[(1) - (3)].val),  0, (yyvsp[(3) - (3)].val)); ;}
     break;
 
   case 13:
 
 /* Line 1464 of yacc.c  */
-#line 154 "x-deltat.y"
+#line 155 "x-deltat.y"
     { DO ( 0,  0, (yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val)); ;}
     break;
 
   case 14:
 
 /* Line 1464 of yacc.c  */
-#line 155 "x-deltat.y"
+#line 156 "x-deltat.y"
     { DO ( 0,  0,  0, (yyvsp[(1) - (2)].val)); ;}
     break;
 
   case 15:
 
 /* Line 1464 of yacc.c  */
-#line 156 "x-deltat.y"
+#line 157 "x-deltat.y"
     { DO ((yyvsp[(1) - (7)].val), (yyvsp[(3) - (7)].val), (yyvsp[(5) - (7)].val), (yyvsp[(7) - (7)].val)); ;}
     break;
 
   case 16:
 
 /* Line 1464 of yacc.c  */
-#line 157 "x-deltat.y"
+#line 158 "x-deltat.y"
     { DO ( 0, (yyvsp[(1) - (5)].val), (yyvsp[(3) - (5)].val), (yyvsp[(5) - (5)].val)); ;}
     break;
 
   case 17:
 
 /* Line 1464 of yacc.c  */
-#line 158 "x-deltat.y"
+#line 159 "x-deltat.y"
     { DO ( 0, (yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val),  0); ;}
     break;
 
   case 18:
 
 /* Line 1464 of yacc.c  */
-#line 159 "x-deltat.y"
+#line 160 "x-deltat.y"
     { DO ( 0,  0,  0, (yyvsp[(1) - (1)].val)); ;}
     break;
 
   case 20:
 
 /* Line 1464 of yacc.c  */
-#line 164 "x-deltat.y"
+#line 165 "x-deltat.y"
     { if (HOUR_NOT_OK((yyvsp[(1) - (3)].val))) YYERROR;
 	                                  DO_SUM((yyval.val), (yyvsp[(1) - (3)].val) * 3600, (yyvsp[(3) - (3)].val)); ;}
     break;
@@ -1527,7 +1528,7 @@ yyreduce:
   case 22:
 
 /* Line 1464 of yacc.c  */
-#line 168 "x-deltat.y"
+#line 169 "x-deltat.y"
     { if (MIN_NOT_OK((yyvsp[(1) - (3)].val))) YYERROR;
 	                                  DO_SUM((yyval.val), (yyvsp[(1) - (3)].val) * 60, (yyvsp[(3) - (3)].val)); ;}
     break;
@@ -1535,14 +1536,14 @@ yyreduce:
   case 23:
 
 /* Line 1464 of yacc.c  */
-#line 171 "x-deltat.y"
+#line 172 "x-deltat.y"
     { (yyval.val) = 0; ;}
     break;
 
 
 
 /* Line 1464 of yacc.c  */
-#line 1546 "deltat.c"
+#line 1547 "deltat.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -1754,7 +1755,7 @@ yyreturn:
 
 
 /* Line 1684 of yacc.c  */
-#line 174 "x-deltat.y"
+#line 175 "x-deltat.y"
 
 
 #ifdef __GNUC__
