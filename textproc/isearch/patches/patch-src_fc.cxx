$NetBSD: patch-src_fc.cxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - use "std" qualification

--- src/fc.cxx~	1996-12-21 00:40:54.000000000 +0000
+++ src/fc.cxx
@@ -46,8 +46,8 @@ void FC::FlipBytes() {
 	GpSwab(&FieldEnd);
 }
 
-ostream& operator<<(ostream& Os, const FC& Fc) {
-	Os << Fc.FieldStart << ' ' << Fc.FieldEnd << endl;
+std::ostream& operator<<(std::ostream& Os, const FC& Fc) {
+	Os << Fc.FieldStart << ' ' << Fc.FieldEnd << std::endl;
 	return Os;
 }
 
