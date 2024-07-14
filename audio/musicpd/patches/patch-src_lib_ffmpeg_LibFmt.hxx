--- src/lib/ffmpeg/LibFmt.hxx.orig	2023-12-20 07:21:57.000000000 -0800
+++ src/lib/ffmpeg/LibFmt.hxx	2024-07-14 16:13:04.359461264 -0700
@@ -29,7 +29,7 @@
 struct fmt::formatter<AVSampleFormat> : formatter<string_view>
 {
 	template<typename FormatContext>
-	auto format(const AVSampleFormat format, FormatContext &ctx) {
+	auto format(const AVSampleFormat format, FormatContext &ctx) const {
 		const char *name = av_get_sample_fmt_name(format);
 		if (name == nullptr)
 			name = "?";
