$NetBSD: patch-dist_Locale-Maketext_lib_Locale_Maketext.pm,v 1.1 2012/12/12 10:13:47 spz Exp $

patch for SA51498 taken from:
http://perl5.git.perl.org/perl.git/commitdiff/1735f6f53ca19f99c6e9e39496c486af323ba6a8?hp=569ba91fcdabdc53eb4284f860a25273bd7fe4e1

--- dist/Locale-Maketext/lib/Locale/Maketext.pm.orig	2012-10-11 18:20:45.000000000 +0000
+++ dist/Locale-Maketext/lib/Locale/Maketext.pm	2012-12-12 09:26:29.000000000 +0000
@@ -625,21 +625,9 @@ sub _compile {
                         # 0-length method name means to just interpolate:
                         push @code, ' (';
                     }
-                    elsif($m =~ /^\w+(?:\:\:\w+)*$/s
-                            and $m !~ m/(?:^|\:)\d/s
-                        # exclude starting a (sub)package or symbol with a digit
+                    elsif($m =~ /^\w+$/s
+                        # exclude anything fancy, especially fully-qualified module names
                     ) {
-                        # Yes, it even supports the demented (and undocumented?)
-                        #  $obj->Foo::bar(...) syntax.
-                        $target->_die_pointing(
-                            $string_to_compile, q{Can't use "SUPER::" in a bracket-group method},
-                            2 + length($c[-1])
-                        )
-                        if $m =~ m/^SUPER::/s;
-                        # Because for SUPER:: to work, we'd have to compile this into
-                        #  the right package, and that seems just not worth the bother,
-                        #  unless someone convinces me otherwise.
-
                         push @code, ' $_[0]->' . $m . '(';
                     }
                     else {
@@ -693,7 +681,9 @@ sub _compile {
             elsif(substr($1,0,1) ne '~') {
                 # it's stuff not containing "~" or "[" or "]"
                 # i.e., a literal blob
-                $c[-1] .= $1;
+                my $text = $1;
+                $text =~ s/\\/\\\\/g;
+                $c[-1] .= $text;
 
             }
             elsif($1 eq '~~') { # "~~"
@@ -731,7 +721,9 @@ sub _compile {
             else {
                 # It's a "~X" where X is not a special character.
                 # Consider it a literal ~ and X.
-                $c[-1] .= $1;
+                my $text = $1;
+                $text =~ s/\\/\\\\/g;
+                $c[-1] .= $text;
             }
         }
     }
