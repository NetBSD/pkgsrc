# $NetBSD: tools.SunOS.mk,v 1.45 2014/05/06 15:42:46 richard Exp $
#
# System-supplied tools for the Solaris operating system.
#
# We bootstrap a pdksh shell on this platform.

TOOLS_PLATFORM.[?=		[			# shell builtin
.if exists(/usr/bin/gawk)
TOOLS_PLATFORM.awk?=		/usr/bin/gawk
.else
TOOLS_PLATFORM.awk?=		/usr/bin/nawk
.endif
TOOLS_PLATFORM.basename?=	/usr/bin/basename
.if exists(/bin/bash)
TOOLS_PLATFORM.bash?=		/bin/bash
.endif
.if exists(/usr/bin/bison)
TOOLS_PLATFORM.bison?=		/usr/bin/bison
TOOLS_PLATFORM.bison-yacc?=	/usr/bin/bison -y
.elif exists(/usr/sfw/bison)
TOOLS_PLATFORM.bison?=		/usr/sfw/bin/bison
TOOLS_PLATFORM.bison-yacc?=	/usr/sfw/bin/bison -y
.endif
.if exists(/usr/bin/bzcat)
TOOLS_PLATFORM.bzcat?=		/usr/bin/bzcat
.endif
.if exists(/usr/bin/bzip2)
TOOLS_PLATFORM.bzip2?=		/usr/bin/bzip2
.endif
TOOLS_PLATFORM.cat?=		/usr/bin/cat
TOOLS_PLATFORM.chgrp?=		/usr/bin/chgrp
TOOLS_PLATFORM.chmod?=		/usr/bin/chmod
TOOLS_PLATFORM.chown?=		/usr/bin/chown
.if exists(/bin/cmp)
TOOLS_PLATFORM.cmp?=		/bin/cmp
.elif exists(/usr/bin/cmp)
TOOLS_PLATFORM.cmp?=		/usr/bin/cmp
.endif
TOOLS_PLATFORM.cp?=		/bin/cp
TOOLS_PLATFORM.csh?=		/bin/csh
.if exists(/usr/bin/curl)
TOOLS_PLATFORM.curl?=		/usr/bin/curl
.endif
TOOLS_PLATFORM.cut?=		/usr/bin/cut
TOOLS_PLATFORM.date?=		/usr/xpg4/bin/date
.if exists(/usr/bin/gdiff)
TOOLS_PLATFORM.diff?=		/usr/bin/gdiff
.else
TOOLS_PLATFORM.diff?=		/usr/bin/diff
.endif
.if exists(/usr/bin/gdiff3)
TOOLS_PLATFORM.diff3?=		/usr/bin/gdiff3
.else
TOOLS_PLATFORM.diff3?=		/usr/bin/diff3
.endif
TOOLS_PLATFORM.dirname?=	/usr/bin/dirname
TOOLS_PLATFORM.echo?=		echo			# shell builtin
.if exists(/usr/gnu/bin/grep)
TOOLS_PLATFORM.grep?=		/usr/gnu/bin/grep
TOOLS_PLATFORM.egrep?=		/usr/gnu/bin/grep -E
TOOLS_PLATFORM.fgrep?=		/usr/gnu/bin/grep -F
.elif exists(/usr/sfw/bin/ggrep)
TOOLS_PLATFORM.grep?=		/usr/sfw/bin/ggrep
TOOLS_PLATFORM.egrep?=		/usr/sfw/bin/ggrep -E
TOOLS_PLATFORM.fgrep?=		/usr/sfw/bin/ggrep -F
.else
TOOLS_PLATFORM.grep?=		/usr/xpg4/bin/grep
TOOLS_PLATFORM.egrep?=		/usr/xpg4/bin/grep -E
TOOLS_PLATFORM.fgrep?=		/usr/xpg4/bin/grep -F
.endif
TOOLS_PLATFORM.env?=		/usr/bin/env
TOOLS_PLATFORM.expr?=		/usr/xpg4/bin/expr
.if exists(/usr/gnu/bin/false)	# if we are using OpenSolaris
TOOLS_PLATFORM.false?=		/usr/gnu/bin/false
.else
TOOLS_PLATFORM.false?=		false			# shell builtin
.endif
TOOLS_PLATFORM.file?=		/usr/bin/file
.if exists(/usr/gnu/bin/find)
TOOLS_PLATFORM.find?=		/usr/gnu/bin/find
.else
TOOLS_PLATFORM.find?=		/usr/bin/find
.endif
.if exists(/usr/bin/flex)
TOOLS_PLATFORM.flex?=		/usr/bin/flex
TOOLS_PLATFORM.lex?=		/usr/bin/flex
.elif exists(/usr/sfw/bin/flex)
TOOLS_PLATFORM.flex?=		/usr/sfw/bin/flex
TOOLS_PLATFORM.lex?=		/usr/sfw/bin/flex
.endif
.if exists(/usr/bin/gawk)
TOOLS_PLATFORM.gawk?=		/usr/bin/gawk
.endif
.if exists(/usr/bin/gm4)
TOOLS_PLATFORM.gm4?=		/usr/bin/gm4
.endif
.if exists(/usr/bin/gmake)
TOOLS_PLATFORM.gmake?=		/usr/bin/gmake
.elif exists(/usr/sfw/bin/gmake)
TOOLS_PLATFORM.gmake?=		/usr/sfw/bin/gmake
.endif
.if exists(/usr/bin/groff)
TOOLS_PLATFORM.groff?=		/usr/bin/groff
.endif
.if exists(/usr/bin/gsed)
TOOLS_PLATFORM.gsed?=		/usr/bin/gsed
.endif
.if exists(/usr/bin/gsoelim)
TOOLS_PLATFORM.gsoelim?=	/usr/bin/gsoelim
.endif
.if exists(/usr/bin/gtar)
TOOLS_PLATFORM.gtar?=		/usr/bin/gtar
TOOLS_PLATFORM.tar?=		/usr/bin/gtar
.elif exists(/usr/sfw/bin/gtar)
TOOLS_PLATFORM.gtar?=		/usr/sfw/bin/gtar
TOOLS_PLATFORM.tar?=		/usr/sfw/bin/gtar
.endif
.if exists(/usr/bin/gzip)
TOOLS_PLATFORM.gunzip?=		/usr/bin/gzip -df
TOOLS_PLATFORM.gzcat?=		/usr/bin/gzip -cd
TOOLS_PLATFORM.gzip?=		/usr/bin/gzip -nf ${GZIP}
.endif
TOOLS_PLATFORM.head?=		/usr/bin/head
TOOLS_PLATFORM.hostname?=	/bin/hostname
TOOLS_PLATFORM.id?=		/usr/xpg4/bin/id
.if exists(/usr/bin/install-info)
TOOLS_PLATFORM.install-info?=	/usr/bin/install-info
.elif exists(/usr/sfw/bin/install-info)
TOOLS_PLATFORM.install-info?=	/usr/sfw/bin/install-info
.endif
.if exists(/usr/bin/ginstall)	# if we are using OpenSolaris
TOOLS_PLATFORM.install?=	/usr/bin/ginstall
.else
TOOLS_PLATFORM.install?=	/usr/ucb/install
.endif
TOOLS_PLATFORM.ksh?=		/bin/ksh
TOOLS_PLATFORM.ln?=		/usr/bin/ln
TOOLS_PLATFORM.ls?=		/usr/bin/ls
TOOLS_PLATFORM.m4?=		/usr/ccs/bin/m4
TOOLS_PLATFORM.mail?=		/usr/bin/mailx
.if exists(/usr/bin/makeinfo)
TOOLS_PLATFORM.makeinfo?=	/usr/bin/makeinfo
.elif exists(/usr/sfw/bin/makeinfo)
TOOLS_PLATFORM.makeinfo?=	/usr/sfw/bin/makeinfo
.endif
TOOLS_PLATFORM.mkdir?=		/usr/bin/mkdir -p
.if exists(/usr/bin/mktemp)
TOOLS_PLATFORM.mktemp?=		/usr/bin/mktemp
.endif
TOOLS_PLATFORM.mv?=		/usr/bin/mv
TOOLS_PLATFORM.nice?=		/usr/xpg4/bin/nice
.if exists(/usr/bin/gnroff)
TOOLS_PLATFORM.nroff?=		/usr/bin/gnroff
.endif
.if exists(/usr/bin/openssl)
TOOLS_PLATFORM.openssl?=	/usr/bin/openssl
.endif
# Don't use GNU patch
#TOOLS_PLATFORM.gpatch?=		/usr/bin/gpatch
#TOOLS_PLATFORM.patch?=		/usr/bin/gpatch
# Native pax doesn't support -O required by mk/extract/extract
#TOOLS_PLATFORM.pax?=		/bin/pax
#.if exists(/usr/bin/perl)
#TOOLS_PLATFORM.perl?=		/usr/bin/perl
#TOOLS_PLATFORM.pod2man?=	/usr/perl5/bin/pod2man
#.endif
.if ${OS_VERSION} == "5.11" && exists(/usr/bin/pkg-config)
TOOLS_PLATFORM.pkg-config?=	/usr/bin/pkg-config
.endif
TOOLS_PLATFORM.printf?=		/bin/printf
TOOLS_PLATFORM.pwd?=		/bin/pwd
.if exists(/usr/gnu/bin/readelf)
TOOLS_PLATFORM.readelf?=	/usr/gnu/bin/readelf
.elif exists(/usr/sfw/bin/greadelf)
TOOLS_PLATFORM.readelf?=	/usr/sfw/bin/greadelf
.endif
TOOLS_PLATFORM.rm?=		/usr/bin/rm
TOOLS_PLATFORM.rmdir?=		/usr/bin/rmdir
.if exists(/usr/bin/gsdiff)
TOOLS_PLATFORM.sdiff?=		/usr/bin/gsdiff
.else
TOOLS_PLATFORM.sdiff?=		/usr/bin/sdiff
.endif
.if exists(/usr/gnu/bin/sed)
TOOLS_PLATFORM.sed?=		/usr/gnu/bin/sed
.endif
TOOLS_PLATFORM.sh?=		/bin/ksh
TOOLS_PLATFORM.sleep?=		/bin/sleep
.if exists(/usr/bin/soelim)
TOOLS_PLATFORM.soelim?=		/usr/bin/soelim
.endif
TOOLS_PLATFORM.sort?=		/usr/bin/sort
.if exists(/usr/ccs/bin/strip)
TOOLS_PLATFORM.strip?=		/usr/ccs/bin/strip
.elif exists(/usr/bin/strip)
TOOLS_PLATFORM.strip?=		/usr/bin/strip
.endif
TOOLS_PLATFORM.tail?=		/usr/xpg4/bin/tail
.if exists(/usr/bin/tbl)
TOOLS_PLATFORM.tbl?=		/usr/bin/tbl
.endif
TOOLS_PLATFORM.tee?=		/usr/bin/tee
TOOLS_PLATFORM.test?=		test			# shell builtin
.if exists(/usr/bin/texi2html)
TOOLS_PLATFORM.texi2html?=	/usr/bin/texi2html
.elif exists(/usr/sfw/bin/texi2html)
TOOLS_PLATFORM.texi2html?=	/usr/sfw/bin/texi2html
.endif
TOOLS_PLATFORM.touch?=		/usr/bin/touch
TOOLS_PLATFORM.tr?=		/usr/xpg4/bin/tr
TOOLS_PLATFORM.true?=		true			# shell builtin
TOOLS_PLATFORM.tsort?=		/usr/ccs/bin/tsort
TOOLS_PLATFORM.uniq?=		/usr/bin/uniq
.if exists(/usr/bin/unzip)
TOOLS_PLATFORM.unzip?=		/usr/bin/unzip
.endif
TOOLS_PLATFORM.wc?=		/usr/bin/wc
TOOLS_PLATFORM.xargs?=		/usr/bin/xargs
.if exists(/usr/bin/yacc)
TOOLS_PLATFORM.yacc?=		/usr/bin/yacc
.endif
.if exists(/usr/bin/zip)
TOOLS_PLATFORM.zip?=		/usr/bin/zip
TOOLS_PLATFORM.zipcloak?=	/usr/bin/zipcloak
TOOLS_PLATFORM.zipnote?=	/usr/bin/zipnote
TOOLS_PLATFORM.zipsplit?=	/usr/bin/zipsplit
.endif
