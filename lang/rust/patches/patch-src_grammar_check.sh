$NetBSD: patch-src_grammar_check.sh,v 1.1 2017/02/23 09:35:16 jperkin Exp $

Shell portability fix.

--- src/grammar/check.sh.orig	2017-02-09 01:37:48.000000000 +0000
+++ src/grammar/check.sh
@@ -9,7 +9,7 @@
 # Argument $1 is the file to check, $2 is the classpath to use, $3 is the path
 # to the grun binary, $4 is the path to the verify binary, $5 is the path to
 # RustLexer.tokens
-if [ "${VERBOSE}" == "1" ]; then
+if [ "${VERBOSE}" = "1" ]; then
     set -x
 fi
 
