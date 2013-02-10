# $NetBSD: tools.Cygwin.mk,v 1.1 2013/02/10 12:25:18 obache Exp $
#
# System-supplied tools for the Cygwin operating system.

TOOLS_PLATFORM.[?=		/bin/[
TOOLS_PLATFORM.awk?=		/bin/awk
TOOLS_PLATFORM.basename?=	/bin/basename
TOOLS_PLATFORM.bash?=		/bin/bash
.if exists(/bin/bison)
TOOLS_PLATFORM.bison?=		/bin/bison
TOOLS_PLATFORM.bison-yacc?=	/bin/bison -y
.endif
.if exists(/bin/bzcat)
TOOLS_PLATFORM.bzcat?=		/bin/bzcat
.elif exists(/bin/bzip2)
TOOLS_PLATFORM.bzcat?=		/bin/bzip2 -cd
.endif
.if exists(/bin/bzip2)
TOOLS_PLATFORM.bzip2?=		/bin/bzip2
.endif

TOOLS_PLATFORM.cat?=		/bin/cat
TOOLS_PLATFORM.chgrp?=		/bin/chgrp
TOOLS_PLATFORM.chmod?=		/bin/chmod
TOOLS_PLATFORM.chown?=		/bin/chown
TOOLS_PLATFORM.cmp?=		/bin/cmp
TOOLS_PLATFORM.cp?=		/bin/cp
TOOLS_PLATFORM.csh?=		/bin/csh
TOOLS_PLATFORM.cut?=		/bin/cut
TOOLS_PLATFORM.date?=		/bin/date
TOOLS_PLATFORM.diff?=		/bin/diff
TOOLS_PLATFORM.dirname?=	/bin/dirname
TOOLS_PLATFORM.echo?=		echo			# shell builtin
TOOLS_PLATFORM.egrep?=		/bin/egrep
TOOLS_PLATFORM.env?=		/bin/env
TOOLS_PLATFORM.expr?=		/bin/expr
TOOLS_PLATFORM.false?=		false			# shell builtin
TOOLS_PLATFORM.fgrep?=		/bin/fgrep
TOOLS_PLATFORM.file?=		/bin/file
TOOLS_PLATFORM.find?=		/bin/find
.if exists(/bin/flex)
TOOLS_PLATFORM.flex?=		/bin/flex
TOOLS_PLATFORM.lex?=		/bin/flex
.endif
TOOLS_PLATFORM.grep?=		/bin/grep
TOOLS_PLATFORM.gunzip?=		/bin/gunzip -f
TOOLS_PLATFORM.gzcat?=		/bin/zcat
TOOLS_PLATFORM.gzip?=		/bin/gzip -nf ${GZIP}
TOOLS_PLATFORM.head?=		/bin/head
TOOLS_PLATFORM.hostname?=	/bin/hostname
TOOLS_PLATFORM.id?=		/bin/id
TOOLS_PLATFORM.install?=	/bin/install
.if exists(/bin/install-info)
TOOLS_PLATFORM.install-info?=	/bin/install-info
.endif
TOOLS_PLATFORM.ln?=		/bin/ln
TOOLS_PLATFORM.ls?=		/bin/ls
TOOLS_PLATFORM.m4?=		/bin/m4
TOOLS_PLATFORM.mail?=		/bin/mail
.if exists(/bin/make)
TOOLS_PLATFORM.gmake?=		/bin/make
.endif
.if exists(/bin/makeinfo)
TOOLS_PLATFORM.makeinfo?=	/bin/makeinfo
.endif
TOOLS_PLATFORM.mkdir?=		/bin/mkdir -p
TOOLS_PLATFORM.mktemp?=		/bin/mktemp
TOOLS_PLATFORM.mv?=		/bin/mv
TOOLS_PLATFORM.nice?=		/bin/nice
.if exists(/bin/perl)
TOOLS_PLATFORM.perl?=		/bin/perl
.endif
# Don't use GNU patch
#.if exists(/bin/patch)
#TOOLS_PLATFORM.patch?=		/bin/patch
#.endif
.if exists(/bin/pkg-config)
TOOLS_PLATFORM.pkg-config?=	/bin/pkg-config
.endif
TOOLS_PLATFORM.printf?=		/bin/printf
TOOLS_PLATFORM.pwd?=		/bin/pwd
TOOLS_PLATFORM.rm?=		/bin/rm
TOOLS_PLATFORM.rmdir?=		/bin/rmdir
TOOLS_PLATFORM.sh?=		/bin/sh
TOOLS_PLATFORM.sleep?=		/bin/sleep
TOOLS_PLATFORM.sort?=		/bin/sort
TOOLS_PLATFORM.strip?=		/bin/strip
TOOLS_PLATFORM.tail?=		/bin/tail
TOOLS_PLATFORM.tee?=		/bin/tee
TOOLS_PLATFORM.test?=		test			# shell builtin
TOOLS_PLATFORM.touch?=		/bin/touch
TOOLS_PLATFORM.tr?=		/bin/tr
TOOLS_PLATFORM.true?=		true			# shell builtin
TOOLS_PLATFORM.tsort?=		/bin/tsort
TOOLS_PLATFORM.wc?=		/bin/wc
TOOLS_PLATFORM.xargs?=		/bin/xargs -r
TOOLS_PLATFORM.sed?=		/bin/sed
