# $NetBSD: tools.Linux.mk,v 1.2 2005/04/27 15:36:26 jlam Exp $
#
# System-supplied tools for the Linux operating system.

PLATFORM_TOOL.awk?=		${PLATFORM_TOOL.gawk}
.if exists(/bin/basename)
PLATFORM_TOOL.basename?=	/bin/basename
.elif exists(/usr/bin/basename)
PLATFORM_TOOL.basename?=	/usr/bin/basename
.endif
.if exists(/usr/bin/bison)
PLATFORM_TOOL.bison?=		/usr/bin/bison
.endif
PLATFORM_TOOL.cat?=		/bin/cat
PLATFORM_TOOL.chgrp?=		/bin/chgrp
PLATFORM_TOOL.chmod?=		/bin/chmod
PLATFORM_TOOL.chown?=		/bin/chown
.if exists(/bin/cmp)
PLATFORM_TOOL.cmp?=		/bin/cmp
.elif exists(/usr/bin/cmp)
PLATFORM_TOOL.cmp?=		/usr/bin/cmp
.endif
PLATFORM_TOOL.cp?=		/bin/cp
.if exists(/bin/cut)
PLATFORM_TOOL.cut?=		/bin/cut
.elif exists(/usr/bin/cut)
PLATFORM_TOOL.cut?=		/usr/bin/cut
.endif
PLATFORM_TOOL.date?=		/bin/date
PLATFORM_TOOL.dirname?=		/usr/bin/dirname
PLATFORM_TOOL.echo?=		echo			# shell builtin
.if exists(/bin/egrep)
PLATFORM_TOOL.egrep?=		/bin/egrep
.elif exists(/usr/bin/egrep)
PLATFORM_TOOL.egrep?=		/usr/bin/egrep
.endif
PLATFORM_TOOL.env?=		/usr/bin/env
PLATFORM_TOOL.expr?=		/usr/bin/expr
PLATFORM_TOOL.false?=		false			# shell builtin
.if exists(/bin/fgrep)
PLATFORM_TOOL.fgrep?=		/bin/fgrep
.elif exists(/usr/bin/fgrep)
PLATFORM_TOOL.fgrep?=		/usr/bin/fgrep
.endif
PLATFORM_TOOL.file?=		/usr/bin/file
PLATFORM_TOOL.find?=		/usr/bin/find
PLATFORM_TOOL.gawk?=		/usr/bin/awk
PLATFORM_TOOL.gm4?=		/usr/bin/m4
.if exists(/usr/bin/make)
PLATFORM_TOOL.gmake?=		/usr/bin/make
.endif
.if exists(/bin/grep)
PLATFORM_TOOL.grep?=		/bin/grep
.elif exists(/bin/grep)
PLATFORM_TOOL.grep?=		/usr/bin/grep
.endif
.if exists(/bin/sed)
PLATFORM_TOOL.gsed?=		/bin/sed
.elif exists(/usr/bin/sed)
PLATFORM_TOOL.gsed?=		/usr/bin/sed
.endif
PLATFORM_TOOL.gtar?=		/bin/tar
.if exists(/bin/gunzip)
PLATFORM_TOOL.gunzip?=		/bin/gunzip -f
.elif exists(/usr/bin/gunzip)
PLATFORM_TOOL.gunzip?=		/usr/bin/gunzip -f
.endif
PLATFORM_TOOL.gzcat?=		/bin/zcat
.if exists(/bin/gzip)
PLATFORM_TOOL.gzip?=		/usr/bin/gzip -nf ${GZIP}
.elif exists(/usr/bin/gzip)
PLATFORM_TOOL.gzip?=		/usr/bin/gzip -nf ${GZIP}
.endif
.if exists(/bin/head)
PLATFORM_TOOL.head?=		/bin/head
.elif exists(/usr/bin/head)
PLATFORM_TOOL.head?=		/usr/bin/head
.endif
PLATFORM_TOOL.hostname?=	/bin/hostname
.if exists(/bin/id)
PLATFORM_TOOL.id?=		/bin/id
.elif exists(/usr/bin/id)
PLATFORM_TOOL.id?=		/usr/bin/id
.endif
PLATFORM_TOOL.ln?=		/bin/ln
PLATFORM_TOOL.ls?=		/bin/ls
PLATFORM_TOOL.m4?=		${PLATFORM_TOOL.gm4}
PLATFORM_TOOL.mkdir?=		/bin/mkdir -p
PLATFORM_TOOL.mv?=		/bin/mv
.if exists(/bin/nice)
PLATFORM_TOOL.nice?=		/bin/nice
.if exists(/usr/bin/nice)
PLATFORM_TOOL.nice?=		/usr/bin/nice
.endif
PLATFORM_TOOL.patch?=		/usr/bin/patch
PLATFORM_TOOL.pwd?=		/bin/pwd
PLATFORM_TOOL.rm?=		/bin/rm
PLATFORM_TOOL.rmdir?=		/bin/rmdir
PLATFORM_TOOL.sed?=		${PLATFORM_TOOL.gsed}
PLATFORM_TOOL.sh?=		/bin/sh
.if exists(/bin/sort)
PLATFORM_TOOL.sort?=		/bin/sort
.elif exists(/usr/bin/sort)
PLATFORM_TOOL.sort?=		/usr/bin/sort
.endif
PLATFORM_TOOL.tail?=		/usr/bin/tail
PLATFORM_TOOL.tee?=		/usr/bin/tee
PLATFORM_TOOL.test?=		test			# shell builtin
.if exists(/bin/touch)
PLATFORM_TOOL.touch?=		/bin/touch
.elif exists(/usr/bin/touch)
PLATFORM_TOOL.touch?=		/usr/bin/touch
.endif
PLATFORM_TOOL.tr?=		/usr/bin/tr
PLATFORM_TOOL.true?=		true			# shell builtin
PLATFORM_TOOL.tsort?=		/usr/bin/tsort
PLATFORM_TOOL.wc?=		/usr/bin/wc
PLATFORM_TOOL.xargs?=		/usr/bin/xargs
