$NetBSD: patch-gcc_config_i386_dragonfly64.h,v 1.1 2013/05/20 05:47:34 adam Exp $

DragonFly BSD support.

--- ../gcc-4.1.2/gcc/config/i386/dragonfly64.h.orig	2013-05-19 08:54:10.000000000 +0000
+++ ../gcc-4.1.2/gcc/config/i386/dragonfly64.h
@@ -0,0 +1,45 @@
+/* Definitions for AMD x86-64 running DragonFly with ELF format
+   Copyright (C) 2002, 2004 Free Software Foundation, Inc.
+   Contributed by David O'Brien <obrien@FreeBSD.org>
+
+This file is part of GCC.
+
+GCC is free software; you can redistribute it and/or modify
+it under the terms of the GNU General Public License as published by
+the Free Software Foundation; either version 2, or (at your option)
+any later version.
+
+GCC is distributed in the hope that it will be useful,
+but WITHOUT ANY WARRANTY; without even the implied warranty of
+MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+GNU General Public License for more details.
+
+You should have received a copy of the GNU General Public License
+along with GCC; see the file COPYING.  If not, write to
+the Free Software Foundation, 59 Temple Place - Suite 330,
+Boston, MA 02111-1307, USA.  */
+
+
+#undef  TARGET_VERSION
+#define TARGET_VERSION fprintf (stderr, " (DragonFly/x86-64 ELF)");
+
+#define SUBTARGET_EXTRA_SPECS \
+  { "dfly_dynamic_linker", DFLY_DYNAMIC_LINKER }
+
+/* Provide a LINK_SPEC appropriate for the DragonFly/x86-64 ELF target.
+   This is a copy of LINK_SPEC from <i386/freebsd.h> tweaked for
+   the x86-64 target.  */
+
+#undef	LINK_SPEC
+#define LINK_SPEC "\
+  %{m32:-m elf_i386_fbsd} \
+  %{Wl,*:%*} \
+  %{v:-V} \
+  %{assert*} %{R*} %{rpath*} %{defsym*} \
+  %{shared:-Bshareable %{h*} %{soname*}} \
+    %{!shared: \
+      %{!static: \
+        %{rdynamic:-export-dynamic} \
+	%{!dynamic-linker:-dynamic-linker %(dfly_dynamic_linker) }} \
+    %{static:-Bstatic}} \
+  %{symbolic:-Bsymbolic}"
