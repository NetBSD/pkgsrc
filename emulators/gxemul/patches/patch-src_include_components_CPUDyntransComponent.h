$NetBSD: patch-src_include_components_CPUDyntransComponent.h,v 1.1 2012/11/23 12:33:22 joerg Exp $

--- src/include/components/CPUDyntransComponent.h.orig	2012-11-19 20:05:03.000000000 +0000
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
-	virtual void (*GetDyntransToBeTranslated())(CPUDyntransComponent* cpu, DyntransIC* ic) const = 0;
+	virtual DyntransIC_t GetDyntransToBeTranslated() const = 0;
 
 	void DyntransToBeTranslatedBegin(struct DyntransIC*);
 	bool DyntransReadInstruction(uint16_t& iword);
