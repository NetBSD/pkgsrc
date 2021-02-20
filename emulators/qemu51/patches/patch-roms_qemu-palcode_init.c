$NetBSD: patch-roms_qemu-palcode_init.c,v 1.1 2021/02/20 22:55:19 ryoon Exp $

- Don't include cross-host header files.
- Initialize the HWRPB CPU ID field with the WHAMI of the primary
  CPU (and not the CPU type) as per the architecture specification.
- Don't set the "PALcode memory valid" bit in the PCS flags; that field
  in the HWRPB is not initialized by this PALcode.
- Provide a Console Terminal Block (CTB) in the HWRPB - NetBSD requires
  it to find the console device.
- Define entry point register $a2 as a config word, rather than just a
  CPU count, and extract the "-nographic" option passed by Qemu, so that
  the CTB can be initialized properly.
- Call the SWPPAL with a private argument in $a4, to specify the value of
  $pv is to be after the SWPPAL has completed.
- When a secondary CPU starts up, extract a new value for $pv from the
  HWRPB "CPU restart data" field, and pass that to the SWPPAL operation
  used to trampiline to into the kernel entry point.

--- roms/qemu-palcode/init.c.orig	2020-10-03 23:12:30.442663290 +0000
+++ roms/qemu-palcode/init.c	2020-10-03 23:12:34.687159989 +0000
@@ -18,8 +18,6 @@
    along with this program; see the file COPYING.  If not see
    <http://www.gnu.org/licenses/>.  */
 
-#include <string.h>
-#include <stddef.h>
 #include "hwrpb.h"
 #include "osf.h"
 #include "ioport.h"
@@ -38,11 +36,21 @@
 
 #define HZ	1024
 
+/*
+ * Register a2 contains configuration information from the VM:
+ *
+ * bits 0-5 -- ncpus
+ * bit  6   -- "nographics" option
+ */
+#define	CONFIG_NCPUS(x)		((x) & 63)
+#define	CONFIG_NOGRAPHICS(x)	((x) & (1ull << 6))
+
 struct hwrpb_combine {
   struct hwrpb_struct hwrpb;
   struct percpu_struct processor[4];
   struct memdesc_struct md;
   struct memclust_struct mc[2];
+  struct ctb_struct ctb;
   struct crb_struct crb;
   struct procdesc_struct proc_dispatch;
   struct procdesc_struct proc_fixup;
@@ -61,6 +69,8 @@ struct hwrpb_combine hwrpb __attribute__
 
 void *last_alloc;
 bool have_vga;
+unsigned int pci_vga_bus;
+unsigned int pci_vga_dev;
 
 static void *
 alloc (unsigned long size, unsigned long align)
@@ -138,11 +148,13 @@ init_page_table(void)
 }
 
 static void
