# $NetBSD: tools.Haiku.mk,v 1.16 2015/02/01 08:48:56 obache Exp $
#
# System-supplied tools for the Haiku operating system.

TOOLS_PLATFORM.[?=		[			# shell builtin
TOOLS_PLATFORM.awk?=		/bin/awk
TOOLS_PLATFORM.basename?=	/bin/basename
TOOLS_PLATFORM.bash?=		/bin/bash
.if exists(/bin/bison)
TOOLS_PLATFORM.bison?=		/bin/bison
TOOLS_PLATFORM.bison-yacc?=	/bin/bison -y
.elif exists(/boot/common/bin/bison)
TOOLS_PLATFORM.bison?=		/boot/common/bin/bison
TOOLS_PLATFORM.bison-yacc?=	/boot/common/bin/bison -y
.endif
.if exists(/bin/bzip2)
TOOLS_PLATFORM.bzcat?=		/bin/bzip2 -cd
TOOLS_PLATFORM.bzip2?=		/bin/bzip2
.elif exists(/boot/common/bin/bzip2)
TOOLS_PLATFORM.bzcat?=		/boot/common/bin/bzip2 -cd
TOOLS_PLATFORM.bzip2?=		/boot/common/bin/bzip2
.endif
TOOLS_PLATFORM.cat?=		/bin/cat
TOOLS_PLATFORM.chgrp?=		/bin/chgrp
TOOLS_PLATFORM.chmod?=		/bin/chmod
TOOLS_PLATFORM.chown?=		/bin/chown
TOOLS_PLATFORM.cmp?=		/bin/cmp
TOOLS_PLATFORM.cp?=		/bin/cp
TOOLS_PLATFORM.cut?=		/bin/cut
.if exists(/bin/curl)
TOOLS_PLATFORM.curl?=		/bin/curl
.elif exists(/boot/common/bin/curl)
TOOLS_PLATFORM.curl?=		/boot/common/bin/curl
.endif
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
TOOLS_PLATFORM.find?=		/bin/find
TOOLS_PLATFORM.ftp?=		/bin/ftp
TOOLS_PLATFORM.gawk?=		/bin/gawk
.if exists(/bin/m4)
TOOLS_PLATFORM.gm4?=		/bin/m4
.elif exists(/boot/common/bin/m4)
TOOLS_PLATFORM.gm4?=		/boot/common/bin/m4
.endif
.if exists(/bin/make)
TOOLS_PLATFORM.gmake?=		/bin/make
.elif exists(/boot/common/bin/make)
TOOLS_PLATFORM.gmake?=		/boot/common/bin/make
.endif
TOOLS_PLATFORM.grep?=		/bin/grep
.if exists(/bin/groff)
TOOLS_PLATFORM.groff?=		/bin/groff
.endif
.if exists(/bin/sed)
TOOLS_PLATFORM.gsed?=		/bin/sed
.elif exists(/boot/common/bin/sed)
TOOLS_PLATFORM.gsed?=		/boot/common/bin/sed
.endif
.if exists(/bin/soelim)
TOOLS_PLATFORM.gsoelim?=	/bin/soelim
.endif
.if exists(/bin/tar)
TOOLS_PLATFORM.gtar?=		/bin/tar
.elif exists(/boot/common/bin/tar)
TOOLS_PLATFORM.gtar?=		/boot/common/bin/tar
.endif
TOOLS_PLATFORM.gunzip?=		/bin/gunzip -f
TOOLS_PLATFORM.gzcat?=		/bin/zcat
TOOLS_PLATFORM.gzip?=		/bin/gzip -nf ${GZIP}
TOOLS_PLATFORM.head?=		/bin/head
TOOLS_PLATFORM.hostname?=	/bin/hostname
TOOLS_PLATFORM.id?=		/bin/id
TOOLS_PLATFORM.ident?=		/bin/ident
TOOLS_PLATFORM.install?=	/bin/install
.if exists(/bin/install-info)
TOOLS_PLATFORM.install-info?=	/bin/install-info
.elif exists(/boot/common/bin/install-info)
TOOLS_PLATFORM.install-info?=	/boot/common/bin/install-info
.endif
#TOOLS_PLATFORM.ldconfig?=	/sbin/ldconfig
# XXX: BFS currently no support of hard link.
TOOLS_PLATFORM.ln?=		/bin/ln
TOOLS_PLATFORM.ls?=		/bin/ls
.if exists(/bin/lzcat)
TOOLS_PLATFORM.lzcat?=		/bin/lzcat
.elif exists(/boot/common/bin/lzcat)
TOOLS_PLATFORM.lzcat?=		/boot/common/bin/lzcat
.endif
TOOLS_PLATFORM.m4?=		${TOOLS_PLATFORM.gm4}
#TOOLS_PLATFORM.mail?=		/bin/mail
.if exists(/bin/makeinfo)
TOOLS_PLATFORM.makeinfo?=	/bin/makeinfo
.elif exists(/boot/common/bin/makeinfo)
TOOLS_PLATFORM.makeinfo?=	/boot/common/bin/makeinfo
.endif
TOOLS_PLATFORM.mkdir?=		/bin/mkdir -p
.if exists(/bin/mktemp)
TOOLS_PLATFORM.mktemp?=		/bin/mktemp
.endif
#TOOLS_PLATFORM.msgfmt?=		/usr/bin/msgfmt
TOOLS_PLATFORM.mv?=		/bin/mv
#TOOLS_PLATFORM.nice?=		/bin/nice
.if exists(/bin/nroff)
TOOLS_PLATFORM.nroff?=		/bin/nroff
.endif
.if exists(/bin/openssl)
TOOLS_PLATFORM.openssl?=	/bin/openssl
.elif exists(/boot/common/bin/openssl)
TOOLS_PLATFORM.openssl?=	/boot/common/bin/openssl
.endif
# Don't use GNU patch
#TOOLS_PLATFORM.patch?=		/bin/patch
TOOLS_PLATFORM.printf?=		/bin/printf
TOOLS_PLATFORM.pwd?=		/bin/pwd
TOOLS_PLATFORM.readlink?=	/bin/readlink
TOOLS_PLATFORM.rm?=		/bin/rm
TOOLS_PLATFORM.rmdir?=		/bin/rmdir
.if exists(/bin/sdiff)
TOOLS_PLATFORM.sdiff?=		/bin/sdiff
.endif
TOOLS_PLATFORM.sed?=		${TOOLS_PLATFORM.gsed}
TOOLS_PLATFORM.sh?=		/bin/sh
TOOLS_PLATFORM.sleep?=		/bin/sleep
.if exists(/bin/soelim)
TOOLS_PLATFORM.soelim?=		/bin/soelim
.endif
TOOLS_PLATFORM.sort?=		/bin/sort
.if exists(/bin/strip)
TOOLS_PLATFORM.strip?=		/bin/strip
.else
TOOLS_PLATFORM.strip?=		/boot/develop/tools/gnupro/bin/strip
.endif
TOOLS_PLATFORM.tail?=		/bin/tail
TOOLS_PLATFORM.tar?=		${TOOLS_PLATFORM.gtar}
.if exists(/bin/tbl)
TOOLS_PLATFORM.tbl?=		/bin/tbl
.endif
TOOLS_PLATFORM.tee?=		/bin/tee
TOOLS_PLATFORM.test?=		test			# shell builtin
TOOLS_PLATFORM.touch?=		/bin/touch
TOOLS_PLATFORM.tr?=		/bin/tr
TOOLS_PLATFORM.true?=		true			# shell builtin
TOOLS_PLATFORM.tsort?=		/bin/tsort
TOOLS_PLATFORM.uniq?=		/bin/uniq
TOOLS_PLATFORM.unzip?=		/bin/unzip
TOOLS_PLATFORM.wc?=		/bin/wc
TOOLS_PLATFORM.wget?=		/bin/wget
TOOLS_PLATFORM.xargs?=		/bin/xargs -r
#TOOLS_PLATFORM.xgettext?=	/usr/bin/xgettext
.if exists(/bin/xz)
TOOLS_PLATFORM.xz?=		/bin/xz
.elif exists(/boot/common/bin/xz)
TOOLS_PLATFORM.xz?=		/boot/common/bin/xz
.endif
.if exists(/bin/xzcat)
TOOLS_PLATFORM.xzcat?=		/bin/xzcat
.elif exists(/boot/common/bin/xzcat)
TOOLS_PLATFORM.xzcat?=		/boot/common/bin/xzcat
.endif
TOOLS_PLATFORM.zip?=		/bin/zip
