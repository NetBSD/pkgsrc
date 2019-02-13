$NetBSD: patch-core_vcpu.c,v 1.1 2019/02/13 05:20:15 kamil Exp $

Cherry-pick from upstream review:
 - Fix FPU DNA exception on NetBSD
   https://github.com/intel/haxm/pull/168

--- core/vcpu.c.orig	2019-02-12 09:24:47.000000000 +0000
+++ core/vcpu.c
@@ -2041,6 +2041,10 @@ static void vcpu_enter_fpu_state(struct 
     struct fx_layout *hfx = (struct fx_layout *)hax_page_va(hstate->hfxpage);
     struct fx_layout *gfx = (struct fx_layout *)hax_page_va(gstate->gfxpage);
 
+    vcpu->cr0_ts = !!(get_cr0() & CR0_TS);
+
+    hax_clts();
+
     hax_fxsave((mword *)hfx);
     hax_fxrstor((mword *)gfx);
 }
@@ -2052,8 +2056,14 @@ static void vcpu_exit_fpu_state(struct v
     struct fx_layout *hfx = (struct fx_layout *)hax_page_va(hstate->hfxpage);
     struct fx_layout *gfx = (struct fx_layout *)hax_page_va(gstate->gfxpage);
 
+    hax_clts();
+
     hax_fxsave((mword *)gfx);
     hax_fxrstor((mword *)hfx);
+
+    if (vcpu->cr0_ts) {
+        set_cr0(get_cr0() | CR0_TS);
+    }
 }
 
 // Instructions are never longer than 15 bytes:
