$NetBSD: patch-libraries_source_fcollada_src_FCollada_FUtils_FUStringBuilder.hpp,v 1.1 2023/05/04 15:20:52 nikita Exp $

--- libraries/source/fcollada/src/FCollada/FUtils/FUStringBuilder.hpp.orig	2021-08-25 14:44:24.000000000 +0000
+++ libraries/source/fcollada/src/FCollada/FUtils/FUStringBuilder.hpp
@@ -174,46 +174,45 @@ void FUStringBuilderT<Char>::append(cons
 template <class Char>
 void FUStringBuilderT<Char>::append(float f)
 {
-#ifdef WIN32
-	// use <float.h> _isnan method to detect the 1.#IND00 NaN.
-	if (f != std::numeric_limits<float>::infinity() && f != -std::numeric_limits<float>::infinity() && f != std::numeric_limits<float>::quiet_NaN() && f != std::numeric_limits<float>::signaling_NaN() && !_isnan((double)f))
-#else
-	if (f != std::numeric_limits<float>::infinity() && f != -std::numeric_limits<float>::infinity() && f != std::numeric_limits<float>::quiet_NaN() && f != std::numeric_limits<float>::signaling_NaN())
-#endif
-	{
-		if (IsEquivalent(f, 0.0f, std::numeric_limits<float>::epsilon())) append((Char)'0');
-		else
-			for (Char c : ToXmlDouble(f))
-				append(c);
-	}
-	else if (f == std::numeric_limits<float>::infinity())
-	{ append((Char)'I'); append((Char)'N'); append((Char)'F'); }
-	else if (f == -std::numeric_limits<float>::infinity())
-	{ append((Char)'-'); append((Char)'I'); append((Char)'N'); append((Char)'F'); }
-	else
-	{ append((Char)'N'); append((Char)'a'); append((Char)'N'); }
+	append((double)f);
 }
 template <class Char>
 void FUStringBuilderT<Char>::append(double f)
 {
-#ifdef WIN32
-	// use <float.h> _isnan method to detect the .#IND00 NaN.
-	if (f != std::numeric_limits<float>::infinity() && f != -std::numeric_limits<float>::infinity() && f != std::numeric_limits<float>::quiet_NaN() && f != std::numeric_limits<float>::signaling_NaN() && !_isnan(f))
-#else
-	if (f != std::numeric_limits<float>::infinity() && f != -std::numeric_limits<float>::infinity() && f != std::numeric_limits<float>::quiet_NaN() && f != std::numeric_limits<float>::signaling_NaN())
-#endif
-	{
-		if (IsEquivalent(f, 0.0, std::numeric_limits<double>::epsilon())) append((Char)'0');
-		else
-			for (Char c : ToXmlDouble(f))
-				append(c);
-	}
-	else if (f == std::numeric_limits<double>::infinity())
-	{ append((Char)'I'); append((Char)'N'); append((Char)'F'); }
-	else if (f == -std::numeric_limits<double>::infinity())
-	{ append((Char)'-'); append((Char)'I'); append((Char)'N'); append((Char)'F'); }
+	if (f == -std::numeric_limits<double>::infinity()) {
+		append("-INF");
+		return;
+	} else if (f == std::numeric_limits<double>::infinity()) {
+		append("INF");
+		return;
+	} else if (f != f) {
+		append("NaN");
+		return;
+	} else if (-std::numeric_limits<double>::epsilon() < f && f < std::numeric_limits<double>::epsilon()) {
+		append("0.0E0");
+		return;
+	}
+	if (f < 0.0) {
+		f = -f;
+		append('-');
+	}
+
+	int e = 0;
+	if (f < 1.0)
+		for (; f < 1.0; f *= 10.0)
+			e--;
 	else
-	{ append((Char)'N'); append((Char)'a'); append((Char)'N'); }
+		for (; f >= 10.0; f /= 10.0)
+			e++;
+
+	char tmp[10];
+	sprintf(tmp, "%.6g", f);
+	append(tmp);
+	if (tmp[1] == 0) // only one digit, add missing part according canonical representation
+		append(".0");
+
+	sprintf(tmp, "E%d", e);
+	append(tmp);
 }
 template <class Char>
 void FUStringBuilderT<Char>::append(const FMVector2& v)
