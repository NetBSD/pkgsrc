$NetBSD: patch-Src_Builtins_rlimits.awk,v 1.1 2012/08/17 10:53:10 wiz Exp $

Add support for thread limits.
From Peter Stephenson <Peter.Stephenson@csr.com> on zsh-workers.

--- Src/Builtins/rlimits.awk.orig	2011-06-18 23:34:23.000000000 +0000
+++ Src/Builtins/rlimits.awk
@@ -42,6 +42,7 @@ BEGIN {limidx = 0}
 	    if (limnam == "MEMLOCK") { msg[limnum] = "Mmemorylocked" }
 	    if (limnam == "NOFILE")  { msg[limnum] = "Ndescriptors" }
 	    if (limnam == "NPROC")   { msg[limnum] = "Nmaxproc" }
+	    if (limnam == "NTHR")    { msg[limnum] = "Nmaxthr" }
 	    if (limnam == "OFILE")   { msg[limnum] = "Ndescriptors" }
 	    if (limnam == "PTHREAD") { msg[limnum] = "Nmaxpthreads" }
 	    if (limnam == "RSS")     { msg[limnum] = "Mresident" }
