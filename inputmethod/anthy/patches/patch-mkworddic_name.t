$NetBSD: patch-mkworddic_name.t,v 1.1 2026/09/15 13:00:15 wiz Exp $

Fix the kanji for the novelist Abe Kobo (1924-1993).  The entry reads
"abekoubou" and gives é˜¿éƒ¨å…¬æˆ¿; he wrote his family name å®‰éƒ¨å…¬æˆ¿.

The neighbouring entries in this file already spell å®‰å€æ™‹ä¸‰, å®‰å€æ™´æ˜
and å®‰å€ãªã¤ã¿ correctly, so this is an isolated slip rather than a
convention the dictionary follows.  Writing a person's name with the
wrong character is a discourtesy in Japanese, and an input method that
offers only the wrong form makes the right one awkward to type.

Taken from Fedora, which has carried this since 2010 as
anthy-fix-typo-in-dict-name.patch.

--- mkworddic/name.t.orig
+++ mkworddic/name.t
@@ -43,7 +43,7 @@
 ¤¢¤È¤¦¤À¤¿¤«¤· #JN #_4°¤ÅáÅÄ_3¹â
 ¤¢¤Ê¤ó #JN ¥¢¥Ê¥ó
 ¤¢¤Ó¤ë¤æ¤¦ #JN #_3¤¢¤Ó¤ë_2Í¥
-¤¢¤Ù¤³¤¦¤Ü¤¦ #JN #_2°¤Éô_4¸øË¼
+¤¢¤Ù¤³¤¦¤Ü¤¦ #JN #_2°ÂÉô_4¸øË¼
 ¤¢¤Ù¤·¤å¤·¤ç¤¦ #JN #_2°ÂÇÜ_5¼óÁê
 ¤¢¤Ù¤·¤ó¤¾¤¦ #JN #_2°ÂÇÜ_4¿¸»°
 ¤¢¤Ù¤½¤¦¤ê #JN #_2°ÂÇÜ_3ÁíÍı
