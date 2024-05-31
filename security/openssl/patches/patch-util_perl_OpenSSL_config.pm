$NetBSD: patch-util_perl_OpenSSL_config.pm,v 1.3 2024/05/31 16:22:21 cheusov Exp $

a strategic chomp makes openssl on NetBSD/i386 configure

fix default platform id (linux-ppc64) for big-endian PowerPC-based Linux

--- util/perl/OpenSSL/config.pm.orig	2024-04-09 12:12:22.000000000 +0000
+++ util/perl/OpenSSL/config.pm
@@ -130,6 +130,7 @@ my $guess_patterns = [
       sub {
           my $hw = `/usr/sbin/sysctl -n hw.model || /sbin/sysctl -n hw.model`;
           $hw =~  s@.*(.)86-class.*@i${1}86@;
+          chomp $hw;
           return "${hw}-whatever-netbsd";
       }
     ],
@@ -579,29 +580,7 @@ EOF
                      %config };
         }
       ],
-      [ 'ppc64-.*-linux2',
-        sub {
-            my $KERNEL_BITS = $ENV{KERNEL_BITS} // '';
-            if ( $KERNEL_BITS eq '' ) {
-                print <<EOF;
-WARNING! To build 64-bit package, do this:
-         $WHERE/Configure linux-ppc64
-EOF
-                maybe_abort();
-            }
-            return { target => "linux-ppc64" } if $KERNEL_BITS eq '64';
-
-            my %config = ();
-            if (!okrun('echo __LP64__',
-                       'gcc -E -x c - 2>/dev/null',
-                       'grep "^__LP64__" 2>&1 >/dev/null') ) {
-                %config = ( cflags => [ '-m32' ],
-                            cxxflags =>  [ '-m32' ] );
-            }
-            return { target => "linux-ppc",
-                     %config };
-        }
-      ],
+      [ 'ppc64-.*-linux2',        { target => "linux-ppc64" } ],
       [ 'ppc64le-.*-linux2',      { target => "linux-ppc64le" } ],
       [ 'ppc-.*-linux2',          { target => "linux-ppc" } ],
       [ 'mips64.*-*-linux2',
