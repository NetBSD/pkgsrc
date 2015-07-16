$NetBSD: patch-gcc_config_netbsd.c,v 1.1 2015/07/16 12:03:36 ryoon Exp $

--- /dev/null	2015-01-20 20:33:39.000000000 +0000
+++ gcc/config/netbsd.c
@@ -0,0 +1,122 @@
+/* Functions for generic NetBSD as target machine for GNU C compiler.
+   Copyright (C) 1989-2014 Free Software Foundation, Inc.
+   Contributed by Apple Computer Inc.
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
+
+#include "config.h"
+#include "system.h"
+#include "coretypes.h"
+#include "tm.h"
+#include "rtl.h"
+#include "regs.h"
+#include "hard-reg-set.h"
+#include "insn-config.h"
+#include "conditions.h"
+#include "insn-flags.h"
+#include "output.h"
+#include "insn-attr.h"
+#include "flags.h"
+#include "hash-set.h"
+#include "machmode.h"
+#include "vec.h"
+#include "double-int.h"
+#include "input.h"
+#include "alias.h"
+#include "symtab.h"
+#include "wide-int.h"
+#include "inchash.h"
+#include "tree.h"
+#include "fold-const.h"
+#include "stringpool.h"
+#include "varasm.h"
+#include "stor-layout.h"
+#include "hashtab.h"
+#include "function.h"
+#include "statistics.h"
+#include "real.h"
+#include "fixed-value.h"
+#include "expmed.h"
+#include "dojump.h"
+#include "explow.h"
+#include "calls.h"
+#include "emit-rtl.h"
+#include "stmt.h"
+#include "expr.h"
+#include "reload.h"
+#include "ggc.h"
+#include "langhooks.h"
+#include "target.h"
+#include "tm_p.h"
+#include "diagnostic-core.h"
+#include "toplev.h"
+#include "dominance.h"
+#include "cfg.h"
+#include "cfgrtl.h"
+#include "cfganal.h"
+#include "lcm.h"
+#include "cfgbuild.h"
+#include "cfgcleanup.h"
+#include "predict.h"
+#include "basic-block.h"
+#include "df.h"
+#include "debug.h"
+#include "obstack.h"
+#include "hash-table.h"
+#include "tree-ssa-alias.h"
+#include "internal-fn.h"
+#include "gimple-fold.h"
+#include "tree-eh.h"
+#include "gimple-expr.h"
+#include "is-a.h"
+#include "gimple.h"
+#include "gimplify.h"
+#include "hash-map.h"
+#include "plugin-api.h"
+#include "ipa-ref.h"
+#include "cgraph.h"
+#include "lto-streamer.h"
+#include "lto-section-names.h"
+
+static void
+netbsd_patch_builtin (enum built_in_function fncode)
+{
+  tree fn = builtin_decl_explicit (fncode);
+  tree sym;
+  char *newname;
+
+  if (!fn)
+    return;
+
+  sym = DECL_ASSEMBLER_NAME (fn);
+  newname = ACONCAT (("__c99_", IDENTIFIER_POINTER (sym), NULL));
+
+  set_user_assembler_name (fn, newname);
+
+  fn = builtin_decl_implicit (fncode);
+  if (fn)
+    set_user_assembler_name (fn, newname);
+}
+
+void
+netbsd_patch_builtins (void)
+{
+  netbsd_patch_builtin (BUILT_IN_CABSF);
+  netbsd_patch_builtin (BUILT_IN_CABS);
+  netbsd_patch_builtin (BUILT_IN_CABSL);
+}
