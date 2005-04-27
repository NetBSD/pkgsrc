# $NetBSD: tools.UnixWare.mk,v 1.1 2005/04/27 15:28:16 jlam Exp $
#
# System-supplied tools for the UnixWare 7 operating system.

PLATFORM_TOOL.awk?=		/usr/bin/nawk
PLATFORM_TOOL.basename?=	/usr/bin/basename
PLATFORM_TOOL.cat?=		/usr/bin/cat
PLATFORM_TOOL.chgrp?=		/usr/bin/chgrp
PLATFORM_TOOL.chmod?=		/usr/bin/chmod
PLATFORM_TOOL.chown?=		/usr/bin/chown
PLATFORM_TOOL.cmp?=		/usr/bin/cmp
PLATFORM_TOOL.cp?=		/usr/bin/cp
PLATFORM_TOOL.cut?=		/usr/bin/cut
PLATFORM_TOOL.date?=		/usr/bin/date
PLATFORM_TOOL.dirname?=		/usr/bin/dirname
PLATFORM_TOOL.echo?=		/usr/ucb/echo
PLATFORM_TOOL.egrep?=		/usr/bin/grep -E
PLATFORM_TOOL.env?=		/usr/bin/env
PLATFORM_TOOL.expr?=		/usr/bin/expr
PLATFORM_TOOL.false?=		/usr/bin/false
PLATFORM_TOOL.fgrep?=		/usr/bin/grep -F
PLATFORM_TOOL.file?=		/usr/bin/file
PLATFORM_TOOL.find?=		/usr/bin/find
PLATFORM_TOOL.grep?=		/usr/bin/grep
PLATFORM_TOOL.head?=		/usr/bin/head
PLATFORM_TOOL.hostname?=	/usr/bin/hostname
PLATFORM_TOOL.id?=		/usr/bin/id
PLATFORM_TOOL.ln?=		/usr/bin/ln
PLATFORM_TOOL.ls?=		/usr/bin/ls
PLATFORM_TOOL.m4?=		/usr/ccs/bin/m4
PLATFORM_TOOL.mv?=		/usr/bin/mv
PLATFORM_TOOL.nice?=		/usr/bin/nice
PLATFORM_TOOL.pwd?=		/usr/bin/pwd
PLATFORM_TOOL.rm?=		/usr/bin/rm
PLATFORM_TOOL.rmdir?=		/usr/bin/rmdir
PLATFORM_TOOL.sed?=		/usr/bin/sed
PLATFORM_TOOL.sh?=		/usr/bin/ksh
PLATFORM_TOOL.sort?=		/usr/bin/sort
PLATFORM_TOOL.tail?=		/usr/bin/tail
PLATFORM_TOOL.tee?=		/usr/bin/tee
PLATFORM_TOOL.test?=		test			# shell builtin
PLATFORM_TOOL.touch?=		/usr/bin/touch
PLATFORM_TOOL.tr?=		/usr/bin/tr
PLATFORM_TOOL.true?=		/usr/bin/true
PLATFORM_TOOL.tsort?=		/usr/ccs/bin/tsort
PLATFORM_TOOL.wc?=		/usr/bin/wc
PLATFORM_TOOL.xargs?=		/usr/bin/xargs