-init_hwrpb (unsigned long memsize, unsigned long cpus)
+init_hwrpb (unsigned long memsize, unsigned long config)
 {
   unsigned long pal_pages;
   unsigned long amask;
   unsigned long i;
+  unsigned long proc_type = EV4_CPU;
+  unsigned long cpus = CONFIG_NCPUS(config);
   
   hwrpb.hwrpb.phys_addr = PA(&hwrpb);
 
@@ -164,12 +176,12 @@ init_hwrpb (unsigned long memsize, unsig
   switch (__builtin_alpha_implver())
     {
     case 0: /* EV4 */
-      hwrpb.hwrpb.cpuid = EV4_CPU;
+      proc_type = EV4_CPU;
       hwrpb.hwrpb.max_asn = 63;
       break;
 
     case 1: /* EV5 */
-      hwrpb.hwrpb.cpuid
+      proc_type
 	= ((amask & 0x101) == 0x101 ? PCA56_CPU		/* MAX+BWX */
 	   : amask & 1 ? EV56_CPU			/* BWX */
 	   : EV5_CPU);
@@ -177,11 +189,12 @@ init_hwrpb (unsigned long memsize, unsig
       break;
 
     case 2: /* EV6 */
-      hwrpb.hwrpb.cpuid = (amask & 4 ? EV67_CPU : EV6_CPU);  /* CIX */
+      proc_type = (amask & 4 ? EV67_CPU : EV6_CPU);  /* CIX */
       hwrpb.hwrpb.max_asn = 255;
       break;
     }
 
+  hwrpb.hwrpb.cpuid = 0;	/* CPU #0 is the primary */
   hwrpb.hwrpb.pagesize = PAGE_SIZE;
   hwrpb.hwrpb.pa_bits = 40;
   hwrpb.hwrpb.sys_type = SYS_TYPE;
@@ -189,9 +202,20 @@ init_hwrpb (unsigned long memsize, unsig
   hwrpb.hwrpb.sys_revision = SYS_REVISION;
   for (i = 0; i < cpus; ++i)
     {
-      /* ??? Look up these bits.  Snagging the value examined by the kernel. */
-      hwrpb.processor[i].flags = 0x1cc;
-      hwrpb.processor[i].type = hwrpb.hwrpb.cpuid;
+      /*
+       * original value was 0x1cc ==
+       *	PALcode loaded       (0x100)
+       *	PALcode memory valid (0x080)
+       *	PALcode valid        (0x040)
+       *	processor present    (0x008)
+       *	processor available  (0x004)
+       *
+       * Don't set PALcode memory valid -- we don't initialize those PCS
+       * fields!
+       */
+      hwrpb.processor[i].flags = 0x14c;
+      hwrpb.processor[i].type = proc_type;
+      /* XXX hwrpb.processor[i].pal_revision */
     }
 
   hwrpb.hwrpb.intr_freq = HZ * 4096;
@@ -213,6 +237,21 @@ init_hwrpb (unsigned long memsize, unsig
   hwrpb.mc[1].start_pfn = pal_pages;
   hwrpb.mc[1].numpages = (memsize >> PAGE_SHIFT) - pal_pages;
 
+  hwrpb.hwrpb.ctbt_offset = offsetof(struct hwrpb_combine, ctb);
+  hwrpb.hwrpb.ctb_size = sizeof(hwrpb.ctb);
+  if (have_vga && !CONFIG_NOGRAPHICS(config))
+    {
+      printf("CTB: GRAPHICS PCI BUS %d DEV %d\r\n", pci_vga_bus, pci_vga_dev);
+      hwrpb.ctb.term_type = CTB_GRAPHICS;
+      hwrpb.ctb.turboslot = (CTB_TURBOSLOT_TYPE_PCI << 16) |
+                            (pci_vga_bus << 8) | pci_vga_dev;
+    }
+  else
+    {
+      printf("CTB: PRINTERPORT\r\n");
+      hwrpb.ctb.term_type = CTB_PRINTERPORT;
+    }
+
   hwrpb.hwrpb.crb_offset = offsetof(struct hwrpb_combine, crb);
   hwrpb.crb.dispatch_va = &hwrpb.proc_dispatch;
   hwrpb.crb.dispatch_pa = PA(&hwrpb.proc_dispatch);
@@ -260,7 +299,7 @@ init_i8259 (void)
   outb(0x01, PORT_PIC1_DATA);	/* ICW4 */
 
   /* Initialize level triggers.  The CY82C693UB that's on real alpha
-     hardware doesn't have this; this is a PIIX extension.  However,
+     hardware controls these differently; we assume a PIIX here.  However,
      QEMU doesn't implement regular level triggers.  */
   outb(0xff, PORT_PIC2_ELCR);
   outb(0xff, PORT_PIC1_ELCR);
@@ -275,32 +314,37 @@ init_i8259 (void)
 }
 
 static void __attribute__((noreturn))
-swppal(void *entry, void *pcb)
+swppal(void *entry, void *pcb, unsigned long vptptr, unsigned long pv)
 {
   register int variant __asm__("$16") = 2;	/* OSF/1 PALcode */
   register void *pc __asm__("$17") = entry;
   register unsigned long pa_pcb __asm__("$18") = PA(pcb);
-  register unsigned long vptptr __asm__("$19") = VPTPTR;
+  register unsigned long newvptptr __asm__("$19") = vptptr;
+  register unsigned long newpv __asm__("$20") = pv;
 
-  asm("call_pal 0x0a" : : "r"(variant), "r"(pc), "r"(pa_pcb), "r"(vptptr));
+  asm("call_pal 0x0a" : :
+      "r"(variant), "r"(pc), "r"(pa_pcb), "r"(newvptptr), "r"(newpv));
   __builtin_unreachable ();
 }
 
 void
-do_start(unsigned long memsize, void (*kernel_entry)(void), unsigned long cpus)
+do_start(unsigned long memsize, void (*kernel_entry)(void),
+         unsigned long config)
 {
   last_alloc = _end;
 
   init_page_table();
-  init_hwrpb(memsize, cpus);
   init_pcb();
   init_i8259();
   uart_init();
   ps2port_setup();
   pci_setup();
   vgahw_init();
+  init_hwrpb(memsize, config);
 
-  swppal(kernel_entry ? kernel_entry : do_console, &pcb);
+  void *new_pc = kernel_entry ? kernel_entry : do_console;
+
+  swppal(new_pc, &pcb, VPTPTR, (unsigned long)new_pc);
 }
 
 void
@@ -315,14 +359,16 @@ do_start_wait(unsigned long cpuid)
 	{
 	  /* ??? The only message I know of is "START\r\n".
 	     I can't be bothered to verify more than 4 characters.  */
-	  /* ??? The Linux kernel fills in, but does not require,
-	     CPU_restart_data.  It just sets that to the same address
-	     as CPU_restart itself.  Our swppal *does* put the PC into
-	     $26 and $27, the latter of which the kernel does rely upon.  */
+
+	  /* Use use a private extension to SWPPAL to get the
+	     CPU_restart_data into $27.  Linux fills it in, but does
+	     not require it. Other operating system, however,s do use
+	     CPU_restart_data as part of secondary CPU start-up.  */
 
 	  unsigned int len = hwrpb.processor[cpuid].ipc_buffer[0];
 	  unsigned int msg = hwrpb.processor[cpuid].ipc_buffer[1];
 	  void *CPU_restart = hwrpb.hwrpb.CPU_restart;
+	  unsigned long CPU_restart_data = hwrpb.hwrpb.CPU_restart_data;
 	  __sync_synchronize();
 	  hwrpb.hwrpb.rxrdy = 0;
 
@@ -330,7 +376,8 @@ do_start_wait(unsigned long cpuid)
 	    {
 	      /* Set bootstrap in progress */
 	      hwrpb.processor[cpuid].flags |= 1;
-	      swppal(CPU_restart, hwrpb.processor[cpuid].hwpcb);
+	      swppal(CPU_restart, hwrpb.processor[cpuid].hwpcb,
+		     hwrpb.hwrpb.vptb, CPU_restart_data);
 	    }
 	}
     }
