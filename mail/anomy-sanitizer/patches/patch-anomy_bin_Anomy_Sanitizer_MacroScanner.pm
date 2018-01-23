$NetBSD: patch-anomy_bin_Anomy_Sanitizer_MacroScanner.pm,v 1.1 2018/01/23 01:28:02 christos Exp $

New version of perl wants escaped braces

--- bin/Anomy/Sanitizer/MacroScanner.pm.orig	2001-12-21 21:47:58.000000000 -0500
+++ bin/Anomy/Sanitizer/MacroScanner.pm	2018-01-22 20:19:51.344624389 -0500
@@ -117,14 +117,14 @@
             $score += 99 while ($buff =~ s/\000(VirusProtection)/x$1/i);
             $score += 99 while ($buff =~ s/\000(select\s[^\000]*shell\s*\()/x$1/i);
             $score +=  9 while ($buff =~ s/\000(regedit|SaveNormalPrompt|Outlook.Application\000)/x$1/i);
-            $score +=  4 while ($buff =~ s/\000(ID="{[-0-9A-F]+)$/x$1/i);
+            $score +=  4 while ($buff =~ s/\000(ID="\{[-0-9A-F]+)$/x$1/i);
             $score +=  4 while ($buff =~ s/\000(CreateObject)/x$1/i);
             $score +=  4 while ($buff =~ s/(?:\000|\004)(([a-z0-9_]\.)*(Autoexec|Workbook_(Open|BeforeClose)|Document_(Open|New|Close)))/x$1/i);
             $score +=  4 while ($buff =~ s/(?:\000|\004)(Logon|AddressLists|AddressEntries|Recipients|Subject|Body|Attachments|Logoff)/x$1/i);
             $score +=  2 while ($buff =~ s/\000(Shell|Options|CodeModule)/x$1/i);
             $score +=  2 while ($buff =~ s/\000(([a-z]+\.)?Application\000)/x$1/i);
             $score +=  2 while ($buff =~ s/(?:\000|\004)(stdole|NormalTemplate)/x$1/i);
-            $score +=  1 while ($buff =~ s/\000(ID="{[-0-9A-F]+}"|ThisWorkbook\000|PrivateProfileString)/x$1/i);
+            $score +=  1 while ($buff =~ s/\000(ID="\{[-0-9A-F]+}"|ThisWorkbook\000|PrivateProfileString)/x$1/i);
             $score +=  1 while ($buff =~ s/(?:\000|\004)(ActiveDocument|ThisDocument)/x$1/i);
             $score +=  1 while ($buff =~ s/\000(\[?HKEY_(CLASSES_ROOT|CURRENT_USER|LOCAL_MACHINE))/x$1/);
 
