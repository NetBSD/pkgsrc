$NetBSD: patch-fltk_main.cxx,v 1.1 2019/02/13 17:39:36 wiz Exp $

Handle '_' in labels as keyboard shortcuts (used by GPG2).
Fix format string handling (Patch from Debian).

--- fltk/main.cxx.orig	2017-12-03 16:13:05.000000000 +0000
+++ fltk/main.cxx
@@ -78,6 +78,44 @@ static std::string escape_accel_utf8(con
 	return result;
 }
 
+// For button labels
+// Accelerator '_' (used e.g. by GPG2) is converted to '&' (for FLTK)
+// '&' is escaped as in escape_accel_utf8()
+static std::string convert_accel_utf8(const char *s)
+{
+	static bool last_was_underscore = false;
+	std::string result;
+	if (NULL != s)
+	{
+		result.reserve(strlen(s));
+		for (const char *p = s; *p; ++p)
+		{
+			// & => &&
+			if ('&' == *p)
+				result.push_back(*p);
+			// _ => & (handle '__' as escaped underscore)
+			if ('_' == *p)
+			{
+				if (last_was_underscore)
+				{
+					result.push_back(*p);
+					last_was_underscore = false;
+				}
+				else
+					last_was_underscore = true;
+			}
+			else
+			{
+				if (last_was_underscore)
+					result.push_back('&');
+				result.push_back(*p);
+				last_was_underscore = false;
+			}
+		}
+	}
+	return result;
+}
+
 class cancel_exception
 {
 
@@ -111,8 +149,8 @@ static int fltk_cmd_handler(pinentry_t p
 		// TODO: Add parent window to pinentry-fltk window
 		//if (pe->parent_wid){}
 		std::string title  = !is_empty(pe->title)?pe->title:PGMNAME;
-		std::string ok 	   = escape_accel_utf8(pe->ok?pe->ok:(pe->default_ok?pe->default_ok:OK_STRING));
-		std::string cancel = escape_accel_utf8(pe->cancel?pe->cancel:(pe->default_cancel?pe->default_cancel:CANCEL_STRING));
+		std::string ok 	   = convert_accel_utf8(pe->ok?pe->ok:(pe->default_ok?pe->default_ok:OK_STRING));
+		std::string cancel = convert_accel_utf8(pe->cancel?pe->cancel:(pe->default_cancel?pe->default_cancel:CANCEL_STRING));
 
 		if (!!pe->pin) // password (or confirmation)
 		{
@@ -241,12 +279,12 @@ static int fltk_cmd_handler(pinentry_t p
 				if (pe->one_button)
 				{
 					fl_ok = ok.c_str();
-					fl_message(message);
+					fl_message("%s", message);
 					result = 1; // OK
 				}
 				else if (pe->notok)
 				{
-					switch (fl_choice(message, ok.c_str(), cancel.c_str(), pe->notok))
+					switch (fl_choice("%s", ok.c_str(), cancel.c_str(), pe->notok, message))
 					{
 					case 0: result = 1; break;
 					case 2: result = 0; break;
@@ -256,7 +294,7 @@ static int fltk_cmd_handler(pinentry_t p
 				}
 				else
 				{
-					switch (fl_choice(message, ok.c_str(), cancel.c_str(), NULL))
+					switch (fl_choice("%s", ok.c_str(), cancel.c_str(), NULL, message))
 					{
 					case 0: result = 1; break;
 					default:
