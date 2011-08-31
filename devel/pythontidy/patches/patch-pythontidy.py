$NetBSD: patch-pythontidy.py,v 1.1 2011/08/31 11:43:17 apb Exp $

Replace hardcoded references to /usr/bin/python
with references to the pkgsrc python interpreter.
This patch changes /usr/bin/python to %PYTHONBIN%,
and the SUBST_STAGES.pythonbin rules in the Makefile
changes %PYTHONBIN% to the value of ${PYTHONBIN}.

--- pythontidy.py.orig	2011-08-31 11:00:17.000000000 +0000
+++ pythontidy.py
@@ -296,7 +296,7 @@ SUBSCRIPT_SEP = ', '
 DICT_COLON = ': '
 SLICE_COLON = ':'
 COMMENT_PREFIX = '# '  # 2007 May 25
-SHEBANG = '#!/usr/bin/python'
+SHEBANG = '#!%PYTHONBIN%'
 CODING = 'utf-8'
 CODING_SPEC = '# -*- coding: %s -*-' % CODING
 BOILERPLATE = NULL  # 2007 Mar 06
