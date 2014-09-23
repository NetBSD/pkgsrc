$NetBSD: patch-libs_gccv_text.cc,v 1.1 2014/09/23 14:33:40 jperkin Exp $

Avoid "call of overloaded 'abs(unsigned int)' is ambiguous".

--- libs/gccv/text.cc.orig	2012-08-11 12:41:27.000000000 +0000
+++ libs/gccv/text.cc
@@ -1208,7 +1208,7 @@ bool Text::OnKeyPressed (GdkEventKey *ev
 	case GDK_Delete:
 	case GDK_KP_Delete: {
 		if (m_CurPos != m_StartSel) {
-			ReplaceText (empty_st, MIN (m_CurPos, m_StartSel), abs (m_CurPos - m_StartSel));
+			ReplaceText (empty_st, MIN (m_CurPos, m_StartSel), abs ((float)m_CurPos - m_StartSel));
 			if (client)
 				client->TextChanged (m_CurPos);
 			break;
@@ -1228,7 +1228,7 @@ bool Text::OnKeyPressed (GdkEventKey *ev
 		break;
 	case GDK_BackSpace: {
 		if (m_CurPos != m_StartSel) {
-			ReplaceText (empty_st, MIN (m_CurPos, m_StartSel), abs (m_CurPos - m_StartSel));
+			ReplaceText (empty_st, MIN (m_CurPos, m_StartSel), abs ((float)m_CurPos - m_StartSel));
 			if (client)
 				client->TextChanged (m_CurPos);
 			break;
