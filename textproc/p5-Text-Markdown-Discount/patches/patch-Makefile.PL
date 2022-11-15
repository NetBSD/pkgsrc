$NetBSD: patch-Makefile.PL,v 1.6 2022/11/15 11:47:57 schmonz Exp $

Remove build instructions for the local copy of libdiscount.

--- Makefile.PL.orig	2022-07-16 22:50:16.000000000 +0000
+++ Makefile.PL
@@ -4,65 +4,6 @@ use warnings;
 use ExtUtils::MakeMaker;
 use File::Spec;
 
-my $extdir = 'discount-2.2.7';
-my $myextlib = File::Spec->catfile($extdir, 'libmarkdown.a');
-my $clean_files = join (" ",
-                  map{ File::Spec->catfile($extdir, $_) }
-                  qw ( 
-main.o
-mkd2html.o
-config.cmd
-cols
-theme.o
-html5.o
-setup.o
-version.o
-mkd2html
-echo
-Csio.o
-msvc
-mktags
-config.h
-pgm_options.o
-libmarkdown
-dumptree.o
-Makefile
-libmarkdown.a
-markdown
-flags.o
-blocktags
-toc.o
-makepage
-emmatch.o
-generate.o
-config.md
-config.sub
-config.mak
-xml.o
-theme
-resource.o
-version.c
-tags.o
-config.log
-xmlpage.o
-css.o
-basename.o
-mkdio.o
-mkdio.h
-markdown.o
-librarian.sh
-docheader.o
-                  ));
-
-
-
-sub MY::postamble {
-    return sprintf('
-$(MYEXTLIB):
-	%s
-', qq{( cd $extdir; CC='cc -fPIC' sh configure.sh --with-fenced-code --with-dl=both; make )\n});
-}
-
 WriteMakefile(
     NAME              => 'Text::Markdown::Discount',
     VERSION_FROM      => 'lib/Text/Markdown/Discount.pm',
@@ -70,10 +11,7 @@ WriteMakefile(
     ($] >= 5.005 ?
       (ABSTRACT_FROM  => 'lib/Text/Markdown/Discount.pm',
        AUTHOR         => 'Masayoshi Sekimura <sekimura@cpan.org>') : ()),
-    LIBS               => '-L' . $extdir,
-    INC               => '-I. -I' . $extdir,
-    MYEXTLIB          => $myextlib,
-    clean             => { FILES => $clean_files },
+    LIBS               => '-L@PREFIX@/lib -lmarkdown',
     META_MERGE => {
         'meta-spec' => { version => 2 },
         resources => {
