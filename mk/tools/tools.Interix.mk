# $NetBSD: tools.Interix.mk,v 1.24 2014/03/06 07:34:20 uebayasi Exp $
#
# System-supplied tools for the Interix operating system.

TOOLS_PLATFORM.[?=		/bin/[
.if !empty(MACHINE_PLATFORM:MInterix-[0-5].*-*)
TOOLS_PLATFORM.awk?=		/bin/awk -mr 16384
.else
TOOLS_PLATFORM.awk?=		/bin/awk
.endif
TOOLS_PLATFORM.basename?=	/bin/basename
TOOLS_PLATFORM.cat?=		/bin/cat
TOOLS_PLATFORM.chgrp?=		/bin/chgrp
TOOLS_PLATFORM.chmod?=		/bin/chmod
TOOLS_PLATFORM.chown?=		/bin/chown
TOOLS_PLATFORM.cmp?=		/bin/cmp
TOOLS_PLATFORM.cp?=		/bin/cp
TOOLS_PLATFORM.csh?=		/bin/csh
TOOLS_PLATFORM.cut?=		/bin/cut
TOOLS_PLATFORM.date?=		/bin/date
TOOLS_PLATFORM.diff?=		/bin/diff
TOOLS_PLATFORM.dirname?=	/bin/dirname
TOOLS_PLATFORM.echo?=		echo			# shell builtin
TOOLS_PLATFORM.egrep?=		/bin/egrep
TOOLS_PLATFORM.env?=		/bin/env
TOOLS_PLATFORM.expr?=		/bin/expr
TOOLS_PLATFORM.false?=		false			# shell builtin
TOOLS_PLATFORM.fgrep?=		/bin/fgrep
TOOLS_PLATFORM.file?=		/bin/file
TOOLS_PLATFORM.find?=		/bin/find
.if empty(MACHINE_PLATFORM:MInterix-[0-5].*-*)
TOOOLS_PLATFORM.gawk?=		/usr/contrib/bin/gawk
.endif
TOOLS_PLATFORM.grep?=		/bin/grep
TOOLS_PLATFORM.gunzip?=		/usr/contrib/bin/gunzip -f
TOOLS_PLATFORM.gzcat?=		/usr/contrib/bin/gunzip -c
TOOLS_PLATFORM.gzip?=		/usr/contrib/bin/gzip -nf ${GZIP}
TOOLS_PLATFORM.head?=		/bin/head
TOOLS_PLATFORM.hostname?=	/bin/hostname
TOOLS_PLATFORM.id?=		/bin/id
.if empty(MACHINE_PLATFORM:MInterix-[0-5].*-*)
TOOLS_PLATFORM.install?=	/bin/install
.endif
.if exists(/bin/install-info)
TOOLS_PLATFORM.install-info?=	/bin/install-info
.endif
.if empty(MACHINE_PLATFORM:MInterix-[0-5].*-*)
TOOLS_PLATFORM.lex?=		/bin/lex
.endif
TOOLS_PLATFORM.ln?=		/bin/ln
TOOLS_PLATFORM.ls?=		/bin/ls
TOOLS_PLATFORM.m4?=		/bin/m4
TOOLS_PLATFORM.mail?=		/bin/mail
.if exists(/bin/makeinfo)
TOOLS_PLATFORM.makeinfo?=	/bin/makeinfo
.endif
TOOLS_PLATFORM.mkdir?=		/bin/mkdir -p
TOOLS_PLATFORM.mv?=		/bin/mv
TOOLS_PLATFORM.nice?=		/bin/nice
.if empty(MACHINE_PLATFORM:MInterix-[0-5].*-*)
TOOLS_PLATFORM.patch?=		/bin/patch
.endif
TOOLS_PLATFORM.printf?=		/bin/printf
TOOLS_PLATFORM.pwd?=		/bin/pwd
TOOLS_PLATFORM.rm?=		/bin/rm
TOOLS_PLATFORM.rmdir?=		/bin/rmdir
.if empty(MACHINE_PLATFORM:MInterix-[0-5].*-*)
TOOLS_PLATFORM.pax?=		/bin/pax
TOOLS_PLATFORM.sed?=		/bin/sed
.endif
TOOLS_PLATFORM.sh?=		/bin/sh
TOOLS_PLATFORM.sleep?=		/bin/sleep
TOOLS_PLATFORM.sort?=		/bin/sort
TOOLS_PLATFORM.strip?=		/bin/strip
TOOLS_PLATFORM.tail?=		/bin/tail
TOOLS_PLATFORM.tee?=		/bin/tee
TOOLS_PLATFORM.test?=		test			# shell builtin
TOOLS_PLATFORM.touch?=		/bin/touch
TOOLS_PLATFORM.tr?=		/bin/tr
TOOLS_PLATFORM.true?=		true			# shell builtin
TOOLS_PLATFORM.tsort?=		/bin/tsort
TOOLS_PLATFORM.uniq?=		/bin/uniq
TOOLS_PLATFORM.wc?=		/bin/wc
.if !empty(MACHINE_PLATFORM:MInterix-[0-5].*-*)
TOOLS_PLATFORM.xargs?=		/bin/xargs
.else
TOOLS_PLATFORM.xargs?=		/bin/xargs -r
.endif
.if exists(/usr/contrib/unzip)
TOOLS_PLATFORM.unzip?=		/usr/contrib/unzip
.endif
.if empty(MACHINE_PLATFORM:MInterix-[0-5].*-*)
TOOLS_PLATFORM.yacc?=		/bin/yacc
.endif
