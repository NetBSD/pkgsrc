$NetBSD: patch-Wnn_include_jllib.h,v 1.1 2011/09/13 07:23:17 mef Exp $

(Almost) Automatic generation to sourceforge cvs Repository 2011/05/31

--- Wnn/include/jllib.h.orig	2005-04-10 15:26:37.000000000 +0000
+++ Wnn/include/jllib.h
@@ -10,9 +10,9 @@
  *                 1987, 1988, 1989, 1990, 1991, 1992
  * Copyright OMRON Corporation. 1987, 1988, 1989, 1990, 1991, 1992, 1999
  * Copyright ASTEC, Inc. 1987, 1988, 1989, 1990, 1991, 1992
- * Copyright FreeWnn Project 1999, 2000
+ * Copyright FreeWnn Project 1999, 2000, 2008
  *
- * Maintainer:  FreeWnn Project   <freewnn@tomo.gr.jp>
+ * Maintainer:  FreeWnn Project
  *
  * This library is free software; you can redistribute it and/or
  * modify it under the terms of the GNU Lesser General Public
@@ -39,6 +39,9 @@
 
 #include "jslib.h"
 
+#ifdef __cplusplus
+extern "C" {
+#endif
 
 /*
    ユーザープログラムは、直接この構造体の内容をアクセスする必要は無いはず。
@@ -248,59 +251,65 @@ struct wnn_buf
 #define jl_set_lang(buf, lang)  js_set_lang((buf)->env, lang)
 
 /* extern function defines */
-extern struct wnn_buf *jl_open_lang ();
-extern struct wnn_env *jl_connect_lang ();
-extern struct wnn_env *jl_env_get ();
-extern struct wnn_jdata *jl_word_info_e ();
-extern w_char *jl_hinsi_name_e ();
-
-extern void jl_close ();
-extern int jl_dic_add_e ();
-extern int jl_dic_comment_set_e ();
-extern int jl_dic_delete_e ();
-extern int jl_dic_list_e ();
-extern int jl_dic_save_all_e ();
-extern int jl_dic_save_e ();
-extern int jl_dic_use_e ();
-extern void jl_disconnect ();
-extern void jl_disconnect_if_server_dead ();
-extern void jl_env_set ();
-extern int jl_fuzokugo_get_e ();
-extern int jl_fuzokugo_set_e ();
-extern void jl_get_zenkouho_kanji ();
-extern int jl_hinsi_dicts_e ();
-extern int jl_hinsi_list_e ();
-extern int jl_hinsi_number_e ();
-extern int jl_isconnect_e ();
-extern int jl_kanji_len ();
-extern int jl_kill ();
-extern int jl_nobi_conv ();
-extern int jl_nobi_conv_e2 ();
-extern int jl_param_get_e ();
-extern int jl_param_set_e ();
-extern int jl_ren_conv ();
-extern int jl_set_env_wnnrc ();
-extern int jl_set_env_wnnrc1 ();
-extern int jl_set_jikouho ();
-extern int jl_set_jikouho_dai ();
-extern int jl_tan_conv ();
-extern int jl_update_hindo ();
-extern int jl_word_add_e ();
-extern int jl_word_comment_set_e ();
-extern int jl_word_delete_e ();
-extern int jl_word_search_by_env_e ();
-extern int jl_word_search_e ();
-extern int jl_word_use_e ();
-extern int jl_yomi_len ();
-extern int jl_zenkouho ();
-extern int jl_zenkouho_dai ();
-extern int wnn_get_area ();
+/* Note: FRWNN_PARAMS is defined in jslib.h . */
+
+extern struct wnn_buf *jl_open_lang    FRWNN_PARAMS((char *env_n, char *server_n, char *lang, char *wnnrc_n, int (*error_handler) (), int (*message_handler) (), int timeout));
+extern struct wnn_env *jl_connect_lang FRWNN_PARAMS((register char *env_n, register char *server_n, register char *lang, register char *wnnrc_n,  int (*error_handler) (), int (*message_handler) (), int timeout));
+extern struct wnn_env *jl_env_get      FRWNN_PARAMS((register struct wnn_buf *buf));
+extern struct wnn_jdata *jl_word_info_e FRWNN_PARAMS((register struct wnn_env *env, int dic_no, int entry));
+extern w_char *jl_hinsi_name_e FRWNN_PARAMS((register struct wnn_env *env, register int no));
+
+extern void jl_close FRWNN_PARAMS((register struct wnn_buf *buf));
+extern int jl_dic_add_e FRWNN_PARAMS((register struct wnn_env *env, char *dic_name, char *hindo_name, int rev, int prio, int rw, int hrw, char *pwd_dic, char *pwd_hindo, int (*error_handler) (), int (*message_handler) () ));
+extern int jl_dic_comment_set_e FRWNN_PARAMS((register struct wnn_env *env, int dic_no, w_char *comment));
+extern int jl_dic_delete_e FRWNN_PARAMS((register struct wnn_env *env, register int dic_no));
+extern int jl_dic_list_e   FRWNN_PARAMS((struct wnn_env *env, WNN_DIC_INFO **dicinfo));
+extern int jl_dic_save_all_e FRWNN_PARAMS((struct wnn_env *env));
+extern int jl_dic_save_e   FRWNN_PARAMS((register struct wnn_env *env, int dic_no));
+extern int jl_dic_use_e    FRWNN_PARAMS((struct wnn_env *env, int dic_no, int flag));
+extern void jl_disconnect FRWNN_PARAMS((register struct wnn_env *env));
+extern void jl_disconnect_if_server_dead FRWNN_PARAMS((register struct wnn_env *env));
+extern void jl_env_set FRWNN_PARAMS((register struct wnn_buf *buf, register struct wnn_env *env));
+extern int jl_fuzokugo_get_e FRWNN_PARAMS((register struct wnn_env *env, char *fname));
+extern int jl_fuzokugo_set_e FRWNN_PARAMS((struct wnn_env *env, char *fname));
+extern void jl_get_zenkouho_kanji FRWNN_PARAMS((register struct wnn_buf *buf, int zen_num, w_char *area));
+extern int jl_hinsi_dicts_e  FRWNN_PARAMS((register struct wnn_env *env, int no, int **area));
+extern int jl_hinsi_list_e   FRWNN_PARAMS((register struct wnn_env *env, int dic_no, w_char *name, w_char ***area));
+extern int jl_hinsi_number_e FRWNN_PARAMS((register struct wnn_env *env, w_char *name));
+extern int jl_isconnect_e FRWNN_PARAMS((register struct wnn_env *env));
+extern int jl_kanji_len FRWNN_PARAMS((struct wnn_buf *buf, register int bun_no, register int bun_no2));
+extern int jl_kill FRWNN_PARAMS((struct wnn_buf *buf, register int bun_no, register int bun_no2));
+extern int jl_nobi_conv    FRWNN_PARAMS((register struct wnn_buf *buf, register int bun_no, int ichbn_len, register int bun_no2, int use_maep, int ich_shop));
+extern int jl_nobi_conv_e2 FRWNN_PARAMS((register struct wnn_buf *buf, struct wnn_env *env, register int bun_no, int ichbn_len, register int bun_no2, int use_maep, int ich_shop));
+extern int jl_param_get_e FRWNN_PARAMS((struct wnn_env *env, struct wnn_param *para));
+extern int jl_param_set_e FRWNN_PARAMS((register struct wnn_env *env, struct wnn_param *para));
+extern int jl_ren_conv FRWNN_PARAMS((register struct wnn_buf *buf, register w_char *yomi, int bun_no, int bun_no2, int use_maep));
+extern int jl_set_env_wnnrc  FRWNN_PARAMS((register struct wnn_env *env, char *wnnrc_n, int (*error_handler) (), int (*message_handler) () ));
+extern int jl_set_env_wnnrc1 FRWNN_PARAMS((register struct wnn_env *env, char *wnnrc_n, int (*error_handler) (), int (*message_handler) (), int level));
+extern int jl_set_jikouho     FRWNN_PARAMS((register struct wnn_buf *buf, register int offset));
+extern int jl_set_jikouho_dai FRWNN_PARAMS((register struct wnn_buf *buf, int offset));
+extern int jl_tan_conv FRWNN_PARAMS((register struct wnn_buf *buf, w_char *yomi, register int bun_no, register int bun_no2, int use_maep, int ich_shop));
+extern int jl_update_hindo FRWNN_PARAMS((register struct wnn_buf *buf, int bun_no, int bun_no2));
+extern int jl_word_add_e         FRWNN_PARAMS((struct wnn_env *env, int dic_no, w_char *yomi, w_char *kanji, w_char *comment, int hinsi, int init_hindo));
+extern int jl_word_comment_set_e FRWNN_PARAMS((register struct wnn_env *env, int dic_no, int entry, w_char *comment));
+extern int jl_word_delete_e      FRWNN_PARAMS((struct wnn_env *env, int dic_no, int entry));
+extern int jl_word_search_by_env_e FRWNN_PARAMS((register struct wnn_env *env, w_char *yomi, struct wnn_jdata **jdp));
+extern int jl_word_search_e      FRWNN_PARAMS((register struct wnn_env *env, int dic_no, w_char *yomi, struct wnn_jdata **jdp));
+extern int jl_word_use_e         FRWNN_PARAMS((register struct wnn_env *env, int dic_no, int entry));
+extern int jl_yomi_len FRWNN_PARAMS((struct wnn_buf *buf, register int bun_no, register int bun_no2));
+extern int jl_zenkouho     FRWNN_PARAMS((register struct wnn_buf *buf, int bun_no, int use_maep, int uniq_level));
+extern int jl_zenkouho_dai FRWNN_PARAMS((register struct wnn_buf *buf, int bun_no, int bun_no2, int use_maep, int uniq_level));
+extern int wnn_get_area FRWNN_PARAMS((struct wnn_buf *buf, register int bun_no, register int bun_no2, w_char *area, int kanjip));
 
-extern char *wnn_perror ();
-extern char *wnn_perror_lang ();
+extern char *wnn_perror      FRWNN_PARAMS((void));
+extern char *wnn_perror_lang FRWNN_PARAMS((char *lang));
 
 #ifdef  CONVERT_by_STROKE
-extern void jl_get_zenkouho_yomi ();
+extern void jl_get_zenkouho_yomi FRWNN_PARAMS((register struct wnn_buf *buf, int zen_num, w_char *area));
+#endif
+
+#ifdef __cplusplus
+}
 #endif
 
 #endif  /* WNN_JLLIB_H */
