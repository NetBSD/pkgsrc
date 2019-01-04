$NetBSD: patch-src_include_components_CPUDyntransComponent.h,v 1.2 2019/01/04 13:35:16 ryoon Exp $

Don't define functions returning functions.

--- src/include/components/CPUDyntransComponent.h.orig	2018-12-07 06:29:22.000000000 +0000
+++ src/include/components/CPUDyntransComponent.h
@@ -47,9 +47,13 @@ class CPUDyntransComponent;
  * f points to a function to be executed.
  * arg[] contains arguments, such as pointers to registers, or immediate values.
  */
+class CPUDyntransComponent;
+struct DyntransIC;
+typedef void (*DyntransIC_t)(class CPUDyntransComponent*, struct DyntransIC*);
+
 struct DyntransIC
 {
-	void (*f)(CPUDyntransComponent*, DyntransIC*);
+	DyntransIC_t f;
 
 	union {
 		void* p;
@@ -105,7 +109,7 @@ public:
 protected:
 	// Implemented by specific CPU families:
 	virtual int GetDyntransICshift() const = 0;
-	virtual void (*GetDyntransToBeTranslated())(CPUDyntransComponent* cpu, DyntransIC* ic) = 0;
+	virtual DyntransIC_t GetDyntransToBeTranslated() = 0;
 
 	void DyntransToBeTranslatedBegin(struct DyntransIC*);
 	bool DyntransReadInstruction(uint16_t& iword);
