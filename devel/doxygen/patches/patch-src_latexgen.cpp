$NetBSD: patch-src_latexgen.cpp,v 1.1 2015/02/19 11:53:59 joerg Exp $

--- src/latexgen.cpp.orig	2015-02-18 21:15:46.000000000 +0000
+++ src/latexgen.cpp
@@ -540,9 +540,10 @@ static void writeDefaultFooter(FTextStre
     unit = "section";
   else
     unit = "chapter";
-  t << "% Index\n"
-       "\\backmatter\n"
-       "\\newpage\n"
+  t << "% Index\n";
+  if (!Config_getBool("COMPACT_LATEX"))
+    t << "\\backmatter\n";
+  t << "\\newpage\n"
        "\\phantomsection\n"
        "\\clearemptydoublepage\n"
        "\\addcontentsline{toc}{" << unit << "}{" << theTranslator->trRTFGeneralIndex() << "}\n"
