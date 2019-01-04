$NetBSD: patch-src_include_components_MIPS__CPUComponent.h,v 1.2 2019/01/04 13:35:16 ryoon Exp $

Don't define functions returning functions.

--- src/include/components/MIPS_CPUComponent.h.orig	2018-12-07 06:29:22.000000000 +0000
+++ src/include/components/MIPS_CPUComponent.h
@@ -196,7 +196,7 @@ protected:
 	virtual bool FunctionTraceReturnImpl(int64_t& retval);
 
 	virtual int GetDyntransICshift() const;
-	virtual void (*GetDyntransToBeTranslated())(CPUDyntransComponent*, DyntransIC*);
+	virtual DyntransIC_t GetDyntransToBeTranslated();
 
 	virtual void ShowRegisters(GXemul* gxemul, const vector<string>& arguments) const;
 
