$NetBSD: patch-policy_policy.l,v 1.1 2012/07/03 17:36:10 joerg Exp $

--- policy/policy.l.orig	2008-08-06 08:25:49.000000000 +0000
+++ policy/policy.l
@@ -35,6 +35,7 @@ namespace {
 %option outfile="lex.yy_policy_parser.cc"
 %option noyywrap
 %option nounput
+%option noinput
 %option never-interactive
 %x STR
 
