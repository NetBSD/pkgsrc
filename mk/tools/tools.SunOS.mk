# $NetBSD: tools.SunOS.mk,v 1.30 2008/09/11 23:00:31 adrianp Exp $
#
# System-supplied tools for the Solaris operating system.
#
# We bootstrap a pdksh shell on this platform.

TOOLS_PLATFORM.[?=		[			# shell builtin
TOOLS_PLATFORM.awk?=		/usr/bin/nawk
TOOLS_PLATFORM.basename?=	/usr/bin/basename
.if exists(/bin/bash)
TOOLS_PLATFORM.bash?=		/bin/bash
.endif
.if exists(/usr/bin/bzcat)
TOOLS_PLATFORM.bzcat?=		/usr/bin/bzcat
.endif
.if exists(/usr/bin/bzip2)
TOOLS_PLATFORM.bzip2?=		/usr/bin/bzip2
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
TOOLS_PLATFORM.csh?=		/bin/csh
TOOLS_PLATFORM.cut?=		/usr/bin/cut
TOOLS_PLATFORM.date?=		/usr/xpg4/bin/date
.if exists(/bin/diff)
TOOLS_PLATFORM.diff?=		/bin/diff
.elif exists(/usr/bin/diff)
TOOLS_PLATFORM.diff?=		/usr/bin/diff
.endif
.if exists(/bin/diff3)
TOOLS_PLATFORM.diff3?=		/bin/diff3
.elif exists(/usr/bin/diff3)
TOOLS_PLATFORM.diff3?=		/usr/bin/diff3
.endif
TOOLS_PLATFORM.dirname?=	/usr/bin/dirname
TOOLS_PLATFORM.echo?=		echo			# shell builtin
TOOLS_PLATFORM.egrep?=		/usr/xpg4/bin/grep -E
TOOLS_PLATFORM.env?=		/usr/bin/env
TOOLS_PLATFORM.expr?=		/usr/xpg4/bin/expr
.if exists(/usr/gnu/bin/false)	# if we are using OpenSolaris
TOOLS_PLATFORM.false?=		/usr/gnu/bin/false
.else
TOOLS_PLATFORM.false?=		false			# shell builtin
.endif
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
.if exists(/usr/bin/ginstall)	# if we are using OpenSolaris
TOOLS_PLATFORM.install?=	/usr/bin/ginstall
.else
TOOLS_PLATFORM.install?=	/usr/ucb/install
.endif
TOOLS_PLATFORM.ln?=		/usr/bin/ln
TOOLS_PLATFORM.ls?=		/usr/bin/ls
TOOLS_PLATFORM.m4?=		/usr/ccs/bin/m4
TOOLS_PLATFORM.mail?=		/usr/bin/mailx
TOOLS_PLATFORM.mkdir?=		/usr/bin/mkdir -p
.if exists(/usr/bin/mktemp)
TOOLS_PLATFORM.mktemp?=		/usr/bin/mktemp
.endif
TOOLS_PLATFORM.mv?=		/usr/bin/mv
TOOLS_PLATFORM.nice?=		/usr/xpg4/bin/nice
.if exists(/usr/bin/nroff)
TOOLS_PLATFORM.nroff?=		/usr/bin/nroff
.endif
.if exists(/usr/bin/openssl)
TOOLS_PLATFORM.openssl?=	/usr/bin/openssl
.endif
.if exists(/usr/bin/gpatch)
TOOLS_PLATFORM.patch?=		/usr/bin/gpatch
.endif
TOOLS_PLATFORM.printf?=		/bin/printf
TOOLS_PLATFORM.pwd?=		/bin/pwd
TOOLS_PLATFORM.rm?=		/usr/bin/rm
TOOLS_PLATFORM.rmdir?=		/usr/bin/rmdir
.if exists(/bin/sdiff)
TOOLS_PLATFORM.sdiff?=		/bin/sdiff
.elif exists(/usr/bin/sdiff)
TOOLS_PLATFORM.sdiff?=		/usr/bin/sdiff
.endif
TOOLS_PLATFORM.sh?=		/bin/ksh
TOOLS_PLATFORM.sleep?=		/bin/sleep
.if exists(/usr/bin/soelim)
TOOLS_PLATFORM.tbl?=		/usr/bin/soelim
.endif
TOOLS_PLATFORM.sort?=		/usr/bin/sort
TOOLS_PLATFORM.strip?=		/usr/ccs/bin/strip
TOOLS_PLATFORM.tail?=		/usr/xpg4/bin/tail
.if exists(/usr/bin/tbl)
TOOLS_PLATFORM.tbl?=		/usr/bin/tbl
.endif
TOOLS_PLATFORM.tee?=		/usr/bin/tee
TOOLS_PLATFORM.test?=		test			# shell builtin
TOOLS_PLATFORM.touch?=		/usr/bin/touch
TOOLS_PLATFORM.tr?=		/usr/bin/tr
TOOLS_PLATFORM.true?=		true			# shell builtin
TOOLS_PLATFORM.tsort?=		/usr/ccs/bin/tsort
TOOLS_PLATFORM.wc?=		/usr/bin/wc
TOOLS_PLATFORM.xargs?=		/usr/bin/xargs
