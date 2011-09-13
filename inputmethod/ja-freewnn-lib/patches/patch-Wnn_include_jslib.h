$NetBSD: patch-Wnn_include_jslib.h,v 1.1 2011/09/13 07:23:17 mef Exp $

(Almost) Automatic generation to sourceforge cvs Repository 2011/05/31

--- Wnn/include/jslib.h.orig	2005-04-10 15:26:37.000000000 +0000
+++ Wnn/include/jslib.h
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
@@ -42,6 +42,10 @@
 #include <setjmp.h>
 #endif
 
+#ifdef __cplusplus
+extern "C" {
+#endif
+
 #define JLIB_VERSION    0x4003
 
 #ifndef w_char
@@ -399,70 +403,87 @@ struct wnn_file_head
 #define js_open(server, timeout)        js_open_lang(server, "ja_JP", timeout)
 #define js_connect(server,env_name)     js_connect_lang(server, env_name, "ja_JP")
 
-extern WNN_JSERVER_ID *js_open_lang ();
-extern int js_close ();
-extern WNN_JSERVER_ID *js_change_current_jserver ();
-extern struct wnn_env *js_connect_lang ();
-extern int js_disconnect ();
-extern int js_env_list ();
-extern int js_param_set ();
-extern int js_param_get ();
-extern char *js_get_lang ();
+#ifndef FRWNN_PARAMS
+/*
+ * I currently think ANSI-C is not sufficiant on building your clients
+ * linked with libwnn. (aonoto)
+ */
+#if __STDC__		/* Sufficient? */
+#define FRWNN_PARAMS(paramlist)	paramlist
+#else
+#define FRWNN_PARAMS(paramlist)	()
+#endif
+#endif
+
+extern WNN_JSERVER_ID *js_open_lang FRWNN_PARAMS((register char *server, register char *lang, register int timeout));
+extern int js_close      FRWNN_PARAMS((WNN_JSERVER_ID *server));
+/* extern WNN_JSERVER_ID *js_change_current_jserver (); */ /* Not exist? */
+extern struct wnn_env *js_connect_lang FRWNN_PARAMS((WNN_JSERVER_ID *server, register char *env_name, char *lang));
+extern int js_disconnect FRWNN_PARAMS((register struct wnn_env *env));
+extern int js_env_list   FRWNN_PARAMS((WNN_JSERVER_ID *server, struct wnn_ret_buf *ret));
+extern int js_param_set  FRWNN_PARAMS((struct wnn_env *env, register struct wnn_param *para));
+extern int js_param_get  FRWNN_PARAMS((struct wnn_env *env, register struct wnn_param *para));
+extern char *js_get_lang FRWNN_PARAMS((struct wnn_env *env));
 /**************************************/
-extern int js_access ();
-extern int js_dic_add ();
-extern int js_dic_delete ();
-extern int js_dic_file_create ();
-extern int js_dic_file_create_client ();
-extern int js_dic_info ();
-extern int js_dic_list ();
-extern int js_dic_list_all ();
-extern int js_dic_use ();
-extern int js_env_exist ();
-extern int js_env_sticky ();
-extern int js_env_un_sticky ();
-extern int js_file_comment_set ();
-extern int js_file_discard ();
-extern int js_file_info ();
-extern int js_file_list ();
-extern int js_file_list_all ();
-extern int js_file_loaded ();
-extern int js_file_loaded_local ();
-extern int js_file_password_set ();
-extern int js_file_read ();
-extern int js_file_receive ();
-extern int js_file_remove ();
-extern int js_file_remove_client ();
-extern int js_file_send ();
-extern int js_file_stat ();
-extern int js_file_write ();
-extern void js_flush ();
-extern int js_fuzokugo_get ();
-extern int js_fuzokugo_set ();
-extern int js_hindo_file_create ();
-extern int js_hindo_file_create_client ();
-extern int js_hindo_set ();
-extern int js_hinsi_dicts ();
-extern int js_hinsi_list ();
-extern int js_hinsi_name ();
-extern int js_hinsi_number ();
-extern int js_hinsi_table_set ();
-extern int js_isconnect ();
-extern int js_kanren ();
-extern int js_kantan_dai ();
-extern int js_kantan_sho ();
-extern int js_kanzen_dai ();
-extern int js_kanzen_sho ();
-extern int js_kill ();
-extern int js_mkdir ();
-extern int js_version ();
-extern int js_who ();
-extern int js_word_add ();
-extern int js_word_comment_set ();
-extern int js_word_delete ();
-extern int js_word_info ();
-extern int js_word_search ();
-extern int js_word_search_by_env ();
+extern int js_access     FRWNN_PARAMS((struct wnn_env *env, char *path, int amode));
+extern int js_dic_add    FRWNN_PARAMS((struct wnn_env *env, int fid, int hfid, int rev,int jnice, int rw, int hrw, char *pw1, char *pw2));
+extern int js_dic_delete      FRWNN_PARAMS((struct wnn_env *env, int dicno));
+extern int js_dic_file_create FRWNN_PARAMS((struct wnn_env *env, char *fn, int type, w_char *comment, char *passwd, char *hpasswd));
+extern int js_dic_file_create_client FRWNN_PARAMS((struct wnn_env *env, char *fn, int type, w_char *comment, char *passwd, char *hpasswd));
+extern int js_dic_info     FRWNN_PARAMS((struct wnn_env *env, int dic_no, register WNN_DIC_INFO *ret));
+extern int js_dic_list     FRWNN_PARAMS((struct wnn_env *env, struct wnn_ret_buf *ret));
+extern int js_dic_list_all FRWNN_PARAMS((WNN_JSERVER_ID *server, struct wnn_ret_buf *ret));
+extern int js_dic_use      FRWNN_PARAMS((struct wnn_env *env, int dic_no, int flag));
+extern int js_env_exist     FRWNN_PARAMS((register WNN_JSERVER_ID *server, register char *env_name));
+extern int js_env_sticky    FRWNN_PARAMS((register struct wnn_env *env));
+extern int js_env_un_sticky FRWNN_PARAMS((register struct wnn_env *env));
+extern int js_file_comment_set FRWNN_PARAMS((struct wnn_env *env, int fid, w_char *comment));
+extern int js_file_discard FRWNN_PARAMS((struct wnn_env *env, int fid));
+extern int js_file_info    FRWNN_PARAMS((struct wnn_env *env, int fid, register WNN_FILE_INFO_STRUCT *file));
+extern int js_file_list    FRWNN_PARAMS((struct wnn_env *env, struct wnn_ret_buf *ret));
+extern int js_file_list_all FRWNN_PARAMS((WNN_JSERVER_ID *server, struct wnn_ret_buf *ret));
+extern int js_file_loaded  FRWNN_PARAMS((WNN_JSERVER_ID *server, char *path));
+extern int js_file_loaded_local FRWNN_PARAMS((WNN_JSERVER_ID *server, char *path));
+extern int js_file_password_set FRWNN_PARAMS((struct wnn_env *env, int fid, int which, char *old_passwd, char *new_passwd));
+extern int js_file_read    FRWNN_PARAMS((struct wnn_env *env, char *fn));
+extern int js_file_receive FRWNN_PARAMS((struct wnn_env *env, int fid, char *fn));
+extern int js_file_remove  FRWNN_PARAMS((WNN_JSERVER_ID *server, char *n, char *pwd));
+extern int js_file_remove_client FRWNN_PARAMS((WNN_JSERVER_ID *server, char *n, char *pwd));
+extern int js_file_send    FRWNN_PARAMS((struct wnn_env *env, char *fn));
+extern int js_file_stat    FRWNN_PARAMS((struct wnn_env *env, char *path, WNN_FILE_STAT *s));
+extern int js_file_write   FRWNN_PARAMS((struct wnn_env *env, int fid, char *fn));
+extern void js_flush FRWNN_PARAMS((struct wnn_env *env));
+extern int js_fuzokugo_get FRWNN_PARAMS((struct wnn_env *env));
+extern int js_fuzokugo_set FRWNN_PARAMS((struct wnn_env *env, int fid));
+extern int js_hindo_file_create FRWNN_PARAMS((struct wnn_env *env, int fid, char *fn, w_char *comment, char *hpasswd));
+extern int js_hindo_file_create_client FRWNN_PARAMS((struct wnn_env *env, int fid, char *fn, w_char *com, char *hpasswd));
+extern int js_hindo_set    FRWNN_PARAMS((struct wnn_env *env, int dic, int entry, int ima, int hindo));
+extern int js_hinsi_dicts  FRWNN_PARAMS((struct wnn_env *env, int no, struct wnn_ret_buf *rb));
+extern int js_hinsi_list   FRWNN_PARAMS((struct wnn_env *env, int dic_no, w_char *name, struct wnn_ret_buf *rb));
+extern int js_hinsi_name   FRWNN_PARAMS((WNN_JSERVER_ID *server, int no,  struct wnn_ret_buf *rb));
+extern int js_hinsi_number FRWNN_PARAMS((WNN_JSERVER_ID *server, w_char *name));
+extern int js_hinsi_table_set FRWNN_PARAMS((struct wnn_env *env, int dic_no, w_char *hinsi_table));
+extern int js_isconnect FRWNN_PARAMS((register struct wnn_env *env));
+extern int js_kanren FRWNN_PARAMS((struct wnn_env *env, w_char *yomi, int hinsi, w_char *fzk, int vec, int vec1, int vec2, struct wnn_ret_buf *rb));
+extern int js_kantan_dai FRWNN_PARAMS((struct wnn_env *env, w_char *yomi, int hinsi, w_char *fzk, int vec, int vec1, struct wnn_ret_buf *rb));
+extern int js_kantan_sho FRWNN_PARAMS((struct wnn_env *env, w_char *yomi, int hinsi, w_char *fzk, int vec, int vec1, struct wnn_ret_buf *rb));
+extern int js_kanzen_dai FRWNN_PARAMS((struct wnn_env *env, w_char *yomi, int hinsi, w_char *fzk, int vec, int vec1, struct wnn_ret_buf *rb));
+extern int js_kanzen_sho FRWNN_PARAMS((struct wnn_env *env, w_char *yomi, int hinsi, w_char *fzk, int vec, int vec1, struct wnn_ret_buf *rb));
+extern int js_kill    FRWNN_PARAMS((WNN_JSERVER_ID *server));
+extern int js_mkdir   FRWNN_PARAMS((struct wnn_env *env, char *path));
+extern int js_version FRWNN_PARAMS((WNN_JSERVER_ID *server, int *serv, int *libv));
+extern int js_who     FRWNN_PARAMS((WNN_JSERVER_ID *server, struct wnn_ret_buf *ret));
+extern int js_word_add    FRWNN_PARAMS((struct wnn_env *env, int dic_no, w_char *yomi, w_char *kanji, w_char *comment, int hinshi, int init_hindo));
+extern int js_word_comment_set FRWNN_PARAMS((struct wnn_env *env, int dic_no, int entry, w_char *comment));
+extern int js_word_delete FRWNN_PARAMS((struct wnn_env *env, int dic_no, int entry));
+extern int js_word_info   FRWNN_PARAMS((struct wnn_env *env, int dic_no, int entry, struct wnn_ret_buf *ret));
+extern int js_word_search FRWNN_PARAMS((struct wnn_env *env, int dic_no, w_char *yomi, struct wnn_ret_buf *ret));
+extern int js_word_search_by_env FRWNN_PARAMS((struct wnn_env *env, w_char *yomi, struct wnn_ret_buf *ret));
 
+#endif	/* !JSERVER */
+
+#ifdef __cplusplus
+}
 #endif
+
 #endif  /* WNN_JSLIB_H */
