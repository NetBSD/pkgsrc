$NetBSD: patch-cnf-to-paths.awk,v 1.1 2011/07/28 04:25:06 minskim Exp $

--- cnf-to-paths.awk.orig	2011-05-23 17:48:36.000000000 +0000
+++ cnf-to-paths.awk
@@ -10,19 +10,6 @@
 # (whitespace around the = is optional)
 #
 /^[ \t]*[A-Z0-9_]+[ \t]*=/ {
-  # On these lines, there are two cases:
-  # 
-  # 1) definitions referring to SELFAUTO*, which we want to keep.  In
-  # particular, this is how the compile-time TEXMFCNF gets defined and
-  # thus how texmf.cnf gets found.
-  # 
-  # 2) all the others, which we want to convert to a constant
-  # /nonesuch.  That way, the binaries don't get change just because we
-  # change definitions in texmf.cnf.
-  # 
-  # The definition of DEFAULT_TEXMF (and other variables)
-  # that winds up in the final paths.h will not be used.
-  
   # Let's extract the identifier and the value from the line.  Since
   # gawk's subexpression matching is an extension, do it with copies.
   ident = $0;
@@ -34,13 +21,7 @@
   sub(/[ \t]*$/, "", val);
   #print "got ident", ident, "and val", val >"/dev/stderr"; 
   
-  if (val ~ /\$SELFAUTO/) {
-    # Replace all semicolons with colons in the SELFAUTO paths we're keeping.
-    # (The path-splitting code should be changed to understand both.)
-    gsub(/;/, ":", val);
-  } else {
-    val = "/nonesuch";
-  }
+  gsub(/;/, ":", val);
   
   print "#ifndef DEFAULT_" ident;
   print "#define DEFAULT_" ident " \"" val "\"";
