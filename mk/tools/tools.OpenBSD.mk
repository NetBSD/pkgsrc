# $NetBSD: tools.OpenBSD.mk,v 1.38 2023/05/09 14:50:33 schmonz Exp $
#
# System-supplied tools for the OpenBSD operating system.

TOOLS_PLATFORM.[?=		[			# shell builtin
TOOLS_PLATFORM.awk?=		/usr/bin/awk
TOOLS_PLATFORM.basename?=	/usr/bin/basename
TOOLS_PLATFORM.byacc?=		/usr/bin/yacc
TOOLS_PLATFORM.cat?=		/bin/cat
.if exists(/bin/chgrp)
TOOLS_PLATFORM.chgrp?=		/bin/chgrp
.elif exists(/usr/bin/chgrp)
TOOLS_PLATFORM.chgrp?=		/usr/bin/chgrp
.elif exists(/usr/sbin/chgrp)
TOOLS_PLATFORM.chgrp?=		/usr/sbin/chgrp
.endif
TOOLS_PLATFORM.chmod?=		/bin/chmod
.if exists(/sbin/chown)
TOOLS_PLATFORM.chown?=		/sbin/chown
.elif exists(/usr/sbin/chown)
TOOLS_PLATFORM.chown?=		/usr/sbin/chown
.endif
TOOLS_PLATFORM.cmp?=		/usr/bin/cmp
TOOLS_PLATFORM.cp?=		/bin/cp
TOOLS_PLATFORM.csh?=		/bin/csh
TOOLS_PLATFORM.cut?=		/usr/bin/cut
TOOLS_PLATFORM.date?=		/bin/date
TOOLS_PLATFORM.diff?=		/usr/bin/diff
TOOLS_PLATFORM.diff3?=		/usr/bin/diff3
TOOLS_PLATFORM.dirname?=	/usr/bin/dirname
TOOLS_PLATFORM.echo?=		echo			# shell builtin
TOOLS_PLATFORM.egrep?=		/usr/bin/egrep
TOOLS_PLATFORM.env?=		/usr/bin/env
TOOLS_PLATFORM.expr?=		/bin/expr
TOOLS_PLATFORM.false?=		false			# shell builtin
TOOLS_PLATFORM.fgrep?=		/usr/bin/fgrep
TOOLS_PLATFORM.file?=		/usr/bin/file
TOOLS_PLATFORM.find?=		/usr/bin/find
TOOLS_PLATFORM.flex?=		/usr/bin/lex
TOOLS_PLATFORM.grep?=		/usr/bin/grep
TOOLS_PLATFORM.gstrip?=		/usr/bin/strip
TOOLS_PLATFORM.gunzip?=		/usr/bin/gunzip -f
TOOLS_PLATFORM.gzcat?=		/usr/bin/gzcat
TOOLS_PLATFORM.gzip?=		/usr/bin/gzip -nf ${GZIP}
TOOLS_PLATFORM.head?=		/usr/bin/head
TOOLS_PLATFORM.hostname?=	/bin/hostname
TOOLS_PLATFORM.id?=		/usr/bin/id
TOOLS_PLATFORM.ident?=		/usr/bin/ident
TOOLS_PLATFORM.install?=	/usr/bin/install
.if exists(/usr/bin/install-info)
TOOLS_PLATFORM.install-info?=	/usr/bin/install-info
.endif
TOOLS_PLATFORM.ldconfig?=	/sbin/ldconfig
TOOLS_PLATFORM.ksh?=		/bin/ksh
TOOLS_PLATFORM.lex?=		/usr/bin/lex
TOOLS_PLATFORM.ln?=		/bin/ln
TOOLS_PLATFORM.ls?=		/bin/ls
TOOLS_PLATFORM.m4?=		/usr/bin/m4
TOOLS_PLATFORM.mail?=		/usr/bin/mail
.if exists(/usr/bin/makeinfo)
TOOLS_PLATFORM.makeinfo?=	/usr/bin/makeinfo
.endif
TOOLS_PLATFORM.mandoc?=		/usr/bin/mandoc
TOOLS_PLATFORM.mkdir?=		/bin/mkdir -p
TOOLS_PLATFORM.mktemp?=		/usr/bin/mktemp
TOOLS_PLATFORM.mtree?=		/usr/sbin/mtree
TOOLS_PLATFORM.mv?=		/bin/mv
TOOLS_PLATFORM.nice?=		/usr/bin/nice
.if exists(/usr/bin/nroff)
TOOLS_PLATFORM.nroff?=		/usr/bin/nroff
.endif
.if exists(/usr/bin/openssl)
TOOLS_PLATFORM.openssl?=	/usr/bin/openssl
.elif exists(/usr/sbin/openssl)
TOOLS_PLATFORM.openssl?=	/usr/sbin/openssl
.endif
TOOLS_PLATFORM.patch?=		/usr/bin/patch
TOOLS_PLATFORM.pax?=		/bin/pax
TOOLS_PLATFORM.printf?=		/usr/bin/printf
TOOLS_PLATFORM.pwd?=		/bin/pwd
TOOLS_PLATFORM.readelf?=	/usr/bin/readelf
TOOLS_PLATFORM.readlink?=	/usr/bin/readlink
TOOLS_PLATFORM.rm?=		/bin/rm
TOOLS_PLATFORM.rmdir?=		/bin/rmdir
TOOLS_PLATFORM.sdiff?=		/usr/bin/sdiff
TOOLS_PLATFORM.sed?=		/usr/bin/sed
TOOLS_PLATFORM.sh?=		/bin/sh
TOOLS_PLATFORM.sleep?=		/bin/sleep
.if exists(/usr/bin/soelim)
TOOLS_PLATFORM.soelim?=		/usr/bin/soelim
.endif
TOOLS_PLATFORM.sort?=		/usr/bin/sort
TOOLS_PLATFORM.strip?=		/usr/bin/strip
TOOLS_PLATFORM.tail?=		/usr/bin/tail
.if exists(/bin/tar)
TOOLS_PLATFORM.tar?=		/bin/tar
.elif exists(/usr/bin/tar)
TOOLS_PLATFORM.tar?=		/usr/bin/tar
.endif
.if exists(/usr/bin/tbl)
TOOLS_PLATFORM.tbl?=		/usr/bin/tbl
.endif
TOOLS_PLATFORM.tee?=		/usr/bin/tee
TOOLS_PLATFORM.test?=		test			# shell builtin
TOOLS_PLATFORM.touch?=		/usr/bin/touch
TOOLS_PLATFORM.tr?=		/usr/bin/tr
TOOLS_PLATFORM.true?=		true			# shell builtin
TOOLS_PLATFORM.tsort?=		/usr/bin/tsort
TOOLS_PLATFORM.uniq?=		/usr/bin/uniq
TOOLS_PLATFORM.wc?=		/usr/bin/wc
TOOLS_PLATFORM.xargs?=		/usr/bin/xargs -r
TOOLS_PLATFORM.yacc?=		/usr/bin/yacc
