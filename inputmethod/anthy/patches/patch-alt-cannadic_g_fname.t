$NetBSD: patch-alt-cannadic_g_fname.t,v 1.1 2026/09/15 13:00:15 wiz Exp $

Fix the kanji for the novelist Abe Kobo (1924-1993).  The entry reads
"abekoubou" and gives 阿部公房; he wrote his family name 安部公房.

The neighbouring entries in this file already spell 安倍晋三, 安倍晴明
and 安倍なつみ correctly, so this is an isolated slip rather than a
convention the dictionary follows.  Writing a person's name with the
wrong character is a discourtesy in Japanese, and an input method that
offers only the wrong form makes the right one awkward to type.

Taken from Fedora, which has carried this since 2010 as
anthy-fix-typo-in-dict-name.patch.

--- alt-cannadic/g_fname.t.orig
+++ alt-cannadic/g_fname.t
@@ -82,7 +82,7 @@
 あとうだたかし #JN*100 #_4阿刀田_3高
 あなやまこすけ #JN*10 #_4穴山_3小介
 あびるゆう #JN*100 #_3あびる_2優
-あべこうぼう #JN*10 #_2阿部_4公房
+あべこうぼう #JN*10 #_2安部_4公房
 あべしんぞう #JN*100 #_2安倍_4晋三
 あべせいめい #JN*50 #_2安倍_4晴明
 あべなつみ #JN*150 #_2安倍_3なつみ
