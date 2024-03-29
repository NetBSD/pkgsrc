# $NetBSD: tools.UnixWare.mk,v 1.15 2023/06/27 10:27:21 riastradh Exp $
#
# System-supplied tools for the UnixWare 7 operating system.

TOOLS_PLATFORM.[?=		[			# shell builtin
TOOLS_PLATFORM.awk?=		/usr/bin/nawk
TOOLS_PLATFORM.basename?=	/usr/bin/basename
TOOLS_PLATFORM.cat?=		/usr/bin/cat
TOOLS_PLATFORM.chgrp?=		/usr/bin/chgrp
TOOLS_PLATFORM.chmod?=		/usr/bin/chmod
TOOLS_PLATFORM.chown?=		/usr/bin/chown
TOOLS_PLATFORM.cmp?=		/usr/bin/cmp
TOOLS_PLATFORM.cp?=		/usr/bin/cp
TOOLS_PLATFORM.csh?=		/bin/csh
TOOLS_PLATFORM.cut?=		/usr/bin/cut
TOOLS_PLATFORM.date?=		/usr/bin/date
TOOLS_PLATFORM.diff?=		/usr/bin/diff
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
TOOLS_PLATFORM.head?=		/usr/bin/head
TOOLS_PLATFORM.hostname?=	/usr/bin/hostname
TOOLS_PLATFORM.id?=		/usr/bin/id
TOOLS_PLATFORM.install?=	/usr/ucb/install
TOOLS_PLATFORM.ln?=		/usr/bin/ln
TOOLS_PLATFORM.ls?=		/usr/bin/ls
TOOLS_PLATFORM.m4?=		/usr/ccs/bin/m4
TOOLS_PLATFORM.mail?=		/usr/bin/mailx
TOOLS_PLATFORM.mv?=		/usr/bin/mv
TOOLS_PLATFORM.nice?=		/usr/bin/nice
TOOLS_PLATFORM.nroff?=		/usr/bin/nroff
TOOLS_PLATFORM.pwd?=		/usr/bin/pwd
TOOLS_PLATFORM.rm?=		/usr/bin/rm
TOOLS_PLATFORM.rmdir?=		/usr/bin/rmdir
TOOLS_PLATFORM.sed?=		/usr/bin/sed
TOOLS_PLATFORM.sh?=		/usr/bin/ksh
TOOLS_PLATFORM.sort?=		/usr/bin/sort
TOOLS_PLATFORM.tail?=		/usr/bin/tail
TOOLS_PLATFORM.tee?=		/usr/bin/tee
TOOLS_PLATFORM.test?=		test			# shell builtin
TOOLS_PLATFORM.touch?=		/usr/bin/touch
TOOLS_PLATFORM.tr?=		/usr/bin/tr
TOOLS_PLATFORM.true?=		/usr/bin/true
TOOLS_PLATFORM.tsort?=		/usr/ccs/bin/tsort
TOOLS_PLATFORM.uniq?=		/usr/bin/uniq
TOOLS_PLATFORM.wc?=		/usr/bin/wc
TOOLS_PLATFORM.xargs?=		/usr/bin/xargs

# Special bootstrap script
TOOLS_PLATFORM.mkdir?=		${TOOLBASE}/sbin/mkdir-sh -p
