$NetBSD: patch-Tcl.cc,v 1.1 2014/02/01 08:00:06 markd Exp $

Build with tcl8.6

--- Tcl.cc.orig	2007-02-04 01:46:43.000000000 +0000
+++ Tcl.cc
@@ -213,7 +213,7 @@ void Tcl::error(const char* s)
 	if (strlen(s) > MAX_CODE_TO_DUMP) {
 		s = "\n[code omitted because of length]\n";
 	};
-	fprintf(stderr, "%s: \"%s\": %s\n", application_, s, tcl_->result);
+	fprintf(stderr, "%s: \"%s\": %s\n", application_, s, Tcl_GetStringResult(tcl_));
 	exit(1);
 }
 
@@ -546,7 +546,7 @@ TclClass::dispatch_instvar(ClientData /*
 			need_parse = 1;
 			continue;
 		};
-		result = Tcl_SplitList(in, argv[i], &ac, (const char ***) &av);
+		result = Tcl_SplitList(in, argv[i], &ac, (CONST84 char ***) &av);
 		if (result != TCL_OK) break;
 		if (ac == 1) {
 			varName = localName = av[0];
