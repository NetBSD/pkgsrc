$NetBSD: patch-tools_xentrace_xenalyze.c,v 1.1 2017/02/14 21:38:34 joerg Exp $

Based on 28ab9f3d0e7cbb22f5ce77500af7873f6e2d3c59.

--- tools/xentrace/xenalyze.c.orig	2016-06-20 12:08:22.000000000 +0000
+++ tools/xentrace/xenalyze.c
@@ -509,7 +509,6 @@ struct {
 #define HVM_VMX_EXIT_REASON_MAX (EXIT_REASON_XSETBV+1)
 
 char * hvm_vmx_exit_reason_name[HVM_VMX_EXIT_REASON_MAX] = {
-    [0] = "NONE",
     [EXIT_REASON_EXCEPTION_NMI]="EXCEPTION_NMI",
     [EXIT_REASON_EXTERNAL_INTERRUPT]="EXTERNAL_INTERRUPT",
     [EXIT_REASON_TRIPLE_FAULT]="TRIPLE_FAULT",
@@ -2262,11 +2261,6 @@ static inline void update_summary(struct
     s->count++;
 }
 
-static inline void clear_interval_summary(struct event_cycle_summary *s) {
-    s->interval.count = 0;
-    s->interval.cycles = 0;
-}
-
 static inline void update_cycles(struct cycle_summary *s, long long c) {
 /* We don't know ahead of time how many samples there are, and working
  * with dynamic stuff is a pain, and unnecessary.  This algorithm will
@@ -2314,6 +2308,7 @@ static inline void clear_interval_cycles
     e->instructions = 0;
 }
 
+#if 0
 static inline void update_cpi(struct weighted_cpi_summary *s,
                               unsigned long long i,
                               unsigned long long c) {
@@ -2359,6 +2354,7 @@ static inline void clear_interval_cpi(st
     s->interval.count = 0;
     s->interval.instructions = 0;
 }
+#endif
 
 static inline void print_cpu_affinity(struct cycle_summary *s, char *p) {
     if(s->count) {
@@ -2639,6 +2635,23 @@ void interval_cr3_value_check(struct cr3
     }
 }
 
+int cr3_time_compare(const void *_a, const void *_b) {
+    struct cr3_value_struct *a=*(typeof(&a))_a;
+    struct cr3_value_struct *b=*(typeof(&a))_b;
+
+    if(a->total_time.interval.cycles < b->total_time.interval.cycles)
+        return 1;
+    else if(b->total_time.interval.cycles == a->total_time.interval.cycles) {
+        if(a->total_time.interval.count < b->total_time.interval.count)
+            return 1;
+        else if(a->total_time.interval.count == b->total_time.interval.count)
+            return 0;
+        else
+            return -1;
+    } else
+        return -1;
+}
+
 void interval_cr3_schedule_ordered_output(void) {
     struct cr3_value_struct *p;
     int i;
@@ -2646,23 +2659,6 @@ void interval_cr3_schedule_ordered_outpu
     struct cr3_value_struct **qsort_array;
     int N=0;
 
-    int cr3_time_compare(const void *_a, const void *_b) {
-        struct cr3_value_struct *a=*(typeof(&a))_a;
-        struct cr3_value_struct *b=*(typeof(&a))_b;
-
-        if(a->total_time.interval.cycles < b->total_time.interval.cycles)
-            return 1;
-        else if(b->total_time.interval.cycles == a->total_time.interval.cycles) {
-            if(a->total_time.interval.count < b->total_time.interval.count)
-                return 1;
-            else if(a->total_time.interval.count == b->total_time.interval.count)
-                return 0;
-            else
-                return -1;
-        } else
-            return -1;
-    }
-
     for(p=P.cr3.head; p; p=p->gnext)
         N++;
 
@@ -2958,6 +2954,23 @@ void update_eip(struct eip_list_struct *
     update_summary(&p->summary, cycles);
 }
 
+int eip_compare(const void *_a, const void *_b) {
+    struct eip_list_struct *a=*(typeof(&a))_a;
+    struct eip_list_struct *b=*(typeof(&a))_b;
+
+    if(a->summary.cycles < b->summary.cycles)
+        return 1;
+    else if(b->summary.cycles == a->summary.cycles) {
+        if(a->summary.count < b->summary.count)
+            return 1;
+        else if(a->summary.count == b->summary.count)
+            return 0;
+        else
+            return -1;
+    } else
+        return -1;
+}
+
 void dump_eip(struct eip_list_struct *head) {
     struct eip_list_struct *p;
     int i;
@@ -2966,23 +2979,6 @@ void dump_eip(struct eip_list_struct *he
     struct eip_list_struct **qsort_array;
     int N=0;
 
-    int eip_compare(const void *_a, const void *_b) {
-        struct eip_list_struct *a=*(typeof(&a))_a;
-        struct eip_list_struct *b=*(typeof(&a))_b;
-
-        if(a->summary.cycles < b->summary.cycles)
-            return 1;
-        else if(b->summary.cycles == a->summary.cycles) {
-            if(a->summary.count < b->summary.count)
-                return 1;
-            else if(a->summary.count == b->summary.count)
-                return 0;
-            else
-                return -1;
-        } else
-            return -1;
-    }
-
     for(p=head; p; p=p->next)
     {
         total += p->summary.count;
@@ -3549,6 +3545,50 @@ struct outstanding_ipi *find_vec(struct 
     return o;
 }
 
+void ipi_send(struct vcpu_data *ov, int vec)
+{
+    struct vlapic_struct *vla;
+    struct outstanding_ipi *o = NULL;
+
+    if(ov->runstate.state == RUNSTATE_LOST) {
+        if(opt.dump_all)
+            fprintf(warn, "%s: v%d in state RUNSTATE_LOST, not counting ipi\n",
+                    __func__, ov->vid);
+        return;
+    }
+
+    vla = &ov->vlapic;
+
+    o = find_vec(vla, vec);
+
+    if(!o)
+    {
+        fprintf(warn, "%s: Couldn't find an open slot!\n",
+                __func__);
+        return;
+    }
+
+    if(!o->first_tsc)
+        o->first_tsc = P.now;
+
+    if(opt.dump_all && o->count == 0 && o->injected)
+        printf(" [vla] Pre-injection\n");
+
+    o->count++;
+
+    if((opt.dump_all)
+#if 0
+       && (ov->runstate.state != RUNSTATE_RUNNING
+           || ov->hvm.vmexit_valid)
+#endif
+        )
+        printf(" [vla] d%dv%d vec %d state %s (outstanding ipis %d)\n",
+               ov->d->did, ov->vid,
+               o->vec,
+               runstate_name[ov->runstate.state],
+               o->count);
+}
+
 void hvm_vlapic_icr_handler(struct hvm_data *h)
 {
     struct mmio_info *m = &h->inflight.mmio;
@@ -3567,50 +3607,6 @@ void hvm_vlapic_icr_handler(struct hvm_d
         };
     } icr = { .val = m->data };
 
-    void ipi_send(struct vcpu_data *ov, int vec)
-    {
-        struct vlapic_struct *vla;
-        struct outstanding_ipi *o = NULL;
-
-        if(ov->runstate.state == RUNSTATE_LOST) {
-            if(opt.dump_all)
-                fprintf(warn, "%s: v%d in state RUNSTATE_LOST, not counting ipi\n",
-                        __func__, ov->vid);
-            return;
-        }
-
-        vla = &ov->vlapic;
-
-        o = find_vec(vla, vec);
-
-        if(!o)
-        {
-            fprintf(warn, "%s: Couldn't find an open slot!\n",
-                    __func__);
-            return;
-        }
-
-        if(!o->first_tsc)
-            o->first_tsc = P.now;
-
-        if(opt.dump_all && o->count == 0 && o->injected)
-            printf(" [vla] Pre-injection\n");
-
-        o->count++;
-
-        if((opt.dump_all)
-#if 0
-           && (ov->runstate.state != RUNSTATE_RUNNING
-               || ov->hvm.vmexit_valid)
-#endif
-            )
-            printf(" [vla] d%dv%d vec %d state %s (outstanding ipis %d)\n",
-                   ov->d->did, ov->vid,
-                   o->vec,
-                   runstate_name[ov->runstate.state],
-                   o->count);
-    }
-
     if(m->is_write) {
         if(opt.dump_all) {
             printf("              [vla] d%dv%d icr vec %d %s\n",
@@ -4116,11 +4112,6 @@ void cr3_prealloc_unpin(struct vcpu_data
                gmfn, cr3->prealloc_unpin.count);
 }
 
-void cr3_dump_list(struct cr3_value_struct *head){
-    struct cr3_value_struct *p;
-    struct cr3_value_struct **qsort_array;
-    int i, N=0;
-
     int cr3_compare_total(const void *_a, const void *_b) {
         struct cr3_value_struct *a=*(typeof(&a))_a;
         struct cr3_value_struct *b=*(typeof(&a))_b;
@@ -4150,6 +4141,11 @@ void cr3_dump_list(struct cr3_value_stru
             return -1;
     }
 
+void cr3_dump_list(struct cr3_value_struct *head){
+    struct cr3_value_struct *p;
+    struct cr3_value_struct **qsort_array;
+    int i, N=0;
+
     if(!head)
         return;
 
