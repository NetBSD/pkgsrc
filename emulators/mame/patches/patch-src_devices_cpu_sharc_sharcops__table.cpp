$NetBSD: patch-src_devices_cpu_sharc_sharcops__table.cpp,v 1.1 2026/01/30 13:39:49 wiz Exp $

https://github.com/mamedev/mame/commit/ffde4d3920ae99d2730db83982ffa9f8fbd8abd2

--- src/devices/cpu/sharc/sharcops_table.cpp.orig	2026-01-29 15:02:37.000000000 +0000
+++ src/devices/cpu/sharc/sharcops_table.cpp
@@ -1,5 +1,7 @@
 // license:BSD-3-Clause
 // copyright-holders:Ville Linde
+
+#include "emu.h"
 #include "sharc.h"
 
 const adsp21062_device::SHARC_OP adsp21062_device::s_sharc_opcode_table[] =
