$NetBSD: patch-Markdown.pl,v 1.1 2024/01/09 13:34:50 sborrill Exp $

Patch from Debian to exit with non-zero exit code if the input file cannot
be opened:

https://metadata.ftp-master.debian.org/changelogs//main/m/markdown/markdown_1.0.

--- Markdown.pl.orig	2004-12-14 22:57:42.000000000 +0000
+++ Markdown.pl	2024-01-09 13:31:50.483232360 +0000
@@ -215,7 +215,7 @@
 		my $text;
 		{
 			local $/;               # Slurp the whole file
-			$text = <>;
+			defined($text = <>) or exit 2;
 		}
         print Markdown($text);
     }
