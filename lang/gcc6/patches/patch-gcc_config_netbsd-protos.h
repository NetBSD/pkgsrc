$NetBSD: patch-gcc_config_netbsd-protos.h,v 1.1 2016/09/12 22:13:54 maya Exp $

--- /dev/null	2014-12-15 07:13:57.000000000 +0000
+++ gcc/config/netbsd-protos.h
@@ -0,0 +1,29 @@
+/* Prototypes.
+   Copyright (C) 2001-2014 Free Software Foundation, Inc.
+
+This file is part of GCC.
+
+GCC is free software; you can redistribute it and/or modify
+it under the terms of the GNU General Public License as published by
+the Free Software Foundation; either version 3, or (at your option)
+any later version.
+
+GCC is distributed in the hope that it will be useful,
+but WITHOUT ANY WARRANTY; without even the implied warranty of
+MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+GNU General Public License for more details.
+
+You should have received a copy of the GNU General Public License
+along with GCC; see the file COPYING3.  If not see
+<http://www.gnu.org/licenses/>.  */
+
+#ifndef _NETBSD_PROTOS_H_
+#define _NETBSD_PROTOS_H_
+
+double __c99_cabs (double complex);
+float __c99_cabsf (float complex);
+long double __c99_cabsl (long double complex);
+
+void netbsd_patch_builtins (void);
+
+#endif /* _NETBSD_PROTOS_H_ */
