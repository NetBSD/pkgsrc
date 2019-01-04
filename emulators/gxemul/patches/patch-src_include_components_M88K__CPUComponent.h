$NetBSD: patch-src_include_components_M88K__CPUComponent.h,v 1.2 2019/01/04 13:35:16 ryoon Exp $

Don't define functions returning functions.

--- src/include/components/M88K_CPUComponent.h.orig	2018-12-07 06:29:22.000000000 +0000
+++ src/include/components/M88K_CPUComponent.h
@@ -377,7 +377,7 @@ protected:
 	virtual bool FunctionTraceReturnImpl(int64_t& retval) { retval = m_r[M88K_RETURN_VALUE_REG]; return true; }
 
 	virtual int GetDyntransICshift() const;
-	virtual void (*GetDyntransToBeTranslated())(CPUDyntransComponent*, DyntransIC*);
+	virtual DyntransIC_t GetDyntransToBeTranslated();
 
 	virtual void ShowRegisters(GXemul* gxemul, const vector<string>& arguments) const;
 
