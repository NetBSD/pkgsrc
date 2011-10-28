$NetBSD: patch-Switch.pm,v 1.1.1.1 2011/10/28 09:14:41 obache Exp $

* misuses the (;$) prototype
  https://rt.cpan.org/Public/Bug/Display.html?id=60380

--- Switch.pm.orig	2009-10-23 07:52:51.000000000 +0000
+++ Switch.pm
@@ -146,7 +146,7 @@ sub filter_blocks
 				die "Bad $keyword statement (problem in the code block?) near $Switch::file line ", line(substr($source,0, pos $source), $line), "\n";
 			};
 			my $code = filter_blocks(substr($source,$pos[0],$pos[4]-$pos[0]),line(substr($source,0,$pos[0]),$line));
-			$code =~ s/{/{ local \$::_S_W_I_T_C_H; Switch::switch $arg;/;
+			$code =~ s/{/{ local \$::_S_W_I_T_C_H; Switch::switch($arg);/;
 			$text .= $code . 'continue {last}';
 			next component;
 		}
