$NetBSD: patch-src_scanner.c,v 1.1 2014/12/20 21:04:32 wiz Exp $

Fix CVE-2014-9130:
https://bitbucket.org/xi/libyaml/commits/2b9156756423e967cfd09a61d125d883fca6f4f2

--- src/scanner.c.orig	2014-03-26 18:54:02.000000000 +0000
+++ src/scanner.c
@@ -1106,13 +1106,6 @@ yaml_parser_save_simple_key(yaml_parser_
             && parser->indent == (ptrdiff_t)parser->mark.column);
 
     /*
-     * A simple key is required only when it is the first token in the current
-     * line.  Therefore it is always allowed.  But we add a check anyway.
-     */
-
-    assert(parser->simple_key_allowed || !required);    /* Impossible. */
-
-    /*
      * If the current position may start a simple key, save it.
      */
 
