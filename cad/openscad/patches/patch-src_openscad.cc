$NetBSD: patch-src_openscad.cc,v 1.1 2025/02/02 00:41:13 mef Exp $

Compile fix from upstream, fixing ::join ambiguity
https://github.com/openscad/openscad/commit/9b79576c1ee9d57d0f4a5de5c1365bb87c548f36

--- src/openscad.cc.orig	2021-01-31 17:41:09.000000000 +0000
+++ src/openscad.cc
@@ -65,7 +65,6 @@
 #include <chrono>
 #include <boost/algorithm/string.hpp>
 #include <boost/algorithm/string/split.hpp>
-#include <boost/algorithm/string/join.hpp>
 #include <boost/range/adaptor/transformed.hpp>
 #include <boost/program_options.hpp>
 #include <boost/filesystem.hpp>
@@ -307,7 +306,7 @@ void set_render_color_scheme(const std::
 	}
 
 	if (exit_if_not_found) {
-		LOG(message_group::None,Location::NONE,"",(boost::join(ColorMap::inst()->colorSchemeNames(), "\n")));
+		LOG(message_group::None,Location::NONE,"",(boost::algorithm::join(ColorMap::inst()->colorSchemeNames(), "\n")));
 
 		exit(1);
 	} else {
@@ -885,7 +884,7 @@ struct CommaSeparatedVector
 };
 
 template <class Seq, typename ToString>
-std::string join(const Seq &seq, const std::string &sep, const ToString &toString)
+std::string str_join(const Seq &seq, const std::string &sep, const ToString &toString)
 {
     return boost::algorithm::join(boost::adaptors::transform(seq, toString), sep);
 }
@@ -947,7 +946,7 @@ int main(int argc, char **argv)
 		("P,P", po::value<string>(), "customizer parameter set")
 #ifdef ENABLE_EXPERIMENTAL
 		("enable", po::value<vector<string>>(), ("enable experimental features: " +
-		                                          join(boost::make_iterator_range(Feature::begin(), Feature::end()), " | ",
+		                                          str_join(boost::make_iterator_range(Feature::begin(), Feature::end()), " | ",
 		                                               [](const Feature *feature) {
 		                                                   return feature->get_name();
 		                                               }) +
@@ -964,11 +963,11 @@ int main(int argc, char **argv)
 		("render", po::value<string>()->implicit_value(""), "for full geometry evaluation when exporting png")
 		("preview", po::value<string>()->implicit_value(""), "[=throwntogether] -for ThrownTogether preview png")
 		("animate", po::value<unsigned>(), "export N animated frames")
-		("view", po::value<CommaSeparatedVector>(), ("=view options: " + boost::join(viewOptions.names(), " | ")).c_str())
+		("view", po::value<CommaSeparatedVector>(), ("=view options: " + boost::algorithm::join(viewOptions.names(), " | ")).c_str())
 		("projection", po::value<string>(), "=(o)rtho or (p)erspective when exporting png")
 		("csglimit", po::value<unsigned int>(), "=n -stop rendering at n CSG elements when exporting png")
 		("colorscheme", po::value<string>(), ("=colorscheme: " +
-		                                      join(ColorMap::inst()->colorSchemeNames(), " | ",
+		                                      str_join(ColorMap::inst()->colorSchemeNames(), " | ",
 		                                           [](const std::string& colorScheme) {
 		                                               return (colorScheme == ColorMap::inst()->defaultColorSchemeName() ? "*" : "") + colorScheme;
 		                                           }) +
