# $NetBSD: tools.GNUkFreeBSD.mk,v 1.6 2018/11/12 13:34:39 jperkin Exp $
#
# System-supplied tools for the Debian GNU/kFreeBSD operating system.

TOOLS_PLATFORM.[?=		[			# shell builtin
TOOLS_PLATFORM.awk?=		/usr/bin/awk
TOOLS_PLATFORM.basename?=	/usr/bin/basename
TOOLS_PLATFORM.bash?=		/bin/bash
.if exists(/usr/bin/bison)
TOOLS_PLATFORM.bison?=		/usr/bin/bison
TOOLS_PLATFORM.bison-yacc?=	/usr/bin/bison -y
.endif
TOOLS_PLATFORM.bzcat?=		/bin/bzcat
TOOLS_PLATFORM.bzip2?=		/bin/bzip2
TOOLS_PLATFORM.cat?=		/bin/cat
TOOLS_PLATFORM.chgrp?=		/bin/chgrp
TOOLS_PLATFORM.chmod?=		/bin/chmod
TOOLS_PLATFORM.chown?=		/bin/chown
TOOLS_PLATFORM.cmp?=		/usr/bin/cmp
TOOLS_PLATFORM.cp?=		/bin/cp
TOOLS_PLATFORM.cut?=		/usr/bin/cut
TOOLS_PLATFORM.date?=		/bin/date
TOOLS_PLATFORM.diff?=		/usr/bin/diff
TOOLS_PLATFORM.diff3?=		/usr/bin/diff3
TOOLS_PLATFORM.dirname?=	/usr/bin/dirname
TOOLS_PLATFORM.echo?=		echo			# shell builtin
TOOLS_PLATFORM.egrep?=		/bin/egrep
TOOLS_PLATFORM.env?=		/usr/bin/env
TOOLS_PLATFORM.expr?=		/usr/bin/expr
TOOLS_PLATFORM.false?=		false			# shell builtin
TOOLS_PLATFORM.fgrep?=		/bin/fgrep
TOOLS_PLATFORM.file?=		/usr/bin/file
TOOLS_PLATFORM.find?=		/usr/bin/find
TOOLS_PLATFORM.gm4?=		/usr/bin/m4
.if exists(/usr/bin/make)
TOOLS_PLATFORM.gmake?=		/usr/bin/make
.endif
TOOLS_PLATFORM.grep?=		/bin/grep
TOOLS_PLATFORM.gsed?=		/bin/sed
TOOLS_PLATFORM.gsoelim?=	/usr/bin/soelim
TOOLS_PLATFORM.gstrip?=		/usr/bin/strip
TOOLS_PLATFORM.gtar?=		/bin/tar
TOOLS_PLATFORM.gunzip?=		/bin/gunzip -f
TOOLS_PLATFORM.gzcat?=		/bin/zcat
TOOLS_PLATFORM.gzip?=		/bin/gzip -nf ${GZIP}
TOOLS_PLATFORM.head?=		/usr/bin/head
TOOLS_PLATFORM.hostname?=	/bin/hostname
TOOLS_PLATFORM.id?=		/usr/bin/id
TOOLS_PLATFORM.install?=	/usr/bin/install
TOOLS_PLATFORM.install-info?=	/usr/bin/install-info
TOOLS_PLATFORM.ldconfig?=	/sbin/ldconfig
TOOLS_PLATFORM.ln?=		/bin/ln
TOOLS_PLATFORM.ls?=		/bin/ls
TOOLS_PLATFORM.m4?=		${TOOLS_PLATFORM.gm4}
TOOLS_PLATFORM.mail?=		/usr/bin/mail
TOOLS_PLATFORM.makeinfo?=	/usr/bin/makeinfo
TOOLS_PLATFORM.mkdir?=		/bin/mkdir -p
TOOLS_PLATFORM.mktemp?=		/bin/mktemp
TOOLS_PLATFORM.mv?=		/bin/mv
TOOLS_PLATFORM.nice?=		/usr/bin/nice
TOOLS_PLATFORM.nroff?=		/usr/bin/nroff
TOOLS_PLATFORM.openssl?=	/usr/bin/openssl
# Don't use GNU patch
#TOOLS_PLATFORM.patch?=		/usr/bin/patch
TOOLS_PLATFORM.printf?=		/usr/bin/printf
TOOLS_PLATFORM.pwd?=		/bin/pwd
TOOLS_PLATFORM.rm?=		/bin/rm
TOOLS_PLATFORM.rmdir?=		/bin/rmdir
TOOLS_PLATFORM.sdiff?=		/usr/bin/sdiff
TOOLS_PLATFORM.sed?=		${TOOLS_PLATFORM.gsed}
TOOLS_PLATFORM.sh?=		${TOOLS_PLATFORM.bash} # dash is not BSD compatible
TOOLS_PLATFORM.sleep?=		/bin/sleep
TOOLS_PLATFORM.soelim?=		${TOOLS_PLATFORM.gsoelim}
TOOLS_PLATFORM.sort?=		/usr/bin/sort
TOOLS_PLATFORM.strip?=		/usr/bin/strip
TOOLS_PLATFORM.tail?=		/usr/bin/tail
TOOLS_PLATFORM.tar?=		${TOOLS_PLATFORM.gtar}
TOOLS_PLATFORM.tbl?=		/usr/bin/tbl
TOOLS_PLATFORM.tee?=		/usr/bin/tee
TOOLS_PLATFORM.test?=		test			# shell builtin
TOOLS_PLATFORM.touch?=		/usr/bin/touch
TOOLS_PLATFORM.tr?=		/usr/bin/tr
TOOLS_PLATFORM.true?=		true			# shell builtin
TOOLS_PLATFORM.tsort?=		/usr/bin/tsort
TOOLS_PLATFORM.uniq?=		/usr/bin/uniq
TOOLS_PLATFORM.wc?=		/usr/bin/wc
TOOLS_PLATFORM.xargs?=		/usr/bin/xargs -r
TOOLS_PLATFORM.xz?=		/usr/bin/xz
TOOLS_PLATFORM.xzcat?=		/usr/bin/xzcat
