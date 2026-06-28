$NetBSD: patch-Xwnmo_romkan__m_rk__main.c,v 1.1 2026/06/28 06:16:28 tsutsui Exp $

- Appease "comparison between pointer and integer" warning
- Appease -Wchar-subscripts warnings/errors

--- Xwnmo/romkan_m/rk_main.c.orig	2026-06-23 18:36:18.699420637 +0000
+++ Xwnmo/romkan_m/rk_main.c
@@ -452,7 +452,7 @@ rk_buf_init ()
   p->ungetc_buf = EOLTTR;
   p->unnext_buf = EOLTTR;
   p->delchr2 = EOLTTR;
-  p->ebf_sw = NULL;
+  p->ebf_sw = 0;
   p->oneletter[0] = p->oneletter[1] = EOLTTR;
   p->keybuf[0] = p->urabuf[0] = p->disout[0] = p->rk_output[0] = EOLTTR;
   p->rk_table = (RomkanTable *) NULL;
@@ -1753,7 +1753,7 @@ henkan_ok ()
                                    match()がurabufなどの調整をする。 */
   fast letter *p;               /* V3.1 */
 #ifndef MULTI
-  static char ebf_sw = 0;       /* V3.1 */
+  static int ebf_sw = 0;        /* V3.1 */
   static letter oneletter[2] = { EOLTTR, EOLTTR };      /* V3.1 */
 #endif /*!MULTI */
 
