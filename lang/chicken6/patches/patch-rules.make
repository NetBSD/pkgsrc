$NetBSD: patch-rules.make,v 1.1 2026/09/19 22:54:07 mef Exp $

Honor LDFLAGS for chicken-do

--- rules.make.orig	2026-08-10 17:38:38.125000353 +0900
+++ rules.make	2026-09-20 07:30:37.795748634 +0900
@@ -249,7 +249,7 @@ $(eval $(call declare-program-from-objec
 # "chicken-do"
 
 $(CHICKEN_DO_PROGRAM)$(EXE): $(SRCDIR)chicken-do.c chicken.h $(CHICKEN_CONFIG_H)
-	$(C_COMPILER) $(C_COMPILER_OPTIONS) $(C_COMPILER_OPTIMIZATION_OPTIONS) $< -o $@
+	$(C_COMPILER) $(C_COMPILER_OPTIONS) $(C_COMPILER_OPTIMIZATION_OPTIONS) $(LINKER_OPTIONS) $< -o $@
 
 
 # installation
