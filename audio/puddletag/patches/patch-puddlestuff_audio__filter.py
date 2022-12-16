$NetBSD: patch-puddlestuff_audio__filter.py,v 1.1 2022/12/16 17:49:09 wiz Exp $

Stop using deprecated function.
https://github.com/puddletag/puddletag/issues/643

--- puddlestuff/audio_filter.py.orig	2020-08-29 13:19:47.992420700 +0000
+++ puddlestuff/audio_filter.py
@@ -180,7 +180,7 @@ bool_exprs = [
 field_expr = Combine('%' + Word(alphanums + '_') + '%')
 tokens = QuotedString('"', unquoteResults=False) \
          | field_expr | Word(alphanums + '_')
-bool_expr = operatorPrecedence(tokens, bool_exprs)
+bool_expr = infixNotation(tokens, bool_exprs)
 bool_expr.enablePackrat()
 
 
