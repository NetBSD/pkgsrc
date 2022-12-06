$NetBSD: patch-gdb_ppc-nbsd-nat.c,v 1.1 2022/12/06 09:45:51 he Exp $

Use the updated / correct struct member names.

--- gdb/ppc-nbsd-nat.c.orig	2020-10-24 04:23:02.000000000 +0000
+++ gdb/ppc-nbsd-nat.c
@@ -167,19 +167,19 @@ ppcnbsd_supply_pcb (struct regcache *reg
     return 0;
 
   read_memory (pcb->pcb_sp, (gdb_byte *)&sf, sizeof sf);
-  regcache->raw_supply (tdep->ppc_cr_regnum, &sf.cr);
-  regcache->raw_supply (tdep->ppc_gp0_regnum + 2, &sf.fixreg2);
+  regcache->raw_supply (tdep->ppc_cr_regnum, &sf.sf_cr);
+  regcache->raw_supply (tdep->ppc_gp0_regnum + 2, &sf.sf_fixreg2);
   for (i = 0 ; i < 19 ; i++)
-    regcache->raw_supply (tdep->ppc_gp0_regnum + 13 + i, &sf.fixreg[i]);
+    regcache->raw_supply (tdep->ppc_gp0_regnum + 13 + i, &sf.sf_fixreg[i]);
 
-  read_memory(sf.sp, (gdb_byte *)&cf, sizeof(cf));
-  regcache->raw_supply (tdep->ppc_gp0_regnum + 30, &cf.r30);
-  regcache->raw_supply (tdep->ppc_gp0_regnum + 31, &cf.r31);
-  regcache->raw_supply (tdep->ppc_gp0_regnum + 1, &cf.sp);
-
-  read_memory(cf.sp, (gdb_byte *)&cf, sizeof(cf));
-  regcache->raw_supply (tdep->ppc_lr_regnum, &cf.lr);
-  regcache->raw_supply (gdbarch_pc_regnum (gdbarch), &cf.lr);
+  read_memory(sf.sf_sp, (gdb_byte *)&cf, sizeof(cf));
+  regcache->raw_supply (tdep->ppc_gp0_regnum + 30, &cf.cf_r30);
+  regcache->raw_supply (tdep->ppc_gp0_regnum + 31, &cf.cf_r31);
+  regcache->raw_supply (tdep->ppc_gp0_regnum + 1, &cf.cf_sp);
+
+  read_memory(cf.cf_sp, (gdb_byte *)&cf, sizeof(cf));
+  regcache->raw_supply (tdep->ppc_lr_regnum, &cf.cf_lr);
+  regcache->raw_supply (gdbarch_pc_regnum (gdbarch), &cf.cf_lr);
 
   return 1;
 }
