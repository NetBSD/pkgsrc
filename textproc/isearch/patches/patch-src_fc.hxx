$NetBSD: patch-src_fc.hxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers
   - use "std" qualification

--- src/fc.hxx~	1996-12-21 00:40:55.000000000 +0000
+++ src/fc.hxx
@@ -8,7 +8,7 @@ Author:		Nassib Nassar, nrn@cnidr.org
 #ifndef FC_HXX
 #define FC_HXX
 
-#include <iostream.h>
+#include <iostream>
 /*
 #include "defs.hxx"
 */
@@ -22,7 +22,7 @@ public:
 	void Write(PFILE fp) const;
 	void Read(PFILE fp);
 	void FlipBytes();
-	friend ostream& operator<<(ostream& os, const FC& Fc);
+	friend std::ostream& operator<<(std::ostream& os, const FC& Fc);
 	~FC();
 private:
 	GPTYPE FieldStart;
