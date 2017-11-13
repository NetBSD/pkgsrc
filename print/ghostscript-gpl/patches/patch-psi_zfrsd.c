$NetBSD: patch-psi_zfrsd.c,v 1.1 2017/11/13 15:10:05 he Exp $

Fix for CVE-2017-8291 from
https://git.ghostscript.com/?p=ghostpdl.git;a=blobdiff_plain;f=psi/zfrsd.c;h=950588d696b682448ec3216fb3ea397999bb50a5;hp=191107d8ae0b3becea2c7318e3ed538b0d18d470;hb=04b37bbce174eed24edec7ad5b920eb93db4d47d;hpb=4f83478c88c2e05d6e8d79ca4557eb039354d2f3

Original commit message:
Bug 697799: have .rsdparams check its parameters

The Ghostscript internal operator .rsdparams wasn't checking the number or
type of the operands it was being passed. Do so.

--- psi/zfrsd.c.orig	2012-08-08 08:01:36.000000000 +0000
+++ psi/zfrsd.c
@@ -49,13 +49,20 @@ zrsdparams(i_ctx_t *i_ctx_p)
     ref *pFilter;
     ref *pDecodeParms;
     int Intent = 0;
-    bool AsyncRead;
+    bool AsyncRead = false;
     ref empty_array, filter1_array, parms1_array;
     uint i;
-    int code;
+    int code = 0;
+
+    if (ref_stack_count(&o_stack) < 1)
+        return_error(gs_error_stackunderflow);
+    if (!r_has_type(op, t_dictionary) && !r_has_type(op, t_null)) {
+        return_error(gs_error_typecheck);
+    }
 
     make_empty_array(&empty_array, a_readonly);
-    if (dict_find_string(op, "Filter", &pFilter) > 0) {
+    if (r_has_type(op, t_dictionary)
+        && dict_find_string(op, "Filter", &pFilter) > 0) {
         if (!r_is_array(pFilter)) {
             if (!r_has_type(pFilter, t_name))
                 return_error(e_typecheck);
@@ -94,12 +101,13 @@ zrsdparams(i_ctx_t *i_ctx_p)
                 return_error(e_typecheck);
         }
     }
-    code = dict_int_param(op, "Intent", 0, 3, 0, &Intent);
+    if (r_has_type(op, t_dictionary))
+	code = dict_int_param(op, "Intent", 0, 3, 0, &Intent);
     if (code < 0 && code != e_rangecheck) /* out-of-range int is ok, use 0 */
         return code;
-    if ((code = dict_bool_param(op, "AsyncRead", false, &AsyncRead)) < 0
-        )
-        return code;
+    if (r_has_type(op, t_dictionary))
+	if ((code = dict_bool_param(op, "AsyncRead", false, &AsyncRead)) < 0)
+	    return code;
     push(1);
     op[-1] = *pFilter;
     if (pDecodeParms)
