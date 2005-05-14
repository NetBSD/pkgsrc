# $NetBSD: tools.IRIX.mk,v 1.11 2005/05/14 10:17:10 rillig Exp $
#
# System-supplied tools for the IRIX operating system.

TOOLS_PLATFORM.[?=		[			# shell builtin
TOOLS_PLATFORM.awk?=		/usr/bin/nawk
TOOLS_PLATFORM.basename?=	/sbin/basename
TOOLS_PLATFORM.cat?=		/sbin/cat
TOOLS_PLATFORM.chgrp?=		/sbin/chgrp
TOOLS_PLATFORM.chmod?=		/sbin/chmod
TOOLS_PLATFORM.chown?=		/sbin/chown
TOOLS_PLATFORM.cmp?=		/usr/bin/cmp
TOOLS_PLATFORM.cp?=		/sbin/cp
TOOLS_PLATFORM.cut?=		/usr/bin/cut
TOOLS_PLATFORM.date?=		/sbin/date
TOOLS_PLATFORM.dirname?=	/usr/bin/dirname
TOOLS_PLATFORM.echo?=		echo			# shell builtin
TOOLS_PLATFORM.egrep?=		/usr/bin/egrep
TOOLS_PLATFORM.env?=		/sbin/env
TOOLS_PLATFORM.expr?=		/bin/expr
TOOLS_PLATFORM.false?=		false			# shell builtin
TOOLS_PLATFORM.fgrep?=		/usr/bin/fgrep
TOOLS_PLATFORM.file?=		/usr/bin/file
TOOLS_PLATFORM.find?=		/sbin/find
TOOLS_PLATFORM.grep?=		/sbin/grep
TOOLS_PLATFORM.gunzip?=		/usr/sbin/gunzip -f
.if exists(/usr/sbin/gzcat)
TOOLS_PLATFORM.gzcat?=		/usr/sbin/gzcat
.elif exists(/usr/bsd/zcat)
TOOLS_PLATFORM.gzcat?=		/usr/bsd/zcat
.endif
TOOLS_PLATFORM.gzip?=		/usr/sbin/gzip -nf ${GZIP}
TOOLS_PLATFORM.head?=		/usr/bsd/head
TOOLS_PLATFORM.hostname?=	/usr/bsd/hostname
TOOLS_PLATFORM.id?=		/usr/bin/id
TOOLS_PLATFORM.ln?=		/sbin/ln
TOOLS_PLATFORM.ls?=		/sbin/ls
TOOLS_PLATFORM.m4?=		/sbin/m4
TOOLS_PLATFORM.mail?=		/usr/sbin/mailx
TOOLS_PLATFORM.mkdir?=		/sbin/mkdir -p
TOOLS_PLATFORM.mv?=		/sbin/mv
TOOLS_PLATFORM.nice?=		/sbin/nice
TOOLS_PLATFORM.pwd?=		/sbin/pwd
TOOLS_PLATFORM.rm?=		/sbin/rm
TOOLS_PLATFORM.rmdir?=		/usr/bin/rmdir
TOOLS_PLATFORM.sed?=		/sbin/sed
TOOLS_PLATFORM.sh?=		/bin/ksh
TOOLS_PLATFORM.sort?=		/usr/bin/sort
TOOLS_PLATFORM.tail?=		/usr/bin/tail
TOOLS_PLATFORM.tee?=		/usr/bin/tee
TOOLS_PLATFORM.test?=		test			# shell builtin
TOOLS_PLATFORM.touch?=		/usr/bin/touch
TOOLS_PLATFORM.tr?=		/usr/bin/tr
TOOLS_PLATFORM.true?=		true			# shell builtin
TOOLS_PLATFORM.tsort?=		/usr/bin/tsort
TOOLS_PLATFORM.wc?=		/sbin/wc
TOOLS_PLATFORM.xargs?=		/sbin/xargs
