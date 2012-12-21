$NetBSD: patch-src_fct.hxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - use "std" qualification

--- src/fct.hxx~	2001-11-21 07:01:57.000000000 +0000
+++ src/fct.hxx
@@ -31,9 +31,9 @@ public:
 	void SortByFc();
 	void Write(PFILE fp) const;
 	void Read(PFILE fp);
-	void Print(ostream& Os) const;
+	void Print(std::ostream& Os) const;
 	void SubtractOffset(const GPTYPE GpOffset);
-	friend ostream& operator<<(ostream& os, const FCT& Fct);
+	friend std::ostream& operator<<(std::ostream& os, const FCT& Fct);
 };
 
 typedef FCT* PFCT;
