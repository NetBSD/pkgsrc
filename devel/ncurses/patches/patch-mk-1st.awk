$NetBSD: patch-mk-1st.awk,v 1.2 2020/03/09 06:16:13 wiz Exp $

Rename form/menu/panel to gnu*.
TODO: use --with-xxx-libname=libnxxx in ncurses 6.3+ instead

--- mk-1st.awk.orig	2020-02-02 23:34:34.000000000 +0000
+++ mk-1st.awk
@@ -69,6 +69,9 @@ function is_termlib() {
 	}
 # see lib_name
 function lib_name_of(a_name) {
+	if (a_name == "form" || a_name == "panel" || a_name == "menu" || a_name == "formw" || a_name == "panelw" || a_name == "menuw")
+		return sprintf("%sgnu%s%s", prefix, a_name, suffix)
+	else
 		return sprintf("%s%s%s", prefix, a_name, suffix)
 	}
 # see imp_name
