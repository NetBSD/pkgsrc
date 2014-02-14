# $NetBSD: tools.Cygwin.mk,v 1.6 2014/02/14 07:43:46 obache Exp $
#
# System-supplied tools for the Cygwin operating system.

TOOLS_PLATFORM.[?=		[			# shell builtin
TOOLS_PLATFORM.awk?=		/bin/awk
TOOLS_PLATFORM.basename?=	/bin/basename
TOOLS_PLATFORM.bash?=		/bin/bash
.if exists(/bin/bison)
TOOLS_PLATFORM.bison?=		/bin/bison
TOOLS_PLATFORM.bison-yacc?=	/bin/bison -y
.endif
.if exists(/bin/bsdtar)
TOOLS_PLATFORM.bsdtar?=		/bin/bsdtar
.endif
.if exists(/bin/byacc)
TOOLS_PLATFORM.byacc?=		/bin/byacc
.endif
TOOLS_PLATFORM.bzcat?=		/bin/bzcat
TOOLS_PLATFORM.bzip2?=		/bin/bzip2
TOOLS_PLATFORM.cat?=		/bin/cat
TOOLS_PLATFORM.chgrp?=		/bin/chgrp
TOOLS_PLATFORM.chmod?=		/bin/chmod
TOOLS_PLATFORM.chown?=		/bin/chown
TOOLS_PLATFORM.cmp?=		/bin/cmp
TOOLS_PLATFORM.cp?=		/bin/cp
.if exists(/bin/tcsh)
TOOLS_PLATFORM.csh?=		/bin/tcsh
.endif
.if exists(/bin/curl)
TOOLS_PLATFORM.curl?=		/bin/curl
.endif
TOOLS_PLATFORM.cut?=		/bin/cut
TOOLS_PLATFORM.date?=		/bin/date
TOOLS_PLATFORM.diff?=		/bin/diff
TOOLS_PLATFORM.diff3?=		/bin/diff3
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
.endif
.if exists(/bin/tnftp)
TOOLS_PLATFORM.ftp?=		/bin/tnftp
.endif
TOOLS_PLATFORM.gawk?=		/bin/gawk
.if exists(/bin/m4)
TOOLS_PLATFORM.gm4?=		/bin/m4
.endif
TOOLS_PLATFORM.grep?=		/bin/grep
TOOLS_PLATFORM.gsed?=		/bin/sed
TOOLS_PLATFORM.gsoelim?=	/bin/soelim
TOOLS_PLATFORM.gtar?=		/bin/tar
TOOLS_PLATFORM.gunzip?=		/bin/gunzip -f
TOOLS_PLATFORM.gzcat?=		/bin/zcat
TOOLS_PLATFORM.gzip?=		/bin/gzip -nf ${GZIP}
TOOLS_PLATFORM.head?=		/bin/head
TOOLS_PLATFORM.hostname?=	/bin/hostname
TOOLS_PLATFORM.id?=		/bin/id
.if exists(/bin/ident)
TOOLS_PLATFORM.ident?=		/bin/ident
.endif
TOOLS_PLATFORM.install?=	/bin/install
TOOLS_PLATFORM.install-info?=	/bin/install-info
.if exists(/bin/flex)
TOOLS_PLATFORM.lex?=		/bin/flex
.endif
TOOLS_PLATFORM.ln?=		/bin/ln
TOOLS_PLATFORM.ls?=		/bin/ls
.if exists(/bin/m4)
TOOLS_PLATFORM.m4?=		/bin/m4
.endif
.if exists(/bin/make)
TOOLS_PLATFORM.gmake?=		/bin/make
.endif
TOOLS_PLATFORM.makeinfo?=	/bin/makeinfo
TOOLS_PLATFORM.mkdir?=		/bin/mkdir -p
TOOLS_PLATFORM.mktemp?=		/bin/mktemp
.if exists(/bin/msgfmt)
TOOLS_PLATFORM.msgfmt?=		/bin/msgfmt
.endif
TOOLS_PLATFORM.mv?=		/bin/mv
TOOLS_PLATFORM.nice?=		/bin/nice
TOOLS_PLATFORM.nroff?=		/bin/nroff
.if exists(/bin/openssl)
TOOLS_PLATFORM.openssl?=	/bin/openssl
.endif
.if exists(/bin/pax)
TOOLS_PLATFORM.pax?=		/bin/pax
.endif
.if exists(/bin/perl)
TOOLS_PLATFORM.perl?=		/bin/perl
TOOLS_PLATFORM.pod2man?=	/bin/pod2man
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
TOOLS_PLATFORM.readlink?=	/bin/readlink
TOOLS_PLATFORM.rm?=		/bin/rm
TOOLS_PLATFORM.rmdir?=		/bin/rmdir
TOOLS_PLATFORM.sdiff?=		/bin/sdiff
TOOLS_PLATFORM.sed?=		/bin/sed -b
TOOLS_PLATFORM.sh?=		/bin/sh
TOOLS_PLATFORM.sleep?=		/bin/sleep
TOOLS_PLATFORM.soelim?=		/bin/soelim
TOOLS_PLATFORM.sort?=		/bin/sort
.if exists(/bin/strip)
TOOLS_PLATFORM.strip?=		/bin/strip
.endif
TOOLS_PLATFORM.tail?=		/bin/tail
TOOLS_PLATFORM.tar?=		/bin/tar
TOOLS_PLATFORM.tbl?=		/bin/tbl
TOOLS_PLATFORM.tee?=		/bin/tee
TOOLS_PLATFORM.test?=		test			# shell builtin
.if exists(/bin/texi2html)
TOOLS_PLATFORM.texi2html?=	/bin/texi2html
.endif
TOOLS_PLATFORM.touch?=		/bin/touch
TOOLS_PLATFORM.tr?=		/bin/tr
TOOLS_PLATFORM.true?=		true			# shell builtin
TOOLS_PLATFORM.tsort?=		/bin/tsort
.if exists(/bin/unzip)
TOOLS_PLATFORM.unzip?=		/bin/unzip
.endif
TOOLS_PLATFORM.wc?=		/bin/wc
.if exists(/bin/wget)
TOOLS_PLATFORM.wget?=		/bin/wget
.endif
TOOLS_PLATFORM.xargs?=		/bin/xargs -r
.if exists(/bin/xgettext)
TOOLS_PLATFORM.xgettext?=	/bin/xgettext
.endif
TOOLS_PLATFORM.xzcat?=		/bin/xz
TOOLS_PLATFORM.xzcat?=		/bin/xzcat
.if exists(/bin/yacc)
TOOLS_PLATFORM.yacc?=		/bin/yacc
.endif
.if exists(/bin/zip)
TOOLS_PLATFORM.zip?=		/bin/zip
.endif
