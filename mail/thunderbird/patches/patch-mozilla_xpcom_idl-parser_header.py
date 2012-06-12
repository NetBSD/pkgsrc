$NetBSD: patch-mozilla_xpcom_idl-parser_header.py,v 1.4 2012/06/12 19:37:49 ryoon Exp $

--- mozilla/xpcom/idl-parser/header.py.orig	2012-06-01 17:19:53.000000000 +0000
+++ mozilla/xpcom/idl-parser/header.py
@@ -505,10 +505,9 @@ if __name__ == '__main__':
             print >>sys.stderr, "--regen useless without --cachedir"
         # Delete the lex/yacc files.  Ply is too stupid to regenerate them
         # properly
-        deadfiles = os.path.join(options.cachedir, "*.py*")
-        for filename in glob.glob(deadfiles):
-            print filename
-            os.remove(filename)
+	for fileglobs in [os.path.join(options.cachedir, f) for f in ["xpidllex.py*", "xpidlyacc.py*"]]:
+	    for filename in glob.glob(fileglobs):
+		os.remove(filename)
 
     # Instantiate the parser.
     p = xpidl.IDLParser(outputdir=options.cachedir)
