$NetBSD: patch-filter.c,v 1.1 2011/12/07 15:18:51 joerg Exp $

--- filter.c.orig	2003-11-19 14:38:02.000000000 +0000
+++ filter.c
@@ -534,7 +534,7 @@ MakeBoolConstNode(
     pf = MallocZ(sizeof(struct filter_node));
 
     pf->vartype = V_BOOL;
-    pf->un.constant.bool = val;
+    pf->un.constant.boolean = val;
 
     return(pf);
 }
@@ -624,9 +624,9 @@ PrintConst(
 	break;
       case V_BOOL:
 	if (debug)
-	    snprintf(buf,sizeof(buf),"BOOL(%s)",  BOOL2STR(pf->un.constant.bool));
+	    snprintf(buf,sizeof(buf),"BOOL(%s)",  BOOL2STR(pf->un.constant.boolean));
 	else
-	    snprintf(buf,sizeof(buf),"%s", BOOL2STR(pf->un.constant.bool));
+	    snprintf(buf,sizeof(buf),"%s", BOOL2STR(pf->un.constant.boolean));
 	break;
       case V_IPADDR:
 	if (debug)
@@ -716,7 +716,7 @@ Res2Str(
       case V_ULLONG:	snprintf(buf,sizeof(buf),"ULLONG(%" FS_ULL ")",pres->val.u_longint); break;
       case V_LLONG:	snprintf(buf,sizeof(buf),"LLONG(%"  FS_LL  ")",pres->val.longint); break;
       case V_STRING:	snprintf(buf,sizeof(buf),"STRING(%s)",pres->val.string); break;
-      case V_BOOL:	snprintf(buf,sizeof(buf),"BOOL(%s)",  BOOL2STR(pres->val.bool)); break;
+      case V_BOOL:	snprintf(buf,sizeof(buf),"BOOL(%s)",  BOOL2STR(pres->val.boolean)); break;
       default: {
 	  fprintf(stderr,"Res2Str: unknown constant type %d (%s)\n",
 		  pres->vartype, Vartype2Str(pres->vartype));
@@ -1219,7 +1219,7 @@ EvalRelopUnsigned(
 
     /* fill in the answer */
     pres->vartype = V_BOOL;
-    pres->val.bool = ret;
+    pres->val.boolean = ret;
 
     if (debug)
 	printf("EvalUnsigned %" FS_ULL " %s %" FS_ULL " returns %s\n",
@@ -1267,7 +1267,7 @@ EvalRelopSigned(
 
     /* fill in the answer */
     pres->vartype = V_BOOL;
-    pres->val.bool = ret;
+    pres->val.boolean = ret;
 
     if (debug)
 	printf("EvalSigned %" FS_LL " %s %" FS_LL " returns %s\n",
@@ -1329,7 +1329,7 @@ EvalRelopIpaddr(
 
      /* fill in the answer */
      pres->vartype = V_BOOL;
-     pres->val.bool = ret;
+     pres->val.boolean = ret;
 
      if (debug) {
 	 printf("EvalIpaddr %s %s", HostAddr(*varl), Op2Str(pf->op));
@@ -1382,7 +1382,7 @@ EvalRelopString(
 
     /* fill in the answer */
     pres->vartype = V_BOOL;
-    pres->val.bool = ret;
+    pres->val.boolean = ret;
 
     if (debug)
 	printf("EvalString '%s' %s '%s' returns %s\n",
@@ -1425,7 +1425,7 @@ EvalVariable(
 
       case V_BOOL:
 	pres->vartype = V_BOOL;
-	pres->val.bool = (Var2Unsigned(ptp,pf) != 0);
+	pres->val.boolean = (Var2Unsigned(ptp,pf) != 0);
 	break;
 
       case V_IPADDR:
@@ -1475,7 +1475,7 @@ EvalConstant(
 
       case V_BOOL:
 	pres->vartype = V_BOOL;
-	pres->val.bool = (Var2Unsigned(ptp,pf) != 0);
+	pres->val.boolean = (Var2Unsigned(ptp,pf) != 0);
 	break;
 
       case V_IPADDR:
@@ -1528,11 +1528,11 @@ EvalFilter(
 	if (pf->un.binary.left->vartype == V_ULLONG) {
 	    EvalRelopUnsigned(ptp,&res,pf);
 	    pres->vartype = V_BOOL;
-	    pres->val.bool = res.val.bool;
+	    pres->val.boolean = res.val.boolean;
 	} else if (pf->un.binary.left->vartype == V_LLONG) {
 	    EvalRelopSigned(ptp,&res,pf);
 	    pres->vartype = V_BOOL;
-	    pres->val.bool = res.val.bool;
+	    pres->val.boolean = res.val.boolean;
 	} else if (pf->un.binary.left->vartype == V_STRING) {
 	    EvalRelopString(ptp,&res,pf);
 	    pres->vartype = V_LLONG;
@@ -1540,7 +1540,7 @@ EvalFilter(
 	} else if (pf->un.binary.left->vartype == V_IPADDR) {
 	    EvalRelopIpaddr(ptp,&res,pf);
 	    pres->vartype = V_BOOL;
-	    pres->val.bool = res.val.bool;
+	    pres->val.boolean = res.val.boolean;
 	} else {
 	    fprintf(stderr,
 		    "EvalFilter: binary op %d (%s) not supported on data type %d (%s)\n",
@@ -1583,14 +1583,14 @@ EvalFilter(
 	    if (pf->op == OP_OR) {
 		EvalFilter(ptp,&res1,pf->un.binary.left);
 		EvalFilter(ptp,&res2,pf->un.binary.right);
-		ret = res1.val.bool || res2.val.bool;
+		ret = res1.val.boolean || res2.val.boolean;
 	    } else {
 		EvalFilter(ptp,&res1,pf->un.binary.left);
 		EvalFilter(ptp,&res2,pf->un.binary.right);
-		ret = res1.val.bool &&  res2.val.bool;
+		ret = res1.val.boolean &&  res2.val.boolean;
 	    }
 	    pres->vartype = V_BOOL;
-	    pres->val.bool = ret;
+	    pres->val.boolean = ret;
 	} else {
 	    fprintf(stderr,
 		    "EvalFilter: binary op %d (%s) not supported on data type %d (%s)\n",
@@ -1604,7 +1604,7 @@ EvalFilter(
 	if (pf->vartype == V_BOOL) {
 	    EvalFilter(ptp,&res,pf->un.unary.pf);
 	    pres->vartype = V_BOOL;
-	    pres->val.bool = !res.val.bool;
+	    pres->val.boolean = !res.val.boolean;
 	} else {
 	    fprintf(stderr,
 		    "EvalFilter: unary operation %d (%s) not supported on data type %d (%s)\n",
@@ -1641,7 +1641,7 @@ PassesFilter(
 
     /* recurse down the tree */
     EvalFilter(ptp,&res,filter_root);
-    ret = res.val.bool;
+    ret = res.val.boolean;
 
     if (debug)
 	printf("PassesFilter('%s<->%s') returns %s\n",
