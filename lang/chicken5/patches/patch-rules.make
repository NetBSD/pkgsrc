$NetBSD: patch-rules.make,v 1.1 2026/09/10 14:25:21 mef Exp $

Honor LD_FLAGS for chicken-do

--- rules.make.orig	2024-07-16 14:43:18.000000000 +0900
+++ rules.make	2026-09-10 23:11:56.405210505 +0900
@@ -254,7 +254,7 @@ $(eval $(call declare-program-from-objec
 # "chicken-do"
 
 $(CHICKEN_DO_PROGRAM)$(EXE): $(SRCDIR)chicken-do.c chicken.h $(CHICKEN_CONFIG_H)
-	$(C_COMPILER) $(C_COMPILER_OPTIONS) $(C_COMPILER_OPTIMIZATION_OPTIONS) $< -o $@
+	$(C_COMPILER) $(C_COMPILER_OPTIONS) $(C_COMPILER_OPTIMIZATION_OPTIONS) $(LINKER_OPTIONS) $< -o $@
 
 # scripts
 
