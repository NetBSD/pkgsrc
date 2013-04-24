$NetBSD: patch-xen_arch_x86_cpu_mcheck_vmce.c,v 1.1.2.2 2013/04/24 22:25:48 tron Exp $

--- xen/arch/x86/cpu/mcheck/vmce.c.orig	2013-03-25 13:46:53.000000000 +0000
+++ xen/arch/x86/cpu/mcheck/vmce.c
@@ -39,7 +39,7 @@ int vmce_init_msr(struct domain *d)
         return -ENOMEM;
     }
     memset(dom_vmce(d)->mci_ctl, ~0,
-           sizeof(dom_vmce(d)->mci_ctl));
+           sizeof(*dom_vmce(d)->mci_ctl));
 
     dom_vmce(d)->mcg_status = 0x0;
     dom_vmce(d)->mcg_cap = g_mcg_cap;
@@ -369,7 +369,7 @@ static struct bank_entry* alloc_bank_ent
         return NULL;
     }
 
-    memset(entry, 0x0, sizeof(entry));
+    memset(entry, 0x0, sizeof(*entry));
     INIT_LIST_HEAD(&entry->list);
     return entry;
 }
@@ -451,7 +451,7 @@ int vmce_init(struct cpuinfo_x86 *c)
             return -ENOMEM;
         }
         /* Don't care banks before firstbank */
-        memset(h_mci_ctrl, 0xff, sizeof(h_mci_ctrl));
+        memset(h_mci_ctrl, 0xff, sizeof(*h_mci_ctrl));
         for (i = firstbank; i < nr_mce_banks; i++)
             rdmsrl(MSR_IA32_MCx_CTL(i), h_mci_ctrl[i]);
     }
