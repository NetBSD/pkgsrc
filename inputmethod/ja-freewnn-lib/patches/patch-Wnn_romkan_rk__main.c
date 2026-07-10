$NetBSD: patch-Wnn_romkan_rk__main.c,v 1.2 2026/07/10 23:32:38 tsutsui Exp $

- Appease -Wchar-subscripts
- Use proper function prototypes for -std=gnu23

--- Wnn/romkan/rk_main.c.orig	2013-09-02 11:01:39.000000000 +0000
+++ Wnn/romkan/rk_main.c
@@ -68,9 +68,9 @@ letter *codeout, *remainkbf;
 letter ungetc_buf = EOLTTR;     /* romkan_ungetcが一文字退避しておくバッファ */
 letter unnext_buf = EOLTTR;     /* romkan_unnextが            〃             */
 
-letter (*keyin_method) ();      /* キーイン関数のアドレス */
-int (*bytcnt_method) ();        /* バイトカウント関数のアドレス */
-int (*kbytcnt_method) ();       /* キー入力解釈用バイトカウント関数のアドレス */
+letter (*keyin_method) FRWNN_PARAMS((void));     /* キーイン関数のアドレス */
+int (*bytcnt_method) FRWNN_PARAMS((uns_chr *));  /* バイトカウント関数のアドレス */
+int (*kbytcnt_method) FRWNN_PARAMS((uns_chr *)); /* キー入力解釈用バイトカウント関数のアドレス */
 char prv_modfnm[REALFN] = "\0"; /* モード表名（又はそのパス名）を保存 */
             /* 初期設定がいい加減! */
 
@@ -88,7 +88,7 @@ char eofflg;                    /* romka
                                    処理中はeofflgは2。 */
 
 letter evalbuf[2][2][OUTSIZ];
-char ebf_sw = 0;
+int ebf_sw = 0;
 letter saishu_out[OUTSIZ];
 letter delchr, delchr2 = EOLTTR, nisedl;        /* DELのキャラクタは二個まで持てる */
 
@@ -132,8 +132,8 @@ extern void readdata FRWNN_PARAMS((lette
   handakuadd FRWNN_PARAMS((letter,letter**)),
   allchgmod FRWNN_PARAMS((modetyp));
 extern int ltov FRWNN_PARAMS((letter));
-int romkan_init2 FRWNN_PARAMS((char*,letter,char,letter(*keyinfn)(),int(*bytcntfn)(),char,char,char));
-int romkan_init3 FRWNN_PARAMS((char*,letter,letter,letter,letter(*keyinfn)(),int(*bytcntfn)(),int(*kbytcntfn)(),char,int));
+int romkan_init2 FRWNN_PARAMS((char*,letter,char,letter(*keyinfn) (void),int(*bytcntfn) (uns_chr *),char,char,char));
+int romkan_init3 FRWNN_PARAMS((char*,letter,letter,letter,letter(*keyinfn) (void),int(*bytcntfn) (uns_chr *),int(*kbytcntfn) (uns_chr *),char,int));
 
 static letter *
 ltrcpy (lp1, lp2)
@@ -457,8 +457,8 @@ int
 romkan_init (modhyo, delchr_, chmoutf, keyinfn, bytcntfn)
      char *modhyo, chmoutf;
      letter delchr_;
-letter (*keyinfn) ();
-     int (*bytcntfn) ();        /* 引数の詳細はromkan_init3を参照 */
+     letter (*keyinfn) FRWNN_PARAMS((void));
+     int (*bytcntfn) FRWNN_PARAMS((uns_chr *)); /* 引数の詳細はromkan_init3を参照 */
 {
   return (romkan_init2 (modhyo, delchr_, chmoutf, keyinfn, bytcntfn, 0, 0, 0));
 }
@@ -471,11 +471,11 @@ int
 romkan_init2 (modhyo, delchr_, chmoutf, keyinfn, bytcntfn, keyackf, restartf, nonisecodf)
      char *modhyo, chmoutf, keyackf, restartf, nonisecodf;
      letter delchr_;
-letter (*keyinfn) ();
-     int (*bytcntfn) ();        /* 引数の詳細はromkan_init3を参照 */
+     letter (*keyinfn) FRWNN_PARAMS((void));
+     int (*bytcntfn) FRWNN_PARAMS((uns_chr *)); /* 引数の詳細はromkan_init3を参照 */
 {
   return (romkan_init3 (modhyo, delchr_, toNISE (delchr_), EOLTTR,
-                        keyinfn, bytcntfn, (int (*)()) NULL, restartf, ifflg (chmoutf, RK_CHMOUT) | ifflg (keyackf, RK_KEYACK) | ifflg (nonisecodf, RK_NONISE) | RK_DSPNIL));
+                        keyinfn, bytcntfn, (int (*) FRWNN_PARAMS((uns_chr *))) NULL, restartf, ifflg (chmoutf, RK_CHMOUT) | ifflg (keyackf, RK_KEYACK) | ifflg (nonisecodf, RK_NONISE) | RK_DSPNIL));
 }
 
  /**    表を読み込んで変換の初期設定をする。（part 3）*/
@@ -485,10 +485,10 @@ romkan_init3 (modhyo, delchr_, nisedl_, 
      letter delchr_;            /* DELとして使うコード */
      letter nisedl_;            /* 偽DELとして使うコード */
      letter delchr2_;           /* DELとして使うコードが二つある場合そのもう一方 */
-letter (*keyinfn) ();           /* キーイン関数 */
-     int (*bytcntfn) ();        /* バイトカウント関数 */
-     int (*kbytcntfn) ();       /* キーインの解釈用バイトカウント関数。NULL指定の時は
-                                   bytcntfnと同じものが使われる */
+     letter (*keyinfn) FRWNN_PARAMS((void));     /* キーイン関数 */
+     int (*bytcntfn) FRWNN_PARAMS((uns_chr *));  /* バイトカウント関数 */
+     int (*kbytcntfn) FRWNN_PARAMS((uns_chr *)); /* キーインの解釈用バイトカウント関数。NULL指定の時は
+                                                    bytcntfnと同じものが使われる */
      char restartf;
  /*     rk_rst()内から呼ばれた時に立つフラグ。これが立つと、バッファをクリア
     せずに済ます。この時はエラー検出時のメッセージも少し異なる */
