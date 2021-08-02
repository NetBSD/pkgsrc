$NetBSD: patch-Makefile.PL,v 1.5 2021/08/02 12:24:08 schmonz Exp $

Remove build instructions for the local copy of libdiscount.

--- Makefile.PL.orig	2021-08-02 00:38:11.000000000 +0000
+++ Makefile.PL
@@ -4,66 +4,6 @@ use warnings;
 use ExtUtils::MakeMaker;
 use File::Spec;
 
-my $extdir = 'discount';
-my $myextlib = File::Spec->catfile($extdir, 'libmarkdown.a');
-my $clean_files = join (" ",
-                  map{ File::Spec->catfile($extdir, $_) }
-                  qw ( 
-Csio.o
-basename.o
-blocktags
-cols
-config.cmd
-config.h
-config.log
-config.mak
-config.md
-config.sub
-css.o
-docheader.o
-dumptree.o
-echo
-emmatch.o
-flags.o
-generate.o
-html5.o
-libmarkdown
-libmarkdown.a
-librarian.sh
-main.o
-makepage
-markdown
-markdown.o
-mkd2html
-mkd2html.o
-mkdio.h
-mkdio.o
-mktags
-pgm_options.o
-resource.o
-setup.o
-tags.o
-theme
-theme.o
-toc.o
-theme
-theme.o
-toc.o
-version.c
-version.o
-xml.o
-xmlpage.o
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
@@ -71,10 +11,7 @@ WriteMakefile(
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
