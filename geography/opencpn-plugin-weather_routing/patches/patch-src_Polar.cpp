$NetBSD: patch-src_Polar.cpp,v 1.1 2017/02/08 00:05:55 joerg Exp $

Pointers are not relative to 0, so check correct variable.

--- src/Polar.cpp.orig	2017-01-08 19:55:10.199446917 +0000
+++ src/Polar.cpp
@@ -180,7 +180,7 @@ Polar::Polar()
 
 #define MAX_WINDSPEEDS_IN_TABLE 200
 #define MESSAGE(S) (S + wxString(_T("\n")) + wxString::FromUTF8(filename) \
-                    + (line > 0 ? (_(" line ") + wxString::Format(_T("%d"), linenum)) : _T("")))
+                    + (linenum > 0 ? (_(" line ") + wxString::Format(_T("%d"), linenum)) : _T("")))
 #define PARSE_WARNING(S) do { if(message.empty()) message = MESSAGE(S); } while (0)
 #define PARSE_ERROR(S) if(message.empty()) do { message = _("Boat polar failed") + wxString(_T("\n")) \
                                   + MESSAGE(S); goto failed; } while (0)
