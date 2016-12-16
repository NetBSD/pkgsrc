$NetBSD: patch-src_configcontainer.cpp,v 1.1 2016/12/16 00:00:25 joerg Exp $

Passing non-POD types to variadic functions is UB, so use C++11 rvalues
and proper typing.

--- src/configcontainer.cpp.orig	2016-12-15 14:37:26.527419424 +0000
+++ src/configcontainer.cpp
@@ -15,20 +15,8 @@
 
 namespace newsbeuter {
 
-configdata::configdata(std::string v, ...) : value(v), default_value(v), type(ENUM) {
-	va_list ap;
-	va_start(ap, v);
-
-	const char * arg;
-
-	do {
-		arg = va_arg(ap, const char *);
-		if (arg) {
-			enum_values.insert(arg);
-		}
-	} while (arg != NULL);
-
-	va_end(ap);
+configdata::configdata(const std::string &v, std::set<std::string> &&enumv) : value(v), default_value(v), type(ENUM) {
+	enum_values = std::move(enumv);
 }
 
 configcontainer::configcontainer() {
@@ -51,8 +39,8 @@ configcontainer::configcontainer() {
 	config_data["cache-file"]      = configdata("", configdata::PATH);
 	config_data["proxy"]           = configdata("", configdata::STR);
 	config_data["proxy-auth"]      = configdata("", configdata::STR);
-	config_data["proxy-auth-method"] = configdata("any", "any", "basic", "digest", "digest_ie", "gssnegotiate", "ntlm", "anysafe", NULL);
-	config_data["http-auth-method"] = configdata("any", "any", "basic", "digest", "digest_ie", "gssnegotiate", "ntlm", "anysafe", NULL);
+	config_data["proxy-auth-method"] = configdata("any", std::set<std::string>({"any", "basic", "digest", "digest_ie", "gssnegotiate", "ntlm", "anysafe"}));
+	config_data["http-auth-method"] = configdata("any", std::set<std::string>({"any", "basic", "digest", "digest_ie", "gssnegotiate", "ntlm", "anysafe"}));
 	config_data["confirm-exit"]    = configdata("no", configdata::BOOL);
 	config_data["error-log"]       = configdata("", configdata::PATH);
 	config_data["notify-screen"]   = configdata("no", configdata::BOOL);
@@ -62,7 +50,7 @@ configcontainer::configcontainer() {
 	config_data["notify-program"]  = configdata("", configdata::PATH);
 	config_data["notify-format"]   = configdata(_("newsbeuter: finished reload, %f unread feeds (%n unread articles total)"), configdata::STR);
 	config_data["datetime-format"] = configdata("%b %d", configdata::STR);
-	config_data["urls-source"]     = configdata("local", "local", "opml", "oldreader", "ttrss", "newsblur", "feedhq", NULL); // enum
+	config_data["urls-source"]     = configdata("local", std::set<std::string>({"local", "opml", "oldreader", "ttrss", "newsblur", "feedhq"})); // enum
 	config_data["bookmark-cmd"]    = configdata("", configdata::STR);
 	config_data["opml-url"]        = configdata("", configdata::STR, true);
 	config_data["html-renderer"]   = configdata("internal", configdata::PATH);
@@ -90,7 +78,7 @@ configcontainer::configcontainer() {
 	config_data["history-limit"] = configdata("100", configdata::INT);
 	config_data["prepopulate-query-feeds"] = configdata("false", configdata::BOOL);
 	config_data["goto-first-unread"] = configdata("true", configdata::BOOL);
-	config_data["proxy-type"] = configdata("http", "http", "socks4", "socks4a", "socks5", NULL); // enum
+	config_data["proxy-type"] = configdata("http", std::set<std::string>({"http", "socks4", "socks4a", "socks5"})); // enum
 	config_data["oldreader-login"] = configdata("", configdata::STR);
 	config_data["oldreader-password"] = configdata("", configdata::STR);
 	config_data["oldreader-passwordfile"] = configdata("", configdata::PATH);
@@ -106,7 +94,7 @@ configcontainer::configcontainer() {
 	config_data["feedhq-show-special-feeds"] = configdata("true", configdata::BOOL);
 	config_data["feedhq-min-items"] = configdata("20", configdata::INT);
 	config_data["feedhq-url"] = configdata("https://feedhq.org/", configdata::STR);
-	config_data["ignore-mode"] = configdata("download", "download", "display", NULL); // enum
+	config_data["ignore-mode"] = configdata("download", std::set<std::string>({"download", "display"})); // enum
 	config_data["max-download-speed"] = configdata("0", configdata::INT);
 	config_data["cookie-cache"] = configdata("", configdata::PATH);
 	config_data["download-full-page"] = configdata("false", configdata::BOOL);
@@ -115,7 +103,7 @@ configcontainer::configcontainer() {
 	config_data["ttrss-password"] = configdata("", configdata::STR);
 	config_data["ttrss-passwordfile"] = configdata("", configdata::PATH);
 	config_data["ttrss-url"] = configdata("", configdata::STR);
-	config_data["ttrss-mode"] = configdata("multi", "single", "multi", NULL); // enum
+	config_data["ttrss-mode"] = configdata("multi", std::set<std::string>({"single", "multi"})); // enum
 	config_data["ttrss-flag-star"] = configdata("", configdata::STR);
 	config_data["ttrss-flag-publish"] = configdata("", configdata::STR);
 	config_data["newsblur-login"] = configdata("", configdata::STR);
