# $NetBSD: tools.UnixWare.mk,v 1.16 2025/03/05 11:44:42 nia Exp $
#
# System-supplied tools for the UnixWare 7 operating system.

TOOLS_PLATFORM.[?=		[			# shell builtin
TOOLS_PLATFORM.awk?=		/usr/bin/nawk
TOOLS_PLATFORM.basename?=	/usr/bin/basename
.if exists(/usr/bin/bash)
TOOLS_PLATFORM.bash?=		/usr/bin/bash
.endif
TOOLS_PLATFORM.bzcat?=		/usr/bin/bzcat
TOOLS_PLATFORM.bzip2?=		/usr/bin/bzip2
TOOLS_PLATFORM.cat?=		/usr/bin/cat
TOOLS_PLATFORM.chgrp?=		/usr/bin/chgrp
TOOLS_PLATFORM.chmod?=		/usr/bin/chmod
TOOLS_PLATFORM.chown?=		/usr/bin/chown
TOOLS_PLATFORM.cmp?=		/usr/bin/cmp
TOOLS_PLATFORM.cp?=		/usr/bin/cp
TOOLS_PLATFORM.csh?=		/bin/csh
.if exists(/opt/xinuos/bin/curl)
TOOLS_PLATFORM.curl?=		/opt/xinuos/bin/curl
.endif
TOOLS_PLATFORM.cut?=		/usr/bin/cut
TOOLS_PLATFORM.date?=		/usr/bin/date
# stock uw7 diff doesn't support -u
# you need Xinuosdiffutils
.if exists(/opt/xinuos/bin/diff)
TOOLS_PLATFORM.diff?=		/opt/xinuos/bin/diff
.endif
.if exists(/opt/xinuos/bin/diff3)
TOOLS_PLATFORM.diff3?=		/opt/xinuos/bin/diff3
.endif
TOOLS_PLATFORM.dirname?=	/usr/bin/dirname
TOOLS_PLATFORM.echo?=		/usr/ucb/echo
TOOLS_PLATFORM.egrep?=		/usr/bin/grep -E
TOOLS_PLATFORM.env?=		/usr/bin/env
TOOLS_PLATFORM.expr?=		/usr/bin/expr
TOOLS_PLATFORM.false?=		/usr/bin/false
TOOLS_PLATFORM.fgrep?=		/usr/bin/grep -F
TOOLS_PLATFORM.file?=		/usr/bin/file
TOOLS_PLATFORM.find?=		/usr/bin/find
TOOLS_PLATFORM.grep?=		/usr/bin/grep
TOOLS_PLATFORM.gunzip?=		/usr/bin/gunzip
TOOLS_PLATFORM.gzcat?=		/usr/bin/gzcat
TOOLS_PLATFORM.gzip?=		/usr/bin/gzip
TOOLS_PLATFORM.head?=		/usr/bin/head
TOOLS_PLATFORM.hostname?=	/usr/bin/hostname
TOOLS_PLATFORM.id?=		/usr/bin/id
TOOLS_PLATFORM.install?=	/usr/ucb/install
TOOLS_PLATFORM.ksh?=		/usr/bin/ksh
TOOLS_PLATFORM.lex?=		/usr/bin/lex
TOOLS_PLATFORM.ln?=		/usr/bin/ln
TOOLS_PLATFORM.ls?=		/usr/bin/ls
TOOLS_PLATFORM.m4?=		/usr/ccs/bin/m4
TOOLS_PLATFORM.mail?=		/usr/bin/mailx
TOOLS_PLATFORM.mv?=		/usr/bin/mv
TOOLS_PLATFORM.nice?=		/usr/bin/nice
TOOLS_PLATFORM.nroff?=		/usr/bin/nroff
.if exists(/usr/bin/openssl)
TOOLS_PLATFORM.openssl?=	/usr/bin/openssl
.endif
TOOLS_PLATFORM.pax?=		/usr/bin/pax
TOOLS_PLATFORM.printf?=		/usr/bin/printf
TOOLS_PLATFORM.pwd?=		/usr/bin/pwd
TOOLS_PLATFORM.rm?=		/usr/bin/rm
TOOLS_PLATFORM.rmdir?=		/usr/bin/rmdir
TOOLS_PLATFORM.sdiff?=		/usr/bin/sdiff
TOOLS_PLATFORM.sed?=		/usr/bin/sed
TOOLS_PLATFORM.sh?=		/usr/bin/ksh
TOOLS_PLATFORM.sleep?=		/usr/bin/sleep
TOOLS_PLATFORM.sort?=		/usr/bin/sort
TOOLS_PLATFORM.strip?=		/usr/ccs/bin/strip
TOOLS_PLATFORM.tail?=		/usr/bin/tail
TOOLS_PLATFORM.tar?=		/usr/bin/tar
TOOLS_PLATFORM.tbl?=		/usr/ucb/tbl
TOOLS_PLATFORM.tee?=		/usr/bin/tee
TOOLS_PLATFORM.test?=		test			# shell builtin
TOOLS_PLATFORM.touch?=		/usr/bin/touch
TOOLS_PLATFORM.tr?=		/usr/bin/tr
TOOLS_PLATFORM.true?=		/usr/bin/true
TOOLS_PLATFORM.tsort?=		/usr/ccs/bin/tsort
TOOLS_PLATFORM.uniq?=		/usr/bin/uniq
.if exists(/usr/bin/unzip)
TOOLS_PLATFORM.unzip?=		/usr/bin/unzip
.endif
.if exists(/opt/xinuos/bin/wget)
TOOLS_PLATFORM.wget?=		/opt/xinuos/bin/wget
.endif
TOOLS_PLATFORM.wc?=		/usr/bin/wc
TOOLS_PLATFORM.xargs?=		/usr/bin/xargs
.if exists(/usr/bin/xzcat)
TOOLS_PLATFORM.xzcat?=		/usr/bin/xzcat
.endif
.if exists(/usr/bin/xz)
TOOLS_PLATFORM.xz?=		/usr/bin/xz
.endif
TOOLS_PLATFORM.yacc?=		/usr/bin/yacc
.if exists(/usr/bin/zip)
TOOLS_PLATFORM.zip?=		/usr/bin/zip
.endif

# Special bootstrap script
TOOLS_PLATFORM.mkdir?=		${TOOLBASE}/sbin/mkdir-sh -p
