$NetBSD: patch-libstdc++-v3_config_os_bsd_dragonfly_os__defines.h,v 1.1 2013/04/01 21:06:18 wiz Exp $

--- libstdc++-v3/config/os/bsd/dragonfly/os_defines.h.orig	2012-06-22 10:35:30.000000000 +0000
+++ libstdc++-v3/config/os/bsd/dragonfly/os_defines.h
@@ -0,0 +1,41 @@
+// Specific definitions for BSD  -*- C++ -*-
+
+// Copyright (C) 2000, 2009, 2010 Free Software Foundation, Inc.
+//
+// This file is part of the GNU ISO C++ Library.  This library is free
+// software; you can redistribute it and/or modify it under the
+// terms of the GNU General Public License as published by the
+// Free Software Foundation; either version 3, or (at your option)
+// any later version.
+
+// This library is distributed in the hope that it will be useful,
+// but WITHOUT ANY WARRANTY; without even the implied warranty of
+// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+// GNU General Public License for more details.
+
+// Under Section 7 of GPL version 3, you are granted additional
+// permissions described in the GCC Runtime Library Exception, version
+// 3.1, as published by the Free Software Foundation.
+
+// You should have received a copy of the GNU General Public License and
+// a copy of the GCC Runtime Library Exception along with this program;
+// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
+// <http://www.gnu.org/licenses/>.
+
+
+#ifndef _GLIBCXX_OS_DEFINES
+#define _GLIBCXX_OS_DEFINES 1
+
+// System-specific #define, typedefs, corrections, etc, go here.  This
+// file will come before all others.
+
+/*  FreeBSD approach, likely a mistake for DragonFly.
+#define _GLIBCXX_USE_C99_CHECK 1
+#define _GLIBCXX_USE_C99_DYNAMIC (!(__ISO_C_VISIBLE >= 1999))
+#define _GLIBCXX_USE_C99_LONG_LONG_CHECK 1
+#define _GLIBCXX_USE_C99_LONG_LONG_DYNAMIC (_GLIBCXX_USE_C99_DYNAMIC || !defined __LONG_LONG_SUPPORTED)
+#define _GLIBCXX_USE_C99_FLOAT_TRANSCENDENTALS_CHECK 1
+#define _GLIBCXX_USE_C99_FLOAT_TRANSCENDENTALS_DYNAMIC defined _XOPEN_SOURCE
+*/
+
+#endif
