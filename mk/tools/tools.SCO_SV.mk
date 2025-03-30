# $NetBSD: tools.SCO_SV.mk,v 1.2 2025/03/30 09:50:23 nia Exp $
#
# System-supplied tools for the OpenServer 5.0.7/3.2 and 6.0.0/5.

TOOLS_PLATFORM.[?=		[			# shell builtin
.if exists(/usr/xdev/bin/autopoint)
TOOLS_PLATFORM.autopoint?=	/usr/xdev/bin/autopoint
.elif exists(/usr/gnu/bin/autopoint)
TOOLS_PLATFORM.autopoint?=	/usr/gnu/bin/autopoint
.endif
TOOLS_PLATFORM.awk?=		/usr/bin/nawk
TOOLS_PLATFORM.basename?=	/bin/basename
TOOLS_PLATFORM.bash?=		/usr/bin/bash
.if exists(/usr/gnu/bin/bison)
TOOLS_PLATFORM.bison?=		/usr/gnu/bin/bison
TOOLS_PLATFORM.bison-yacc?=	/usr/gnu/bin/bison -y
.endif
TOOLS_PLATFORM.bzcat?=		/bin/bzcat
TOOLS_PLATFORM.bzip2?=		/bin/bzip2
TOOLS_PLATFORM.cat?=		/bin/cat
TOOLS_PLATFORM.chgrp?=		/bin/chgrp
TOOLS_PLATFORM.chmod?=		/bin/chmod
TOOLS_PLATFORM.chown?=		/bin/chown
TOOLS_PLATFORM.cmp?=		/bin/cmp
TOOLS_PLATFORM.cp?=		/bin/cp
TOOLS_PLATFORM.csh?=		/bin/csh
.if exists(/usr/bin/curl)
TOOLS_PLATFORM.curl?=		/usr/bin/curl
.endif
TOOLS_PLATFORM.cut?=		/usr/bin/cut
TOOLS_PLATFORM.date?=		/bin/date
# /bin/diff under OpenServer 5.0.7/3.2 does not support -u option.
.if exists(/usr/gnu/bin/diff)
TOOLS_PLATFORM.diff?=		/usr/gnu/bin/diff
.endif
.if exists(/usr/gnu/bin/diff3)
TOOLS_PLATFORM.diff3?=		/usr/gnu/bin/diff3
.endif
TOOLS_PLATFORM.dirname?=	/bin/dirname
TOOLS_PLATFORM.echo?=		echo			# shell builtin
TOOLS_PLATFORM.egrep?=		/usr/bin/egrep
TOOLS_PLATFORM.env?=		/bin/env
TOOLS_PLATFORM.expr?=		/bin/expr
TOOLS_PLATFORM.false?=		/bin/false
TOOLS_PLATFORM.fgrep?=		/bin/fgrep
TOOLS_PLATFORM.file?=		/bin/file
TOOLS_PLATFORM.find?=		/bin/find
.if exists(/usr/gnu/bin/flex)
TOOLS_PLATFORM.flex?=		/usr/gnu/bin/flex
.endif
.if exists(/usr/gnu/bin/awk)
TOOLS_PLATFORM.gawk?=		/usr/gnu/bin/gawk
.endif
.if exists(/usr/gnu/bin/grep)
TOOLS_PLATFORM.ggrep?=		/usr/gnu/bin/grep
.endif
TOOLS_PLATFORM.grep?=		/bin/grep
.if exists(/usr/gnu/bin/groff)
TOOLS_PLATFORM.groff?=		/usr/gnu/bin/groff
.endif
.if exists(/usr/xdev/bin/m4)
TOOLS_PLATFORM.gm4?=		/usr/xdev/bin/m4
.elif exists(/usr/gnu/bin/m4)
TOOLS_PLATFORM.gm4?=		/usr/gnu/bin/m4
.endif
.if exists(/usr/xdev/bin/make)
TOOLS_PLATFORM.gmake?=		/usr/xdev/bin/make
.elif exists(/usr/gnu/bin/make)
TOOLS_PLATFORM.gmake?=		/usr/gnu/bin/make
.endif
TOOLS_PLATFORM.gunzip?=		/bin/gunzip -f
TOOLS_PLATFORM.gzcat?=		/bin/gzcat
TOOLS_PLATFORM.gzip?=		/bin/gzip -nf ${GZIP}
TOOLS_PLATFORM.head?=		/bin/head
TOOLS_PLATFORM.hostname?=	/usr/bin/hostname
TOOLS_PLATFORM.id?=		/usr/bin/id
.if exists(/usr/gnu/bin/install-info)
TOOLS_PLATFORM.install-info?=	/usr/gnu/bin/install-info
.endif
TOOLS_PLATFORM.install?=	/etc/install
TOOLS_PLATFORM.ksh?=		/bin/ksh93
TOOLS_PLATFORM.lex?=		/bin/lex
TOOLS_PLATFORM.ln?=		/bin/ln
TOOLS_PLATFORM.ls?=		/bin/ls
TOOLS_PLATFORM.m4?=		/bin/m4
TOOLS_PLATFORM.mail?=		/bin/mail
.if exists(/usr/gnu/bin/makeinfo)
TOOLS_PLATFORM.makeinfo?=	/usr/gnu/bin/makeinfo
.endif
TOOLS_PLATFORM.mkdir?=		/bin/mkdir -p
.if exists(/usr/xdev/bin/msgconv)
TOOLS_PLATFORM.msgconv?=	/usr/xdev/bin/msgconv
.elif exists(/usr/gnu/bin/msgfmt)
TOOLS_PLATFORM.msgconv?=	/usr/gnu/bin/msgconv
.endif
.if exists(/usr/xdev/bin/msgfmt)
TOOLS_PLATFORM.msgfmt?=		/usr/xdev/bin/msgfmt
.elif exists(/usr/gnu/bin/msgfmt)
TOOLS_PLATFORM.msgfmt?=		/usr/gnu/bin/msgfmt
.endif
.if exists(/usr/xdev/bin/msgmerge)
TOOLS_PLATFORM.msgmerge?=	/usr/xdev/bin/msgmerge
.elif exists(/usr/gnu/bin/msgmerge)
TOOLS_PLATFORM.msgmerge?=	/usr/gnu/bin/msgmerge
.endif
TOOLS_PLATFORM.mv?=		/bin/mv
TOOLS_PLATFORM.nice?=		/bin/nice
.if exists(/usr/gnu/bin/nroff)
TOOLS_PLATFORM.nroff?=		/usr/gnu/bin/nroff
.endif
TOOLS_PLATFORM.openssl?=	/usr/bin/openssl
TOOLS_PLATFORM.printf?=		/usr/bin/printf
TOOLS_PLATFORM.pwd?=		/bin/pwd
.if exists(/usr/xdev/bin/readelf)
TOOLS_PLATFORM.readelf?=	/usr/xdev/bin/readelf
.endif
TOOLS_PLATFORM.rm?=		/bin/rm
TOOLS_PLATFORM.rmdir?=		/bin/rmdir
TOOLS_PLATFORM.sdiff?=		/usr/bin/sdiff
.if exists(/usr/gnu/bin/sed)
TOOLS_PLATFORM.sed?=		/usr/gnu/bin/sed
TOOLS_PLATFORM.gsed?=		/usr/gnu/bin/sed
.else
TOOLS_PLATFORM.sed?=		/bin/sed
.endif
TOOLS_PLATFORM.sleep?=		/bin/sleep
TOOLS_PLATFORM.sh?=		/bin/sh
.if exists(/usr/gnu/bin/soelim)
TOOLS_PLATFORM.soelim?=		/usr/gnu/bin/soelim
TOOLS_PLATFORM.gsoelim?=	/usr/gnu/bin/soelim
.endif
TOOLS_PLATFORM.sort?=		/bin/sort
.if exists(/usr/xdev/bin/strip)
TOOLS_PLATFORM.strip?=		/bin/strip
.endif
TOOLS_PLATFORM.tail?=		/bin/tail
.if exists(/usr/gnu/bin/tbl)
TOOLS_PLATFORM.tbl?=		/usr/gnu/bin/tbl
.endif
TOOLS_PLATFORM.tee?=		/bin/tee
.if exists(/usr/xdev/bin/tar)
TOOLS_PLATFORM.tar?=		/usr/xdev/bin/tar
TOOLS_PLATFORM.gtar?=		/usr/xdev/bin/tar
.elif exists(/usr/gnu/bin/tar)
TOOLS_PLATFORM.tar?=		/usr/gnu/bin/tar
TOOLS_PLATFORM.gtar?=		/usr/gnu/bin/tar
.endif
TOOLS_PLATFORM.test?=		test			# shell builtin
TOOLS_PLATFORM.touch?=		/bin/touch
TOOLS_PLATFORM.tr?=		/usr/bin/tr
TOOLS_PLATFORM.true?=		/bin/true
TOOLS_PLATFORM.tsort?=		/bin/tsort
TOOLS_PLATFORM.uniq?=		/usr/bin/uniq
TOOLS_PLATFORM.unzip?=		/bin/unzip
.if exists(/opt/xinuos/bin/wget)
TOOLS_PLATFORM.wget?=		/opt/xinuos/bin/wget
.endif
TOOLS_PLATFORM.wc?=		/bin/wc
TOOLS_PLATFORM.xargs?=		/usr/bin/xargs
.if exists(/usr/xdev/bin/xgettext)
TOOLS_PLATFORM.xgettext?=	/usr/xdev/bin/xgettext
.elif exists(/usr/gnu/bin/xgettext)
TOOLS_PLATFORM.xgettext?=	/usr/gnu/bin/xgettext
.endif
.if exists(/usr/xdev/bin/xz)
TOOLS_PLATFORM.xz?=		/usr/xdev/bin/xz
.endif
.if exists(/usr/xdev/bin/xzcat)
TOOLS_PLATFORM.xzcat?=		/usr/xdev/bin/xzcat
.endif
TOOLS_PLATFORM.yacc?=		/bin/yacc
TOOLS_PLATFORM.zip?=		/bin/zip
TOOLS_PLATFORM.zipcloak?=	/bin/zipcloak
TOOLS_PLATFORM.zipnote?=	/bin/zipnote
TOOLS_PLATFORM.zipsplit?=	/bin/zipsplit
