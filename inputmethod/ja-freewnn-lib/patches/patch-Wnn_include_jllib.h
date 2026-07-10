$NetBSD: patch-Wnn_include_jllib.h,v 1.4 2026/07/10 23:32:37 tsutsui Exp $

- Use proper function prototypes including function pointers

--- Wnn/include/jllib.h.orig	2015-05-10 01:39:27.000000000 +0000
+++ Wnn/include/jllib.h
@@ -260,7 +260,7 @@ extern struct wnn_jdata *jl_word_info_e 
 extern w_char *jl_hinsi_name_e FRWNN_PARAMS((register struct wnn_env *env, register int no));
 
 extern void jl_close FRWNN_PARAMS((register struct wnn_buf *buf));
-extern int jl_dic_add_e FRWNN_PARAMS((register struct wnn_env *env, char *dic_name, char *hindo_name, int rev, int prio, int rw, int hrw, char *pwd_dic, char *pwd_hindo, int (*error_handler) (), int (*message_handler) () ));
+extern int jl_dic_add_e FRWNN_PARAMS((register struct wnn_env *env, char *dic_name, char *hindo_name, int rev, int prio, int rw, int hrw, char *pwd_dic, char *pwd_hindo, int (*error_handler) (const char *), int (*message_handler) (const char *)));
 extern int jl_dic_comment_set_e FRWNN_PARAMS((register struct wnn_env *env, int dic_no, w_char *comment));
 extern int jl_dic_delete_e FRWNN_PARAMS((register struct wnn_env *env, register int dic_no));
 extern int jl_dic_list_e   FRWNN_PARAMS((struct wnn_env *env, WNN_DIC_INFO **dicinfo));
