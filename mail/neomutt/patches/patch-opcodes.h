$NetBSD: patch-opcodes.h,v 1.1 2020/04/17 18:01:34 wiz Exp $

ensure OP_NULL is always first

A recent refactoring altered the ordering of the OPs when autocrypt was
enabled.  This mean that OP_NULL wasn't 0 any more.

Fixes: #2268

https://github.com/neomutt/neomutt/commit/9e7537caddb9c6adc720bb3322a7512cf51ab025

--- opcodes.h.orig	2020-04-17 11:53:50.000000000 +0000
+++ opcodes.h
@@ -37,7 +37,6 @@
 #endif
 
 #define OPS_CORE(_fmt) \
-  _fmt(OP_NULL,                           N_("null operation")) \
   _fmt(OP_ATTACH_COLLAPSE,                N_("toggle display of subparts")) \
   _fmt(OP_ATTACH_VIEW_MAILCAP,            N_("force viewing of attachment using mailcap")) \
   _fmt(OP_ATTACH_VIEW_TEXT,               N_("view attachment as text")) \
@@ -317,6 +316,7 @@
   _fmt(OP_COMPOSE_SMIME_MENU,             N_("show S/MIME options")) \
 
 #define OPS(_fmt) \
+  _fmt(OP_NULL,                           N_("null operation")) \
   OPS_AUTOCRYPT(_fmt) \
   OPS_CORE(_fmt) \
   OPS_SIDEBAR(_fmt) \
