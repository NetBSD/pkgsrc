$NetBSD: patch-src_include_components_M88K__CPUComponent.h,v 1.1 2012/11/23 12:33:22 joerg Exp $

--- src/include/components/M88K_CPUComponent.h.orig	2012-11-19 20:10:14.000000000 +0000
+++ src/include/components/M88K_CPUComponent.h
@@ -377,7 +377,7 @@ protected:
 	virtual bool FunctionTraceReturnImpl(int64_t& retval) { retval = m_r[M88K_RETURN_VALUE_REG]; return true; }
 
 	virtual int GetDyntransICshift() const;
-	virtual void (*GetDyntransToBeTranslated())(CPUDyntransComponent*, DyntransIC*) const;
+	virtual DyntransIC_t GetDyntransToBeTranslated() const ;
 
 	virtual void ShowRegisters(GXemul* gxemul, const vector<string>& arguments) const;
 
