$NetBSD: patch-SPQR_Source_spqr__factorize.cpp,v 1.1 2024/06/14 13:19:54 ktnb Exp $

Upstream bug, should include string

--- SPQR/Source/spqr_factorize.cpp.orig	2024-03-26 21:14:00.000000000 +0000
+++ SPQR/Source/spqr_factorize.cpp
@@ -36,6 +36,7 @@
 // =============================================================================
 
 #include "spqr.hpp"
+#include <string>
 
 #define FCHUNK 32        // FUTURE: make a parameter; Householder block size
 
