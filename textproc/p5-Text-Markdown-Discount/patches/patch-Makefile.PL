$NetBSD: patch-Makefile.PL,v 1.3 2018/03/10 05:45:02 schmonz Exp $

Remove build instructions for the local copy of libdiscount.

--- Makefile.PL.orig	2013-08-09 20:06:59.000000000 +0000
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
-', qq{( cd $extdir; CC='cc -fPIC' sh configure.sh; make )\n});
-}
-
 WriteMakefile(
     NAME              => 'Text::Markdown::Discount',
     VERSION_FROM      => 'lib/Text/Markdown/Discount.pm',
@@ -71,8 +11,5 @@ WriteMakefile(
     ($] >= 5.005 ?
       (ABSTRACT_FROM  => 'lib/Text/Markdown/Discount.pm',
        AUTHOR         => 'Masayoshi Sekimura <sekimura@cpan.org>') : ()),
-    LIBS               => '-L' . $extdir,
-    INC               => '-I. -I' . $extdir,
-    MYEXTLIB          => $myextlib,
-    clean             => { FILES => $clean_files },
+    LIBS              => '-L@PREFIX@/lib -lmarkdown',
 );
