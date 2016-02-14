$NetBSD: patch-xpcom_reflect_xptcall_md_unix_xptcinvoke__arm__netbsd.cpp,v 1.1 2016/02/14 07:30:54 ryoon Exp $

--- xpcom/reflect/xptcall/md/unix/xptcinvoke_arm_netbsd.cpp.orig	2014-11-13 22:50:21.000000000 +0000
+++ xpcom/reflect/xptcall/md/unix/xptcinvoke_arm_netbsd.cpp
@@ -7,82 +7,92 @@
 
 #include "xptcprivate.h"
 
-// Remember that these 'words' are 32bit DWORDS
+#include "mozilla/Compiler.h"
 
-static uint32_t
-invoke_count_words(uint32_t paramCount, nsXPTCVariant* s)
+#ifndef __ARM_PCS_VFP
+
+/* This function copies a 64-bits word from dw to the given pointer in
+ * a buffer delimited by start and end, possibly wrapping around the
+ * buffer boundaries, and/or properly aligning the data at 64-bits word
+ * boundaries (for EABI).
+ * start and end are both assumed to be 64-bits aligned.
+ * Returns a pointer to the second 32-bits word copied (to accomodate
+ * the invoke_copy_to_stack loop).
+ */
+static uint32_t *
+copy_double_word(uint32_t *start, uint32_t *current, uint32_t *end, uint64_t *dw)
 {
-    uint32_t result = 0;
-    for(uint32_t i = 0; i < paramCount; i++, s++)
-    {
-        if(s->IsPtrData())
-        {
-            result++;
-            continue;
-        }
-        switch(s->type)
-        {
-        case nsXPTType::T_I8     :
-        case nsXPTType::T_I16    :
-        case nsXPTType::T_I32    :
-            result++;
-            break;
-        case nsXPTType::T_I64    :
-            result+=2;
-            break;
-        case nsXPTType::T_U8     :
-        case nsXPTType::T_U16    :
-        case nsXPTType::T_U32    :
-            result++;
-            break;
-        case nsXPTType::T_U64    :
-            result+=2;
-            break;
-        case nsXPTType::T_FLOAT  :
-            result++;
-            break;
-        case nsXPTType::T_DOUBLE :
-            result+=2;
-            break;
-        case nsXPTType::T_BOOL   :
-        case nsXPTType::T_CHAR   :
-        case nsXPTType::T_WCHAR  :
-            result++;
-            break;
-        default:
-            // all the others are plain pointer types
-            result++;
-            break;
-        }
+#ifdef __ARM_EABI__
+    /* Aligning the pointer for EABI */
+    current = (uint32_t *)(((uint32_t)current + 7) & ~7);
+    /* Wrap when reaching the end of the buffer */
+    if (current == end) current = start;
+#else
+    /* On non-EABI, 64-bits values are not aligned and when we reach the end
+     * of the buffer, we need to write half of the data at the end, and the
+     * other half at the beginning. */
+    if (current == end - 1) {
+        *current = ((uint32_t*)dw)[0];
+        *start = ((uint32_t*)dw)[1];
+        return start;
     }
-    return result;
+#endif
+
+    *((uint64_t*) current) = *dw;
+    return current + 1;
 }
 
-static void
-invoke_copy_to_stack(uint32_t* d, uint32_t paramCount, nsXPTCVariant* s)
+/* See stack_space comment in NS_InvokeByIndex to see why this needs not to
+ * be static on DEBUG builds. */
+#ifndef DEBUG
+static
+#endif
+void
+invoke_copy_to_stack(uint32_t* stk, uint32_t *end,
+                     uint32_t paramCount, nsXPTCVariant* s)
 {
+    /* The stack buffer is 64-bits aligned. The end argument points to its end.
+     * The caller is assumed to create a stack buffer of at least four 32-bits
+     * words.
+     * We use the last three 32-bit words to store the values for r1, r2 and r3
+     * for the method call, i.e. the first words for arguments passing.
+     */
+    uint32_t *d = end - 3;
     for(uint32_t i = 0; i < paramCount; i++, d++, s++)
     {
+        /* Wrap when reaching the end of the stack buffer */
+        if (d == end) d = stk;
+        NS_ASSERTION(d >= stk && d < end,
+            "invoke_copy_to_stack is copying outside its given buffer");
         if(s->IsPtrData())
         {
             *((void**)d) = s->ptr;
             continue;
         }
+        // According to the ARM EABI, integral types that are smaller than a word
+        // are to be sign/zero-extended to a full word and treated as 4-byte values.
+
         switch(s->type)
         {
-        case nsXPTType::T_I8     : *((int8_t*)  d) = s->val.i8;          break;
-        case nsXPTType::T_I16    : *((int16_t*) d) = s->val.i16;         break;
+        case nsXPTType::T_I8     : *((int32_t*) d) = s->val.i8;          break;
+        case nsXPTType::T_I16    : *((int32_t*) d) = s->val.i16;         break;
         case nsXPTType::T_I32    : *((int32_t*) d) = s->val.i32;         break;
-        case nsXPTType::T_I64    : *((int64_t*) d) = s->val.i64; d++;    break;
-        case nsXPTType::T_U8     : *((uint8_t*) d) = s->val.u8;          break;
-        case nsXPTType::T_U16    : *((uint16_t*)d) = s->val.u16;         break;
+        case nsXPTType::T_I64    :
+            d = copy_double_word(stk, d, end, (uint64_t *)&s->val.i64);
+            break;
+        case nsXPTType::T_U8     : *((uint32_t*)d) = s->val.u8;          break;
+        case nsXPTType::T_U16    : *((uint32_t*)d) = s->val.u16;         break;
         case nsXPTType::T_U32    : *((uint32_t*)d) = s->val.u32;         break;
-        case nsXPTType::T_U64    : *((uint64_t*)d) = s->val.u64; d++;    break;
+        case nsXPTType::T_U64    :
+            d = copy_double_word(stk, d, end, (uint64_t *)&s->val.u64);
+            break;
         case nsXPTType::T_FLOAT  : *((float*)   d) = s->val.f;           break;
-        case nsXPTType::T_DOUBLE : *((double*)  d) = s->val.d;   d++;    break;
-        case nsXPTType::T_BOOL   : *((bool*)  d) = s->val.b;           break;
-        case nsXPTType::T_CHAR   : *((char*)    d) = s->val.c;           break;
-        case nsXPTType::T_WCHAR  : *((wchar_t*) d) = s->val.wc;          break;
+        case nsXPTType::T_DOUBLE :
+            d = copy_double_word(stk, d, end, (uint64_t *)&s->val.d);
+            break;
+        case nsXPTType::T_BOOL   : *((int32_t*) d) = s->val.b;           break;
+        case nsXPTType::T_CHAR   : *((int32_t*) d) = s->val.c;           break;
+        case nsXPTType::T_WCHAR  : *((int32_t*) d) = s->val.wc;          break;
         default:
             // all the others are plain pointer types
             *((void**)d) = s->val.p;
@@ -91,47 +101,27 @@ invoke_copy_to_stack(uint32_t* d, uint32
     }
 }
 
-extern "C" 
-struct my_params_struct {
-    nsISupports* that;      
-    uint32_t Index;         
-    uint32_t Count;         
-    nsXPTCVariant* params;  
-    uint32_t fn_count;     
-    uint32_t fn_copy;      
-};
+typedef nsresult (*vtable_func)(nsISupports *, uint32_t, uint32_t, uint32_t);
 
-XPTC_PUBLIC_API(nsresult)
-XPTC_InvokeByIndex(nsISupports* that, uint32_t methodIndex,
+EXPORT_XPCOM_API(nsresult)
+NS_InvokeByIndex(nsISupports* that, uint32_t methodIndex,
                    uint32_t paramCount, nsXPTCVariant* params)
 {
-    uint32_t result;
-    struct my_params_struct my_params;
-    my_params.that = that;
-    my_params.Index = methodIndex;
-    my_params.Count = paramCount;
-    my_params.params = params;
-    my_params.fn_copy = (uint32_t) &invoke_copy_to_stack;
-    my_params.fn_count = (uint32_t) &invoke_count_words;
 
 /* This is to call a given method of class that.
  * The parameters are in params, the number is in paramCount.
  * The routine will issue calls to count the number of words
  * required for argument passing and to copy the arguments to
  * the stack.
- * Since APCS passes the first 3 params in r1-r3, we need to
- * load the first three words from the stack and correct the stack
- * pointer (sp) in the appropriate way. This means:
- *
- * 1.) more than 3 arguments: load r1-r3, correct sp and remember No.
- *			      of bytes left on the stack in r4
- *
- * 2.) <= 2 args: load r1-r3 (we won't be causing a stack overflow I hope),
- *		  restore sp as if nothing had happened and set the marker r4 to zero.
- *
- * Afterwards sp will be restored using the value in r4 (which is not a temporary register
- * and will be preserved by the function/method called according to APCS [ARM Procedure
- * Calling Standard]).
+ * ACPS passes the first 3 params in r1-r3 (with exceptions for 64-bits
+ * arguments), and the remaining goes onto the stack.
+ * We allocate a buffer on the stack for a "worst case" estimate of how much
+ * stack might be needed for EABI, i.e. twice the number of parameters.
+ * The end of this buffer will be used to store r1 to r3, so that the start
+ * of the stack is the remaining parameters.
+ * The magic here is to call the method with "that" and three 32-bits
+ * arguments corresponding to r1-r3, so that the compiler generates the
+ * proper function call. The stack will also contain the remaining arguments.
  *
  * !!! IMPORTANT !!!
  * This routine makes assumptions about the vtable layout of the c++ compiler. It's implemented
@@ -139,43 +129,272 @@ XPTC_InvokeByIndex(nsISupports* that, ui
  *
  */
  
-  __asm__ __volatile__(
-    "ldr	r1, [%1, #12]	\n\t"	/* prepare to call invoke_count_words	*/
-    "ldr	ip, [%1, #16]	\n\t"	/* r0=paramCount, r1=params		*/
-    "ldr	r0, [%1,  #8]	\n\t"
-    "mov	lr, pc		\n\t"	/* call it...				*/
-    "mov	pc, ip		\n\t"
-    "mov	r4, r0, lsl #2	\n\t"	/* This is the amount of bytes needed.	*/
-    "sub	sp, sp, r4	\n\t"	/* use stack space for the args...	*/
-    "mov	r0, sp		\n\t"	/* prepare a pointer an the stack	*/
-    "ldr	r1, [%1,  #8]	\n\t"	/* =paramCount				*/
-    "ldr	r2, [%1, #12]	\n\t"	/* =params				*/
-    "ldr	ip, [%1, #20]	\n\t"	/* =invoke_copy_to_stack		*/
-    "mov	lr, pc		\n\t"	/* copy args to the stack like the	*/
-    "mov	pc, ip		\n\t"	/* compiler would.			*/
-    "ldr	r0, [%1]	\n\t"	/* =that				*/
-    "ldr	r1, [r0, #0]	\n\t"	/* get that->vtable offset		*/
-    "ldr	r2, [%1, #4]	\n\t"
-    "add	r2, r1, r2, lsl #3\n\t"	/* a vtable_entry(x)=8 + (8 bytes * x)	*/
-    "add	r2, r2, #8	\n\t"	/* with this compilers			*/
-    "ldr	r3, [r2]	\n\t"	/* get virtual offset from vtable	*/
-    "mov	r3, r3, lsl #16	\n\t"
-    "add	r0, r0, r3, asr #16\n\t"
-    "ldr	ip, [r2, #4]	\n\t"	/* get method address from vtable	*/
-    "cmp	r4, #12		\n\t"	/* more than 3 arguments???		*/
-    "ldmgtia	sp!, {r1, r2, r3}\n\t"	/* yes: load arguments for r1-r3	*/
-    "subgt	r4, r4, #12	\n\t"	/*      and correct the stack pointer	*/
-    "ldmleia	sp, {r1, r2, r3}\n\t"	/* no:  load r1-r3 from stack		*/ 
-    "addle	sp, sp, r4	\n\t"	/*      and restore stack pointer	*/
-    "movle	r4, #0		\n\t"	/*	a mark for restoring sp		*/
-    "mov	lr, pc		\n\t"	/* call mathod				*/
-    "mov	pc, ip		\n\t"
-    "add	sp, sp, r4	\n\t"	/* restore stack pointer		*/
-    "mov	%0, r0		\n\t"	/* the result...			*/
-    : "=r" (result)
-    : "r" (&my_params)
-    : "r0", "r1", "r2", "r3", "r4", "ip", "lr"
-    );
-    
-  return result;
+  vtable_func *vtable, func;
+  int base_size = (paramCount > 1) ? paramCount : 2;
+
+/* !!! IMPORTANT !!!
+ * On DEBUG builds, the NS_ASSERTION used in invoke_copy_to_stack needs to use
+ * the stack to pass the 5th argument to NS_DebugBreak. When invoke_copy_to_stack
+ * is inlined, this can result, depending on the compiler and flags, in the
+ * stack pointer not pointing at stack_space when the method is called at the
+ * end of this function. More generally, any function call requiring stack
+ * allocation of arguments is unsafe to be inlined in this function.
+ */
+  uint32_t *stack_space = (uint32_t *) __builtin_alloca(base_size * 8);
+
+  invoke_copy_to_stack(stack_space, &stack_space[base_size * 2],
+                       paramCount, params);
+
+  vtable = *reinterpret_cast<vtable_func **>(that);
+  func = vtable[methodIndex];
+
+  return func(that, stack_space[base_size * 2 - 3],
+                    stack_space[base_size * 2 - 2],
+                    stack_space[base_size * 2 - 1]);
 }    
+
+#else /* __ARM_PCS_VFP */
+
+/* "Procedure Call Standard for the ARM Architecture" document, sections
+ * "5.5 Parameter Passing" and "6.1.2 Procedure Calling" contain all the
+ * needed information.
+ *
+ * http://infocenter.arm.com/help/topic/com.arm.doc.ihi0042d/IHI0042D_aapcs.pdf
+ */
+
+#if defined(__thumb__) && !defined(__thumb2__)
+#error "Thumb1 is not supported"
+#endif
+
+#ifndef __ARMEL__
+#error "Only little endian compatibility was tested"
+#endif
+
+/*
+ * Allocation of integer function arguments initially to registers r1-r3
+ * and then to stack. Handling of 'this' argument which goes to r0 registers
+ * is handled separately and does not belong to these two inline functions.
+ *
+ * The doubleword arguments are allocated to even:odd
+ * register pairs or get aligned at 8-byte boundary on stack. The "holes"
+ * which may appear as a result of this realignment remain unused.
+ *
+ * 'ireg_args'  - pointer to the current position in the buffer,
+ *                corresponding to the register arguments
+ * 'stack_args' - pointer to the current position in the buffer,
+ *                corresponding to the arguments on stack
+ * 'end'        - pointer to the end of the registers argument
+ *                buffer (it is guaranteed to be 8-bytes aligned)
+ */
+
+static inline void copy_word(uint32_t* &ireg_args,
+                             uint32_t* &stack_args,
+                             uint32_t* end,
+                             uint32_t  data)
+{
+  if (ireg_args < end) {
+    *ireg_args = data;
+    ireg_args++;
+  } else {
+    *stack_args = data;
+    stack_args++;
+  }
+}
+
+static inline void copy_dword(uint32_t* &ireg_args,
+                              uint32_t* &stack_args,
+                              uint32_t* end,
+                              uint64_t  data)
+{
+  if (ireg_args + 1 < end) {
+    if ((uint32_t)ireg_args & 4) {
+      ireg_args++;
+    }
+    *(uint64_t *)ireg_args = data;
+    ireg_args += 2;
+  } else {
+    if ((uint32_t)stack_args & 4) {
+      stack_args++;
+    }
+    *(uint64_t *)stack_args = data;
+    stack_args += 2;
+  }
+}
+
+/*
+ * Allocation of floating point arguments to VFP registers (s0-s15, d0-d7).
+ *
+ * Unlike integer registers allocation, "back-filling" needs to be
+ * supported. For example, the third floating point argument in the
+ * following function is going to be allocated to s1 register, back-filling
+ * the "hole":
+ *    void f(float s0, double d1, float s1)
+ *
+ * Refer to the "Procedure Call Standard for the ARM Architecture" document
+ * for more details.
+ *
+ * 'vfp_s_args' - pointer to the current position in the buffer with
+ *                the next unallocated single precision register
+ * 'vfp_d_args' - pointer to the current position in the buffer with
+ *                the next unallocated double precision register,
+ *                it has the same value as 'vfp_s_args' when back-filling
+ *                is not used
+ * 'end'        - pointer to the end of the vfp registers argument
+ *                buffer (it is guaranteed to be 8-bytes aligned)
+ *
+ * Mozilla bugtracker has a test program attached which be used for
+ * experimenting with VFP registers allocation code and testing its
+ * correctness:
+ * https://bugzilla.mozilla.org/show_bug.cgi?id=601914#c19
+ */
+
+static inline bool copy_vfp_single(float* &vfp_s_args, double* &vfp_d_args,
+                                   float* end, float data)
+{
+  if (vfp_s_args >= end)
+    return false;
+
+  *vfp_s_args = data;
+  vfp_s_args++;
+  if (vfp_s_args < (float *)vfp_d_args) {
+    // It was the case of back-filling, now the next free single precision
+    // register should overlap with the next free double precision register
+    vfp_s_args = (float *)vfp_d_args;
+  } else if (vfp_s_args > (float *)vfp_d_args) {
+    // also update the pointer to the next free double precision register
+    vfp_d_args++;
+  }
+  return true;
+}
+
+static inline bool copy_vfp_double(float* &vfp_s_args, double* &vfp_d_args,
+                                   float* end, double data)
+{
+  if (vfp_d_args >= (double *)end) {
+    // The back-filling continues only so long as no VFP CPRC has been
+    // allocated to a slot on the stack. Basically no VFP registers can
+    // be allocated after this point.
+    vfp_s_args = end;
+    return false;
+  }
+
+  if (vfp_s_args == (float *)vfp_d_args) {
+    // also update the pointer to the next free single precision register
+    vfp_s_args += 2;
+  }
+  *vfp_d_args = data;
+  vfp_d_args++;
+  return true;
+}
+
+static void
+invoke_copy_to_stack(uint32_t* stk, uint32_t *end,
+                     uint32_t paramCount, nsXPTCVariant* s)
+{
+  uint32_t *ireg_args  = end - 3;
+  float    *vfp_s_args = (float *)end;
+  double   *vfp_d_args = (double *)end;
+  float    *vfp_end    = vfp_s_args + 16;
+
+  for (uint32_t i = 0; i < paramCount; i++, s++) {
+    if (s->IsPtrData()) {
+      copy_word(ireg_args, stk, end, (uint32_t)s->ptr);
+      continue;
+    }
+    // According to the ARM EABI, integral types that are smaller than a word
+    // are to be sign/zero-extended to a full word and treated as 4-byte values
+    switch (s->type)
+    {
+      case nsXPTType::T_FLOAT:
+        if (!copy_vfp_single(vfp_s_args, vfp_d_args, vfp_end, s->val.f)) {
+          copy_word(end, stk, end, reinterpret_cast<uint32_t&>(s->val.f));
+        }
+        break;
+      case nsXPTType::T_DOUBLE:
+        if (!copy_vfp_double(vfp_s_args, vfp_d_args, vfp_end, s->val.d)) {
+          copy_dword(end, stk, end, reinterpret_cast<uint64_t&>(s->val.d));
+        }
+        break;
+      case nsXPTType::T_I8:  copy_word(ireg_args, stk, end, s->val.i8);   break;
+      case nsXPTType::T_I16: copy_word(ireg_args, stk, end, s->val.i16);  break;
+      case nsXPTType::T_I32: copy_word(ireg_args, stk, end, s->val.i32);  break;
+      case nsXPTType::T_I64: copy_dword(ireg_args, stk, end, s->val.i64); break;
+      case nsXPTType::T_U8:  copy_word(ireg_args, stk, end, s->val.u8);   break;
+      case nsXPTType::T_U16: copy_word(ireg_args, stk, end, s->val.u16);  break;
+      case nsXPTType::T_U32: copy_word(ireg_args, stk, end, s->val.u32);  break;
+      case nsXPTType::T_U64: copy_dword(ireg_args, stk, end, s->val.u64); break;
+      case nsXPTType::T_BOOL: copy_word(ireg_args, stk, end, s->val.b);   break;
+      case nsXPTType::T_CHAR: copy_word(ireg_args, stk, end, s->val.c);   break;
+      case nsXPTType::T_WCHAR: copy_word(ireg_args, stk, end, s->val.wc); break;
+      default:
+        // all the others are plain pointer types
+        copy_word(ireg_args, stk, end, reinterpret_cast<uint32_t>(s->val.p));
+        break;
+    }
+  }
+}
+
+typedef uint32_t (*vtable_func)(nsISupports *, uint32_t, uint32_t, uint32_t);
+
+EXPORT_XPCOM_API(nsresult)
+NS_InvokeByIndex(nsISupports* that, uint32_t methodIndex,
+                   uint32_t paramCount, nsXPTCVariant* params)
+{
+  vtable_func *vtable = *reinterpret_cast<vtable_func **>(that);
+  vtable_func func = vtable[methodIndex];
+  // 'register uint32_t result asm("r0")' could be used here, but it does not
+  //  seem to be reliable in all cases: http://gcc.gnu.org/PR46164
+  nsresult result;
+  asm (
+    "mov    r3, sp\n"
+    "mov    %[stack_space_size], %[param_count_plus_2], lsl #3\n"
+    "tst    r3, #4\n" /* check stack alignment */
+
+    "add    %[stack_space_size], #(4 * 16)\n" /* space for VFP registers */
+    "mov    r3, %[params]\n"
+
+    "it     ne\n"
+    "addne  %[stack_space_size], %[stack_space_size], #4\n"
+    "sub    r0, sp, %[stack_space_size]\n" /* allocate space on stack */
+
+    "sub    r2, %[param_count_plus_2], #2\n"
+    "mov    sp, r0\n"
+
+    "add    r1, r0, %[param_count_plus_2], lsl #3\n"
+    "blx    %[invoke_copy_to_stack]\n"
+
+    "add    ip, sp, %[param_count_plus_2], lsl #3\n"
+    "mov    r0, %[that]\n"
+    "ldmdb  ip, {r1, r2, r3}\n"
+    "vldm   ip, {d0, d1, d2, d3, d4, d5, d6, d7}\n"
+    "blx    %[func]\n"
+
+    "add    sp, sp, %[stack_space_size]\n" /* cleanup stack */
+    "mov    %[stack_space_size], r0\n" /* it's actually 'result' variable */
+    : [stack_space_size]     "=&r" (result)
+    : [func]                 "r"   (func),
+      [that]                 "r"   (that),
+      [params]               "r"   (params),
+      [param_count_plus_2]   "r"   (paramCount + 2),
+      [invoke_copy_to_stack] "r"   (invoke_copy_to_stack)
+    : "cc", "memory",
+      // Mark all the scratch registers as clobbered because they may be
+      // modified by the functions, called from this inline assembly block
+      "r0", "r1", "r2", "r3", "ip", "lr",
+      "d0",  "d1",  "d2",  "d3",  "d4",  "d5",  "d6",  "d7",
+      // Also unconditionally mark d16-d31 registers as clobbered even though
+      // they actually don't exist in vfpv2 and vfpv3-d16 variants. There is
+      // no way to identify VFP variant using preprocessor at the momemnt
+      // (see http://gcc.gnu.org/PR46128 for more details), but fortunately
+      // current versions of gcc do not seem to complain about these registers
+      // even when this code is compiled with '-mfpu=vfpv3-d16' option.
+      // If gcc becomes more strict in the future and/or provides a way to
+      // identify VFP variant, the following d16-d31 registers list needs
+      // to be wrapped into some #ifdef
+      "d16", "d17", "d18", "d19", "d20", "d21", "d22", "d23",
+      "d24", "d25", "d26", "d27", "d28", "d29", "d30", "d31"
+  );
+  return result;
+}
+
+#endif
