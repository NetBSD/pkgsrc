$NetBSD: patch-policy_backend_backend.l,v 1.1 2012/07/03 17:36:10 joerg Exp $

--- policy/backend/backend.l.orig	2008-08-06 08:24:59.000000000 +0000
+++ policy/backend/backend.l
@@ -33,6 +33,7 @@ namespace {
 %}
 %option noyywrap
 %option nounput
+%option noinput
 %option prefix="yy_policy_backend_parser"
 %option outfile="lex.yy_policy_backend_parser.cc"
 %option never-interactive
