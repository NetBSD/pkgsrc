$NetBSD: patch-ext_tk_tcltklib.c,v 1.1 2014/12/14 14:00:06 taca Exp $

* Add tcl/tk 8.6 support.

--- ext/tk/tcltklib.c.orig	2014-01-19 16:28:53.000000000 +0000
+++ ext/tk/tcltklib.c
@@ -6033,7 +6033,12 @@ ip_rbNamespaceObjCmd(clientData, interp,
     Tcl_CmdInfo info;
     int ret;
 
+    DUMP1("call ip_rbNamespaceObjCmd");
+    DUMP2("objc = %d", objc);
+    DUMP2("objv[0] = '%s'", Tcl_GetString(objv[0]));
+    DUMP2("objv[1] = '%s'", Tcl_GetString(objv[1]));
     if (!Tcl_GetCommandInfo(interp, "__orig_namespace_command__", &(info))) {
+        DUMP1("fail to get __orig_namespace_command__");
         Tcl_ResetResult(interp);
         Tcl_AppendResult(interp,
                          "invalid command name \"namespace\"", (char*)NULL);
@@ -6041,15 +6046,38 @@ ip_rbNamespaceObjCmd(clientData, interp,
     }
 
     rbtk_eventloop_depth++;
-    /* DUMP2("namespace wrapper enter depth == %d", rbtk_eventloop_depth); */
+    DUMP2("namespace wrapper enter depth == %d", rbtk_eventloop_depth);
 
     if (info.isNativeObjectProc) {
+#if TCL_MAJOR_VERSION == 8 && TCL_MINOR_VERSION < 6
+        DUMP1("call a native-object-proc");
         ret = (*(info.objProc))(info.objClientData, interp, objc, objv);
+#else
+        /* Tcl8.6 or later */
+        int i;
+        Tcl_Obj **cp_objv;
+        char org_ns_cmd_name[] = "__orig_namespace_command__";
+
+        DUMP1("call a native-object-proc for tcl8.6 or later");
+        cp_objv = RbTk_ALLOC_N(Tcl_Obj *, (objc + 1));
+
+        cp_objv[0] = Tcl_NewStringObj(org_ns_cmd_name, strlen(org_ns_cmd_name));
+        for(i = 1; i < objc; i++) {
+            cp_objv[i] = objv[i];
+        }
+        cp_objv[objc] = (Tcl_Obj *)NULL;
+
+        /* ret = Tcl_EvalObjv(interp, objc, cp_objv, TCL_EVAL_DIRECT); */
+        ret = Tcl_EvalObjv(interp, objc, cp_objv, 0);
+
+        ckfree((char*)cp_objv);
+#endif
     } else {
         /* string interface */
         int i;
         char **argv;
 
+        DUMP1("call with the string-interface");
         /* argv = (char **)Tcl_Alloc(sizeof(char *) * (objc + 1)); */
         argv = RbTk_ALLOC_N(char *, (objc + 1));
 #if 0 /* use Tcl_Preserve/Release */
@@ -6077,9 +6105,10 @@ ip_rbNamespaceObjCmd(clientData, interp,
 #endif
     }
 
-    /* DUMP2("namespace wrapper exit depth == %d", rbtk_eventloop_depth); */
+    DUMP2("namespace wrapper exit depth == %d", rbtk_eventloop_depth);
     rbtk_eventloop_depth--;
 
+    DUMP1("end of ip_rbNamespaceObjCmd");
     return ret;
 }
 #endif
@@ -6089,6 +6118,8 @@ ip_wrap_namespace_command(interp)
     Tcl_Interp *interp;
 {
 #if TCL_MAJOR_VERSION >= 8
+
+#if TCL_MAJOR_VERSION == 8 && TCL_MINOR_VERSION < 6
     Tcl_CmdInfo orig_info;
 
     if (!Tcl_GetCommandInfo(interp, "namespace", &(orig_info))) {
@@ -6105,6 +6136,11 @@ ip_wrap_namespace_command(interp)
                           orig_info.deleteProc);
     }
 
+#else /* tcl8.6 or later */
+    Tcl_GlobalEval(interp, "rename namespace __orig_namespace_command__");
+
+#endif
+
     Tcl_CreateObjCommand(interp, "namespace", ip_rbNamespaceObjCmd,
                          (ClientData) 0, (Tcl_CmdDeleteProc *)NULL);
 #endif
@@ -8487,15 +8523,28 @@ invoke_tcl_proc(arg)
 #endif
 {
     struct invoke_info *inf = (struct invoke_info *)arg;
+
+#if TCL_MAJOR_VERSION >= 8 && TCL_MINOR_VERSION < 6
     int i, len;
-#if TCL_MAJOR_VERSION >= 8
     int argc = inf->objc;
     char **argv = (char **)NULL;
 #endif
 
+    DUMP1("call invoke_tcl_proc");
+
+#if TCL_MAJOR_VERSION > 8 || (TCL_MAJOR_VERSION == 8 && TCL_MINOR_VERSION >= 6)
+
+    /* eval */
+    inf->ptr->return_value = Tcl_EvalObjv(inf->ptr->ip, inf->objc, inf->objv, TCL_EVAL_DIRECT);
+    /* inf->ptr->return_value = Tcl_EvalObjv(inf->ptr->ip, inf->objc, inf->objv, 0); */
+
+#else /* Tcl/Tk 7.x, 8.0 -- 8.5 */
+
     /* memory allocation for arguments of this command */
-#if TCL_MAJOR_VERSION >= 8
+#if TCL_MAJOR_VERSION == 8
+    /* Tcl/Tk 8.0 -- 8.5 */
     if (!inf->cmdinfo.isNativeObjectProc) {
+        DUMP1("called proc is not a native-obj-proc");
         /* string interface */
         /* argv = (char **)ALLOC_N(char *, argc+1);*/ /* XXXXXXXXXX */
         argv = RbTk_ALLOC_N(char *, (argc+1));
@@ -8509,11 +8558,14 @@ invoke_tcl_proc(arg)
     }
 #endif
 
+    DUMP1("reset result of tcl-interp");
     Tcl_ResetResult(inf->ptr->ip);
 
     /* Invoke the C procedure */
-#if TCL_MAJOR_VERSION >= 8
+#if TCL_MAJOR_VERSION == 8
+    /* Tcl/Tk 8.0 -- 8.5 */
     if (inf->cmdinfo.isNativeObjectProc) {
+        DUMP1("call tcl_proc as a native-obj-proc");
         inf->ptr->return_value
             = (*(inf->cmdinfo.objProc))(inf->cmdinfo.objClientData,
                                         inf->ptr->ip, inf->objc, inf->objv);
@@ -8521,7 +8573,9 @@ invoke_tcl_proc(arg)
     else
 #endif
     {
-#if TCL_MAJOR_VERSION >= 8
+#if TCL_MAJOR_VERSION == 8
+        /* Tcl/Tk 8.0 -- 8.5 */
+        DUMP1("call tcl_proc as not a native-obj-proc");
         inf->ptr->return_value
             = (*(inf->cmdinfo.proc))(inf->cmdinfo.clientData, inf->ptr->ip,
                                      argc, (CONST84 char **)argv);
@@ -8544,6 +8598,9 @@ invoke_tcl_proc(arg)
 #endif
     }
 
+#endif /* Tcl/Tk 8.6 or later || Tcl 7.x, 8.0 -- 8.5 */
+
+    DUMP1("end of invoke_tcl_proc");
     return Qnil;
 }
 
@@ -8572,7 +8629,6 @@ ip_invoke_core(interp, argc, argv)
 #if 1 /* wrap tcl-proc call */
     struct invoke_info inf;
     int status;
-    VALUE ret;
 #else
 #if TCL_MAJOR_VERSION >= 8
     int argc = objc;
@@ -8684,7 +8740,9 @@ ip_invoke_core(interp, argc, argv)
 #endif
 
     /* invoke tcl-proc */
-    ret = rb_protect(invoke_tcl_proc, (VALUE)&inf, &status);
+    DUMP1("invoke tcl-proc");
+    rb_protect(invoke_tcl_proc, (VALUE)&inf, &status);
+    DUMP2("status of tcl-proc, %d", status);
     switch(status) {
     case TAG_RAISE:
         if (NIL_P(rb_errinfo())) {
