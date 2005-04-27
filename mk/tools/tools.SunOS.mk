# $NetBSD: tools.SunOS.mk,v 1.2 2005/04/27 15:58:18 jlam Exp $
#
# System-supplied tools for the Solaris operating system.

PLATFORM_TOOL.awk?=		/usr/bin/nawk
PLATFORM_TOOL.basename?=	/usr/bin/basename
PLATFORM_TOOL.cat?=		/usr/bin/cat
PLATFORM_TOOL.chgrp?=		/usr/bin/chgrp
PLATFORM_TOOL.chmod?=		/usr/bin/chmod
PLATFORM_TOOL.chown?=		/usr/bin/chown
.if exists(/bin/cmp).
PLATFORM_TOOL.cmp?=		/bin/cmp
.elif exists(/bin/cmp)
PLATFORM_TOOL.cmp?=		/usr/bin/cmp
.endif
PLATFORM_TOOL.cp?=		/bin/cp
PLATFORM_TOOL.cut?=		/usr/bin/cut
PLATFORM_TOOL.date?=		/usr/xpg4/bin/date
PLATFORM_TOOL.dirname?=		/usr/bin/dirname
PLATFORM_TOOL.echo?=		/usr/ucb/echo
PLATFORM_TOOL.egrep?=		/usr/xpg4/bin/grep -E
PLATFORM_TOOL.env?=		/usr/bin/env
PLATFORM_TOOL.expr?=		/usr/xpg4/bin/expr
PLATFORM_TOOL.false?=		/usr/bin/false
PLATFORM_TOOL.fgrep?=		/usr/xpg4/bin/fgrep
PLATFORM_TOOL.file?=		/usr/bin/file
PLATFORM_TOOL.find?=		/usr/bin/find
PLATFORM_TOOL.grep?=		/usr/xpg4/bin/grep
.if exists(/usr/bin/gzip)
PLATFORM_TOOL.gunzip?=		/usr/bin/gzip -df
PLATFORM_TOOL.gzcat?=		/usr/bin/gzip -cd
PLATFORM_TOOL.gzip?=		/usr/bin/gzip -nf ${GZIP}
.endif
PLATFORM_TOOL.head?=		/usr/bin/head
PLATFORM_TOOL.hostname?=	/bin/hostname
PLATFORM_TOOL.id?=		/usr/xpg4/bin/id
PLATFORM_TOOL.ln?=		/usr/bin/ln
PLATFORM_TOOL.ls?=		/usr/bin/ls
PLATFORM_TOOL.m4?=		/usr/ccs/bin/m4
PLATFORM_TOOL.mkdir?=		/usr/bin/mkdir -p
PLATFORM_TOOL.mv?=		/usr/bin/mv
PLATFORM_TOOL.nice?=		/usr/xpg4/bin/nice
.if exists(/usr/bin/gpatch)
PLATFORM_TOOL.patch?=		/usr/bin/gpatch
.endif
PLATFORM_TOOL.pwd?=		/bin/pwd
PLATFORM_TOOL.rm?=		/usr/bin/rm
PLATFORM_TOOL.rmdir?=		/usr/bin/rmdir
PLATFORM_TOOL.sh?=		/bin/ksh
PLATFORM_TOOL.sort?=		/usr/bin/sort
PLATFORM_TOOL.tail?=		/usr/xpg4/bin/tail
PLATFORM_TOOL.tee?=		/usr/bin/tee
PLATFORM_TOOL.test?=		test			# shell builtin
PLATFORM_TOOL.touch?=		/usr/bin/touch
PLATFORM_TOOL.tr?=		/usr/bin/tr
PLATFORM_TOOL.true?=		/usr/bin/true
PLATFORM_TOOL.tsort?=		/usr/ccs/bin/tsort
PLATFORM_TOOL.wc?=		/usr/bin/wc
PLATFORM_TOOL.xargs?=		/usr/bin/xargs
