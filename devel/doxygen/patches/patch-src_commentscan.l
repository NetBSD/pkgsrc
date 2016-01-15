$NetBSD: patch-src_commentscan.l,v 1.1 2016/01/15 18:04:06 tron Exp $

Fix build with flex 2.6.0.

--- src/commentscan.l.orig	2014-12-22 14:01:20.000000000 +0000
+++ src/commentscan.l	2016-01-15 14:17:37.661978862 +0000
@@ -1098,11 +1098,7 @@
 					      // but we need to know the position in the input buffer where this 
 					      // rule matched.
 					      // for flex 2.5.33+ we should use YY_CURRENT_BUFFER_LVALUE
-#if YY_FLEX_MINOR_VERSION>=5 && YY_FLEX_SUBMINOR_VERSION>=33
 					      inputPosition=prevPosition + (int)(yy_bp - YY_CURRENT_BUFFER_LVALUE->yy_ch_buf);
-#else
-					      inputPosition=prevPosition + (int)(yy_bp - yy_current_buffer->yy_ch_buf);
-#endif
 					      yyterminate();
 					    }
 					    else if (cmdPtr->func==0)
@@ -1160,11 +1156,7 @@
                                           g_memberGroupHeader.resize(0);
 					  parseMore=TRUE;
                                           needNewEntry = TRUE;
-#if YY_FLEX_MINOR_VERSION>=5 && YY_FLEX_SUBMINOR_VERSION>=33
 				          inputPosition=prevPosition + (int)(yy_bp - YY_CURRENT_BUFFER_LVALUE->yy_ch_buf) + strlen(yytext);
-#else
-				          inputPosition=prevPosition + (int)(yy_bp - yy_current_buffer->yy_ch_buf) + strlen(yytext);
-#endif
 					  yyterminate();
                                         }
 <Comment>{B}*{CMD}[$@\\&~<>#%]		{ // escaped character
