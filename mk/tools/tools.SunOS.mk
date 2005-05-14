# $NetBSD: tools.SunOS.mk,v 1.13 2005/05/14 10:14:29 rillig Exp $
#
# System-supplied tools for the Solaris operating system.

TOOLS_PLATFORM.[?=		[			# shell builtin
TOOLS_PLATFORM.awk?=		/usr/bin/nawk
TOOLS_PLATFORM.basename?=	/usr/bin/basename
.if exists(/usr/bin/bzcat)
TOOLS_PLATFORM.bzcat?=		/usr/bin/bzcat
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
TOOLS_PLATFORM.cut?=		/usr/bin/cut
TOOLS_PLATFORM.date?=		/usr/xpg4/bin/date
TOOLS_PLATFORM.dirname?=	/usr/bin/dirname
TOOLS_PLATFORM.echo?=		/usr/ucb/echo
TOOLS_PLATFORM.egrep?=		/usr/xpg4/bin/grep -E
TOOLS_PLATFORM.env?=		/usr/bin/env
TOOLS_PLATFORM.expr?=		/usr/xpg4/bin/expr
TOOLS_PLATFORM.false?=		/usr/bin/false
TOOLS_PLATFORM.fgrep?=		/usr/xpg4/bin/fgrep
TOOLS_PLATFORM.file?=		/usr/bin/file
TOOLS_PLATFORM.find?=		/usr/bin/find
TOOLS_PLATFORM.grep?=		/usr/xpg4/bin/grep
.if exists(/usr/bin/gzip)
TOOLS_PLATFORM.gunzip?=		/usr/bin/gzip -df
TOOLS_PLATFORM.gzcat?=		/usr/bin/gzip -cd
TOOLS_PLATFORM.gzip?=		/usr/bin/gzip -nf ${GZIP}
.endif
TOOLS_PLATFORM.head?=		/usr/bin/head
TOOLS_PLATFORM.hostname?=	/bin/hostname
TOOLS_PLATFORM.id?=		/usr/xpg4/bin/id
TOOLS_PLATFORM.install?=	/usr/ucb/install
TOOLS_PLATFORM.ln?=		/usr/bin/ln
TOOLS_PLATFORM.ls?=		/usr/bin/ls
TOOLS_PLATFORM.m4?=		/usr/ccs/bin/m4
TOOLS_PLATFORM.mail?=		/usr/bin/mailx
TOOLS_PLATFORM.mkdir?=		/usr/bin/mkdir -p
TOOLS_PLATFORM.mv?=		/usr/bin/mv
TOOLS_PLATFORM.nice?=		/usr/xpg4/bin/nice
.if exists(/usr/bin/gpatch)
TOOLS_PLATFORM.patch?=		/usr/bin/gpatch
.endif
TOOLS_PLATFORM.pwd?=		/bin/pwd
TOOLS_PLATFORM.rm?=		/usr/bin/rm
TOOLS_PLATFORM.rmdir?=		/usr/bin/rmdir
TOOLS_PLATFORM.sh?=		/bin/ksh
TOOLS_PLATFORM.sort?=		/usr/bin/sort
TOOLS_PLATFORM.strip?=		/usr/ccs/bin/strip
TOOLS_PLATFORM.tail?=		/usr/xpg4/bin/tail
TOOLS_PLATFORM.tee?=		/usr/bin/tee
TOOLS_PLATFORM.test?=		test			# shell builtin
TOOLS_PLATFORM.touch?=		/usr/bin/touch
TOOLS_PLATFORM.tr?=		/usr/bin/tr
TOOLS_PLATFORM.true?=		/usr/bin/true
TOOLS_PLATFORM.tsort?=		/usr/ccs/bin/tsort
TOOLS_PLATFORM.wc?=		/usr/bin/wc
TOOLS_PLATFORM.xargs?=		/usr/bin/xargs
