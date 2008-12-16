$NetBSD: patch-main.cpp,v 1.1.1.1 2008/12/16 19:35:46 sborrill Exp $

Add option to disable overlay UI

--- main.cpp.orig	2008-12-14 12:19:53.000000000 +0000
+++ main.cpp	2008-12-14 12:21:00.000000000 +0000
@@ -152,6 +152,7 @@
 	 \t[-f bvc|cellb|h261|jpeg|nv|mpeg4|h264] [-F maxfps] [-i ifAddr ] [-I channel]\n\
 	 \t[-K key ] [-L flowLabel (ip6 only)] [-l (creates log file)]\n\
 	 \t[-M colormap] [-m mtu] [-N session] [-n atm|ip|ip6|rtip]\n\
+	 \t[-O (disables overlay) ]\n\
 	 \t[-o clipfile] [-t ttl] [-U interval] [-u script] [-v version] [-V visual]\n\
 	 \t[-x ifIndex (ip6 only)] [-X resource=value] [-j numlayers] dest/port[/fmt/ttl]\n";
 
@@ -504,7 +505,7 @@
 #endif
 	// Option list; If letter is followed by ':' then it takes an argument
 	const char* options = 
-		"A:B:C:c:D:d:f:F:HI:i:j:K:lL:M:m:N:n:o:Pq:rsST:t:U:u:vV:w:x:X:y";
+		"A:B:C:c:D:d:f:F:HI:i:j:K:lL:M:m:N:n:o:OPq:rsST:t:U:u:vV:w:x:X:y";
 	/* process display and window (-use) options before initialising tcl/tk */
 	char buf[256], tmp[256];
 	const char *display=0, *use=0;
@@ -678,6 +679,10 @@
 			tcl.add_option("network", optarg);
 			break;
 
+		case 'O':
+			tcl.add_option("overlayEnabled", "false");
+			break;
+
 		case 'o':
 			tcl.add_option("outfile", optarg);
 			break;
