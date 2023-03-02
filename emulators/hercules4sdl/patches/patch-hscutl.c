$NetBSD: patch-hscutl.c,v 1.1 2023/03/02 17:05:12 rhialto Exp $

Pulled up a patch from the current development version.
As discussed in the hercules-390 mailing list, of which the archives are
currently members-only:
https://hercules-390.groups.io/g/group/message/5475

commit 2d443708f596dec8953758cabb4999c840f0d093
Author: Fish (David B. Trout) <fish@infidels.org>
Date:   Sat Feb 25 13:16:37 2023 -0800

    Fix my careless bug causing MVT to fail!

diff --git a/hscutl.c b/hscutl.c
index 5e61e0f4..262ae056 100644
--- hscutl.c
+++ hscutl.c
@@ -2024,7 +2024,10 @@ DLL_EXPORT U64 do_make_psw64( PSW* psw, BYTE real_ilc, int arch /*370/390/900*/,
             b23 = psw->intcode;
 
             b4 = 0
-                 | (real_ilc     << 6)
+                 | ((real_ilc >> 1) << 6)   // CAREFUL! Herc's ilc value
+                                            // is the ACTUAL length (2,
+                                            // 4 or 6), but the value in
+                                            // the PSW is either 1,2,3!)
                  | (psw->cc << 4)
                  |  psw->progmask
                  ;
