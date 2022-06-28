$NetBSD: patch-cpan_ExtUtils-MakeMaker_lib_ExtUtils_MM__Unix.pm,v 1.3 2022/06/28 10:02:51 wiz Exp $

* $Is{NetBSD} and $Is{Interix} are unified into $Is{BSD}.
* Ignore installed packlist when creating new packlist.
* Compare inode numbers as string to fix pkg/55997. Cherry-picked from
  upstream. See https://github.com/Perl/perl5/pull/18788 for more details.

--- cpan/ExtUtils-MakeMaker/lib/ExtUtils/MM_Unix.pm.orig	2021-05-13 17:40:25.661784701 +0900
+++ cpan/ExtUtils-MakeMaker/lib/ExtUtils/MM_Unix.pm	2021-05-13 17:40:29.734082886 +0900
@@ -28,8 +28,6 @@ BEGIN {
     $Is{VMS}     = $^O eq 'VMS';
     $Is{OSF}     = $^O eq 'dec_osf';
     $Is{IRIX}    = $^O eq 'irix';
-    $Is{NetBSD}  = $^O eq 'netbsd';
-    $Is{Interix} = $^O eq 'interix';
     $Is{SunOS4}  = $^O eq 'sunos';
     $Is{Solaris} = $^O eq 'solaris';
     $Is{SunOS}   = $Is{SunOS4} || $Is{Solaris};
@@ -1059,7 +1057,7 @@ sub xs_make_dynamic_lib {
     push(@m,"	\$(RM_F) \$\@\n");
 
     my $libs = '$(LDLOADLIBS)';
-    if (($Is{NetBSD} || $Is{Interix} || $Is{Android}) && $Config{'useshrplib'} eq 'true') {
+    if ($Is{BSD} && $Config{'useshrplib'} eq 'true') {
         # Use nothing on static perl platforms, and to the flags needed
         # to link against the shared libperl library on shared perl
         # platforms.  We peek at lddlflags to see if we need -Wl,-R
@@ -2351,7 +2349,7 @@ pure_vendor_install :: all
 	$(NOECHO) $(MOD_INSTALL) \
 };
     push @m,
-q{		read "}.$self->catfile('$(VENDORARCHEXP)','auto','$(FULLEXT)','.packlist').q{" \
+q{		read "" \
 		write "}.$self->catfile('$(DESTINSTALLVENDORARCH)','auto','$(FULLEXT)','.packlist').q{" \
 } unless $self->{NO_PACKLIST};
 
