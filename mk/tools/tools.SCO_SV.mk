# $NetBSD: tools.SCO_SV.mk,v 1.1 2014/03/14 22:05:18 ryoon Exp $
#
# System-supplied tools for the OpenServer 5.0.7/3.2 and 6.0.0/5.

TOOLS_PLATFORM.[?=		[			# shell builtin
TOOLS_PLATFORM.awk?=		/usr/bin/awk
TOOLS_PLATFORM.basename?=	/bin/basename
TOOLS_PLATFORM.bzcat?=		/bin/bzcat
TOOLS_PLATFORM.bzip2?=		/bin/bzip2
TOOLS_PLATFORM.cat?=		/bin/cat
TOOLS_PLATFORM.chgrp?=		/bin/chgrp
TOOLS_PLATFORM.chmod?=		/bin/chmod
TOOLS_PLATFORM.chown?=		/bin/chown
TOOLS_PLATFORM.cmp?=		/bin/cmp
TOOLS_PLATFORM.cp?=		/bin/cp
TOOLS_PLATFORM.csh?=		/bin/csh
TOOLS_PLATFORM.cut?=		/bin/cut
TOOLS_PLATFORM.date?=		/bin/date
# /bin/diff under OpenServer 5.0.7/3.2 does not support -u option.
#TOOLS_PLATFORM.diff?=		/bin/diff
TOOLS_PLATFORM.dirname?=	/bin/dirname
TOOLS_PLATFORM.echo?=		/bin/echo
TOOLS_PLATFORM.egrep?=		/usr/bin/egrep
TOOLS_PLATFORM.env?=		/bin/env
TOOLS_PLATFORM.expr?=		/bin/expr
TOOLS_PLATFORM.false?=		/bin/false
TOOLS_PLATFORM.fgrep?=		/bin/fgrep
TOOLS_PLATFORM.file?=		/bin/file
TOOLS_PLATFORM.find?=		/bin/find
TOOLS_PLATFORM.grep?=		/bin/grep
TOOLS_PLATFORM.gunzip?=		/bin/gunzip -f
TOOLS_PLATFORM.gzcat?=		/bin/gzcat
TOOLS_PLATFORM.gzip?=		/bin/gzip -nf ${GZIP}
TOOLS_PLATFORM.head?=		/bin/head
TOOLS_PLATFORM.hostname?=	/usr/bin/hostname
TOOLS_PLATFORM.id?=		/usr/bin/id
TOOLS_PLATFORM.install?=	/etc/install
TOOLS_PLATFORM.ln?=		/bin/ln
TOOLS_PLATFORM.ls?=		/bin/ls
TOOLS_PLATFORM.m4?=		/bin/m4
TOOLS_PLATFORM.mail?=		/bin/mail
TOOLS_PLATFORM.mkdir?=		/bin/mkdir -p
TOOLS_PLATFORM.msgfmt?=		/usr/gnu/bin/msgfmt
TOOLS_PLATFORM.mv?=		/bin/mv
TOOLS_PLATFORM.nice?=		/bin/nice
TOOLS_PLATFORM.printf?=		/usr/bin/printf
TOOLS_PLATFORM.pwd?=		/bin/pwd
# SCO OpenServer 5.0.7/3.2's rm cannot accept "rm -f".
TOOLS_PLATFORM.rm?=		/bin/rm
TOOLS_PLATFORM.rmdir?=		/bin/rmdir
TOOLS_PLATFORM.sed?=		/bin/sed
TOOLS_PLATFORM.sleep?=		/bin/sleep
TOOLS_PLATFORM.sh?=		/bin/sh
TOOLS_PLATFORM.sort?=		/bin/sort
TOOLS_PLATFORM.tail?=		/bin/tail
TOOLS_PLATFORM.tee?=		/bin/tee
TOOLS_PLATFORM.test?=		test			# shell builtin
TOOLS_PLATFORM.touch?=		/bin/touch
TOOLS_PLATFORM.tr?=		/usr/bin/tr
TOOLS_PLATFORM.true?=		/bin/true
TOOLS_PLATFORM.tsort?=		/bin/tsort
TOOLS_PLATFORM.wc?=		/bin/wc
TOOLS_PLATFORM.xargs?=		/usr/bin/xargs
TOOLS_PLATFORM.xgettext?=	/usr/gnu/bin/xgettext
