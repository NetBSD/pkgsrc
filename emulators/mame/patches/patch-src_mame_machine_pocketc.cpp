$NetBSD: patch-src_mame_machine_pocketc.cpp,v 1.1 2019/01/07 15:51:23 wiz Exp $

Fix compile.
https://github.com/mamedev/mame/commit/9592a18b11d708a1430f2684f3f70eef43372de0

--- src/mame/machine/pocketc.cpp.orig	2018-12-25 14:27:31.000000000 +0000
+++ src/mame/machine/pocketc.cpp
@@ -1,6 +1,7 @@
 // license:GPL-2.0+
 // copyright-holders:Peter Trauner
 
+#include "emu.h"
 #include "includes/pocketc.h"
 
 WRITE8_MEMBER(pocketc_state::out_a_w)
