$NetBSD: patch-lib_Mail_SpamAssassin_PerMsgStatus.pm,v 1.3 2017/07/09 22:12:12 schmonz Exp $

Apply upstream patch (SVN rev 1791010) to fix "Unescaped left brace in
regex is deprecated here (and will be fatal in Perl 5.30)".

--- lib/Mail/SpamAssassin/PerMsgStatus.pm.orig	2015-04-28 19:56:49.000000000 +0000
+++ lib/Mail/SpamAssassin/PerMsgStatus.pm
@@ -914,16 +914,16 @@ sub get_content_preview {
     $str .= shift @{$ary};
   }
   undef $ary;
-  chomp ($str); $str .= " [...]\n";
 
   # in case the last line was huge, trim it back to around 200 chars
   local $1;
-  $str =~ s/^(.{,200}).*$/$1/gs;
+  $str =~ s/^(.{200}).+$/$1 [...]/gm;
+  chomp ($str); $str .= "\n";
 
   # now, some tidy-ups that make things look a bit prettier
-  $str =~ s/-----Original Message-----.*$//gs;
+  $str =~ s/-----Original Message-----.*$//gm;
   $str =~ s/This is a multi-part message in MIME format\.//gs;
-  $str =~ s/[-_\*\.]{10,}//gs;
+  $str =~ s/[-_*.]{10,}//gs;
   $str =~ s/\s+/ /gs;
 
   # add "Content preview:" ourselves, so that the text aligns
