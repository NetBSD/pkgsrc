--- src/lib/fmt/AudioFormatFormatter.hxx.orig	2023-12-20 07:21:57.000000000 -0800
+++ src/lib/fmt/AudioFormatFormatter.hxx	2024-07-14 16:13:04.360021663 -0700
@@ -39,7 +39,7 @@
 struct fmt::formatter<SampleFormat> : formatter<string_view>
 {
 	template<typename FormatContext>
-	auto format(const SampleFormat format, FormatContext &ctx) {
+	auto format(const SampleFormat format, FormatContext &ctx) const {
 		return formatter<string_view>::format(sample_format_to_string(format),
 						      ctx);
 	}
@@ -49,7 +49,7 @@
 struct fmt::formatter<AudioFormat> : formatter<string_view>
 {
 	template<typename FormatContext>
-	auto format(const AudioFormat &af, FormatContext &ctx) {
+	auto format(const AudioFormat &af, FormatContext &ctx) const {
 		return formatter<string_view>::format(ToString(af).c_str(),
 						      ctx);
 	}
