$NetBSD: patch-xpcom_reflect_xptcall_md_unix_xptcinvoke__ppc__netbsd.cpp,v 1.1 2016/02/14 07:30:54 ryoon Exp $

--- xpcom/reflect/xptcall/md/unix/xptcinvoke_ppc_netbsd.cpp.orig	2014-10-11 09:06:50.000000000 +0000
+++ xpcom/reflect/xptcall/md/unix/xptcinvoke_ppc_netbsd.cpp
@@ -5,9 +5,9 @@
 
 // Platform specific code to invoke XPCOM methods on native objects
 
-// The purpose of XPTC_InvokeByIndex() is to map a platform
+// The purpose of NS_InvokeByIndex_P() is to map a platform
 // indepenpent call to the platform ABI. To do that,
-// XPTC_InvokeByIndex() has to determine the method to call via vtable
+// NS_InvokeByIndex_P() has to determine the method to call via vtable
 // access. The parameters for the method are read from the
 // nsXPTCVariant* and prepared for the native ABI.  For the Linux/PPC
 // ABI this means that the first 8 integral and floating point
@@ -72,8 +72,10 @@ invoke_copy_to_stack(uint32_t* d,
                 if ((uint32_t) d & 4) d++; // doubles are 8-byte aligned on stack
                 *((double*) d) = s->val.d;
                 d += 2;
+#if __GXX_ABI_VERSION < 100
 		if (gpr < GPR_COUNT)
 		    gpr += 2;
+#endif
             }
         }
         else if (!s->IsPtrData() && s->type == nsXPTType::T_FLOAT) {
@@ -82,8 +84,10 @@ invoke_copy_to_stack(uint32_t* d,
             else {
                 *((float*) d) = s->val.f;
 		d += 1;
+#if __GXX_ABI_VERSION < 100
 		if (gpr < GPR_COUNT)
 		    gpr += 1;
+#endif
 	    }
         }
         else if (!s->IsPtrData() && (s->type == nsXPTType::T_I64
@@ -110,6 +114,6 @@ invoke_copy_to_stack(uint32_t* d,
 }
 
 extern "C"
-XPTC_PUBLIC_API(nsresult)
-XPTC_InvokeByIndex(nsISupports* that, uint32_t methodIndex,
+EXPORT_XPCOM_API(nsresult)
+NS_InvokeByIndex_P(nsISupports* that, PRUint32 methodIndex,
                    uint32_t paramCount, nsXPTCVariant* params);
