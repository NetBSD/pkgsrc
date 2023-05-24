$NetBSD: patch-texk_web2c_luatexdir_luafontloader_src_luafflib.c,v 1.1 2023/05/24 12:03:35 markd Exp $

1.16.0 -> 1.17.0

--- texk/web2c/luatexdir/luafontloader/src/luafflib.c	2023/05/01 23:50:21	66983
+++ texk/web2c/luatexdir/luafontloader/src/luafflib.c	2023/05/02 15:26:43	66984
@@ -1236,7 +1236,6 @@ static void handle_pfminfo(lua_State * L
     dump_intfield(L, "vlinegap", pfm.vlinegap);
     dump_intfield(L, "hhead_ascent", pfm.hhead_ascent);
     dump_intfield(L, "hhead_descent", pfm.hhead_descent);
-    dump_intfield(L, "hhead_descent", pfm.hhead_descent);
     dump_intfield(L, "os2_typoascent", pfm.os2_typoascent);
     dump_intfield(L, "os2_typodescent", pfm.os2_typodescent);
     dump_intfield(L, "os2_typolinegap", pfm.os2_typolinegap);
