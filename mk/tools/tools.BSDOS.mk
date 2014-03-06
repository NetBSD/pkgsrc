# $NetBSD: tools.BSDOS.mk,v 1.18 2014/03/06 07:34:20 uebayasi Exp $
#
# System-supplied tools for the BSD/OS operating system.

TOOLS_PLATFORM.[?=		[			# shell builtin
TOOLS_PLATFORM.awk?=		/usr/bin/awk
TOOLS_PLATFORM.basename?=	/usr/bin/basename
TOOLS_PLATFORM.cat?=		/bin/cat
TOOLS_PLATFORM.chgrp?=		/usr/bin/chgrp
TOOLS_PLATFORM.chmod?=		/bin/chmod
TOOLS_PLATFORM.chown?=		/usr/sbin/chown
TOOLS_PLATFORM.cmp?=		/usr/bin/cmp
TOOLS_PLATFORM.cp?=		/bin/cp
TOOLS_PLATFORM.csh?=		/bin/csh
TOOLS_PLATFORM.cut?=		/usr/bin/cut
TOOLS_PLATFORM.date?=		/bin/date
TOOLS_PLATFORM.diff?=		/usr/bin/diff
TOOLS_PLATFORM.dirname?=	/usr/bin/dirname
TOOLS_PLATFORM.echo?=		echo			# shell builtin
TOOLS_PLATFORM.egrep?=		/bin/egrep
TOOLS_PLATFORM.env?=		/usr/bin/env
TOOLS_PLATFORM.expr?=		/bin/expr
TOOLS_PLATFORM.false?=		false			# shell builtin
TOOLS_PLATFORM.fgrep?=		/bin/fgrep
TOOLS_PLATFORM.file?=		/usr/bin/file
TOOLS_PLATFORM.find?=		/usr/bin/find
TOOLS_PLATFORM.grep?=		/bin/grep
.if exists(/usr/bin/gunzip)
TOOLS_PLATFORM.gunzip?=		/usr/bin/gunzip -f
.elif exists(/usr/contrib/bin/gunzip)
TOOLS_PLATFORM.gunzip?=		/usr/contrib/bin/gunzip -f
.endif
.if exists(/usr/bin/gzcat)
TOOLS_PLATFORM.gzcat?=		/usr/bin/gzcat
.elif exists(/usr/contrib/bin/gzcat)
TOOLS_PLATFORM.gzcat?=		/usr/contrib/bin/gzcat
.endif
.if exists(/usr/bin/gzip)
TOOLS_PLATFORM.gzip?=		/usr/bin/gzip -nf ${GZIP}
.elif exists(/usr/contrib/bin/gzip)
TOOLS_PLATFORM.gzip?=		/usr/contrib/bin/gzip -nf ${GZIP}
.endif
TOOLS_PLATFORM.head?=		/usr/bin/head
TOOLS_PLATFORM.hostname?=	/bin/hostname
TOOLS_PLATFORM.id?=		/usr/bin/id
TOOLS_PLATFORM.install?=	/usr/bin/install
TOOLS_PLATFORM.ldconfig?=	/sbin/ldconfig
TOOLS_PLATFORM.ln?=		/bin/ln
TOOLS_PLATFORM.ls?=		/bin/ls
TOOLS_PLATFORM.m4?=		/usr/bin/m4
TOOLS_PLATFORM.mail?=		/usr/bin/mail
TOOLS_PLATFORM.mkdir?=		/bin/mkdir -p
TOOLS_PLATFORM.mv?=		/bin/mv
TOOLS_PLATFORM.mtree?=		/usr/sbin/mtree
TOOLS_PLATFORM.nice?=		/usr/bin/nice
TOOLS_PLATFORM.nroff?=		/usr/bin/nroff
.if exists(/usr/bin/patch)
TOOLS_PLATFORM.patch?=		/usr/bin/patch
.elif exists(/usr/contrib/bin/patch)
TOOLS_PLATFORM.patch?=		/usr/contrib/bin/patch
.endif
.if exists(/usr/bin/printf)
TOOLS_PLATFORM.printf?=		/usr/bin/printf
.endif
TOOLS_PLATFORM.pwd?=		/bin/pwd
TOOLS_PLATFORM.rm?=		/bin/rm
TOOLS_PLATFORM.rmdir?=		/bin/rmdir
TOOLS_PLATFORM.sed?=		/usr/bin/sed
TOOLS_PLATFORM.sh?=		/bin/bash
TOOLS_PLATFORM.sleep?=		/bin/sleep
TOOLS_PLATFORM.sort?=		/usr/bin/sort
TOOLS_PLATFORM.strip?=		/usr/bin/strip
TOOLS_PLATFORM.tail?=		/usr/bin/tail
.if exists(/bin/tar)
TOOLS_PLATFORM.tar?=		/bin/tar
.elif exists(/usr/bin/tar)
TOOLS_PLATFORM.tar?=		/usr/bin/tar
.endif
TOOLS_PLATFORM.tee?=		/usr/bin/tee
TOOLS_PLATFORM.test?=		test			# shell builtin
TOOLS_PLATFORM.touch?=		/usr/bin/touch
TOOLS_PLATFORM.tr?=		/usr/bin/tr
TOOLS_PLATFORM.true?=		true			# shell builtin
TOOLS_PLATFORM.tsort?=		/usr/bin/tsort
TOOLS_PLATFORM.uniq?=		/usr/bin/uniq
TOOLS_PLATFORM.wc?=		/usr/bin/wc
TOOLS_PLATFORM.xargs?=		/usr/bin/xargs
