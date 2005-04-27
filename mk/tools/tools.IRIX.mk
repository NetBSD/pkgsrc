# $NetBSD: tools.IRIX.mk,v 1.1 2005/04/27 15:28:16 jlam Exp $
#
# System-supplied tools for the IRIX operating system.

PLATFORM_TOOL.awk?=		/usr/bin/nawk
PLATFORM_TOOL.basename?=	/sbin/basename
PLATFORM_TOOL.cat?=		/sbin/cat
PLATFORM_TOOL.chgrp?=		/sbin/chgrp
PLATFORM_TOOL.chmod?=		/sbin/chmod
PLATFORM_TOOL.chown?=		/sbin/chown
PLATFORM_TOOL.cmp?=		/usr/bin/cmp
PLATFORM_TOOL.cp?=		/sbin/cp
PLATFORM_TOOL.cut?=		/usr/bin/cut
PLATFORM_TOOL.date?=		/sbin/date
PLATFORM_TOOL.dirname?=		/usr/bin/dirname
PLATFORM_TOOL.echo?=		echo			# shell builtin
PLATFORM_TOOL.egrep?=		/usr/bin/egrep
PLATFORM_TOOL.env?=		/sbin/env
PLATFORM_TOOL.expr?=		/bin/expr
PLATFORM_TOOL.false?=		false			# shell builtin
PLATFORM_TOOL.fgrep?=		/usr/bin/fgrep
PLATFORM_TOOL.file?=		/usr/bin/file
PLATFORM_TOOL.find?=		/sbin/find
PLATFORM_TOOL.grep?=		/sbin/grep
PLATFORM_TOOL.gunzip?=		/usr/sbin/gunzip -f
.if exists(/usr/sbin/gzcat)
PLATFORM_TOOL.gzcat?=		/usr/bin/gzcat
.elif exists(/usr/bsd/zcat)
PLATFORM_TOOL.gzcat?=		/usr/bsd/zcat
.endif
PLATFORM_TOOL.gzip?=		/usr/sbin/gzip -nf ${GZIP}
PLATFORM_TOOL.head?=		/usr/bsd/head
PLATFORM_TOOL.hostname?=	/usr/bsd/hostname
PLATFORM_TOOL.id?=		/usr/bin/id
PLATFORM_TOOL.ln?=		/sbin/ln
PLATFORM_TOOL.ls?=		/sbin/ls
PLATFORM_TOOL.m4?=		/sbin/m4
PLATFORM_TOOL.mkdir?=		/sbin/mkdir -p
PLATFORM_TOOL.mv?=		/sbin/mv
PLATFORM_TOOL.nice?=		/sbin/nice
PLATFORM_TOOL.pwd?=		/sbin/pwd
PLATFORM_TOOL.rm?=		/sbin/rm
PLATFORM_TOOL.rmdir?=		/usr/bin/rmdir
PLATFORM_TOOL.sed?=		/sbin/sed
PLATFORM_TOOL.sh?=		/bin/ksh
PLATFORM_TOOL.sort?=		/usr/bin/sort
PLATFORM_TOOL.tail?=		/usr/bin/tail
PLATFORM_TOOL.tee?=		/usr/bin/tee
PLATFORM_TOOL.test?=		test			# shell builtin
PLATFORM_TOOL.touch?=		/usr/bin/touch
PLATFORM_TOOL.tr?=		/usr/bin/tr
PLATFORM_TOOL.true?=		true			# shell builtin
PLATFORM_TOOL.tsort?=		/usr/bin/tsort
PLATFORM_TOOL.wc?=		/sbin/wc
PLATFORM_TOOL.xargs?=		/sbin/xargs
