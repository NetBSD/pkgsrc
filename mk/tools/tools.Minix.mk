# $NetBSD: tools.Minix.mk,v 1.11 2018/11/05 13:42:24 sevan Exp $
#
# System-supplied tools for the Minix operating system.

#System supplied tools
TOOLS_PLATFORM.[?=		/bin/[
TOOLS_PLATFORM.awk?=		/usr/bin/awk
TOOLS_PLATFORM.basename?=	/usr/bin/basename
TOOLS_PLATFORM.bsdtar?=		/bin/tar
TOOLS_PLATFORM.byacc?=		/usr/bin/yacc
TOOLS_PLATFORM.bzcat?=		/usr/bin/bzcat
TOOLS_PLATFORM.bzip2?=		/usr/bin/bzip2
TOOLS_PLATFORM.cat?=		/bin/cat
TOOLS_PLATFORM.chgrp?=		/bin/chgrp
TOOLS_PLATFORM.chmod?=		/bin/chmod
TOOLS_PLATFORM.chown?=		/sbin/chown
TOOLS_PLATFORM.cmp?=		/usr/bin/cmp
TOOLS_PLATFORM.cp?=		/bin/cp
TOOLS_PLATFORM.cut?=		/usr/bin/cut
TOOLS_PLATFORM.date?=		/bin/date
TOOLS_PLATFORM.diff?=		/usr/bin/diff
TOOLS_PLATFORM.dirname?=	/usr/bin/dirname
TOOLS_PLATFORM.echo?=		/bin/echo
TOOLS_PLATFORM.egrep?=		/usr/bin/egrep
TOOLS_PLATFORM.env?=		/usr/bin/env
TOOLS_PLATFORM.expr?=		/bin/expr
TOOLS_PLATFORM.false?=		/usr/bin/false
TOOLS_PLATFORM.fetch?=		/usr/bin/fetch
TOOLS_PLATFORM.fgrep?=		/usr/bin/fgrep
TOOLS_PLATFORM.file?=		/usr/bin/file
TOOLS_PLATFORM.find?=		/usr/bin/find
TOOLS_PLATFORM.flex?=		/usr/bin/flex
TOOLS_PLATFORM.ftp?=		/usr/bin/ftp
TOOLS_PLATFORM.gegrep?=		/usr/bin/egrep
TOOLS_PLATFORM.gfgrep?=		/usr/bin/fgrep
TOOLS_PLATFORM.ggrep?=		/usr/bin/grep
TOOLS_PLATFORM.grep?=		/usr/bin/grep
TOOLS_PLATFORM.gsoelim?=	${TOOLS_PLATFORM.soelim}	# GNUish
TOOLS_PLATFORM.gunzip?=		/usr/bin/gunzip -f
TOOLS_PLATFORM.gzcat?=		/usr/bin/gzcat
TOOLS_PLATFORM.gzip?=		/usr/bin/gzip -nf ${GZIP}
TOOLS_PLATFORM.head?=		/usr/bin/head
TOOLS_PLATFORM.hostname?=	/bin/hostname
TOOLS_PLATFORM.id?=		/usr/bin/id
.if empty(USE_CROSS_COMPILE:M[yY][eE][sS])
TOOLS_PLATFORM.install?=	/usr/bin/install
.else
TOOLS_PLATFORM.install?=	${TOOLDIR}/bin/${MACHINE_GNU_PLATFORM}-install
.endif
TOOLS_PLATFORM.install-info?=	/usr/bin/install-info
TOOLS_PLATFORM.ksh?=		/bin/ksh
TOOLS_PLATFORM.lex?=		/usr/bin/lex
TOOLS_PLATFORM.ln?=		/bin/ln
TOOLS_PLATFORM.ls?=		/bin/ls
TOOLS_PLATFORM.m4?=		/usr/bin/m4
TOOLS_PLATFORM.mail?=		/usr/bin/mail
TOOLS_PLATFORM.makeinfo?=	/usr/bin/makeinfo
TOOLS_PLATFORM.mkdir?=		/bin/mkdir -p
TOOLS_PLATFORM.mktemp?=		/usr/bin/mktemp
TOOLS_PLATFORM.mtree?=		/usr/sbin/mtree
TOOLS_PLATFORM.mv?=		/bin/mv
TOOLS_PLATFORM.nice?=		/usr/bin/nice
TOOLS_PLATFORM.nroff?=		/usr/bin/nroff
TOOLS_PLATFORM.openssl?=	/usr/bin/openssl
TOOLS_PLATFORM.patch?=		/usr/bin/patch
TOOLS_PLATFORM.pax?=		/bin/pax
TOOLS_PLATFORM.printf?=		/usr/bin/printf
TOOLS_PLATFORM.pwd?=		/bin/pwd
.if empty(USE_CROSS_COMPILE:M[yY][eE][sS])
TOOLS_PLATFORM.readelf?=	/usr/bin/readelf
.else
TOOLS_PLATFORM.readelf?=	${TOOLDIR}/bin/${MACHINE_GNU_PLATFORM}-readelf
.endif
TOOLS_PLATFORM.readlink?=	/usr/bin/readlink
TOOLS_PLATFORM.rm?=		/bin/rm
TOOLS_PLATFORM.rmdir?=		/bin/rmdir
TOOLS_PLATFORM.sdiff?=		/usr/bin/sdiff
TOOLS_PLATFORM.sed?=		/usr/bin/sed
TOOLS_PLATFORM.sh?=		/bin/sh
TOOLS_PLATFORM.shlock?=		/usr/bin/shlock
TOOLS_PLATFORM.sleep?=		/bin/sleep
TOOLS_PLATFORM.soelim?=		/usr/bin/soelim
TOOLS_PLATFORM.sort?=		/usr/bin/sort
.if empty(USE_CROSS_COMPILE:M[yY][eE][sS])
TOOLS_PLATFORM.strip?=		/usr/bin/strip
.else
TOOLS_PLATFORM.strip?=		${TOOLDIR}/bin/${MACHINE_GNU_PLATFORM}-strip
.endif
TOOLS_PLATFORM.tail?=		/usr/bin/tail
TOOLS_PLATFORM.tar?=		/bin/tar
TOOLS_PLATFORM.tee?=		/usr/bin/tee
TOOLS_PLATFORM.test?=		/bin/test
TOOLS_PLATFORM.touch?=		/usr/bin/touch
TOOLS_PLATFORM.tr?=		/usr/bin/tr
TOOLS_PLATFORM.true?=		/usr/bin/true
TOOLS_PLATFORM.tsort?=		/usr/bin/tsort
TOOLS_PLATFORM.uniq?=		/usr/bin/uniq
TOOLS_PLATFORM.wc?=		/usr/bin/wc
TOOLS_PLATFORM.xargs?=		/usr/bin/xargs
TOOLS_PLATFORM.xz?=		/usr/bin/xz
TOOLS_PLATFORM.xzcat?=		/usr/bin/xzcat
TOOLS_PLATFORM.yacc?=		/usr/bin/yacc

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
.  for _t_ in ar as ld nm objcopy objdump ranlib readelf strip
TOOLS_PATH.${MACHINE_GNU_PLATFORM}-${_t_}?=	\
	${TOOLDIR}/bin/${MACHINE_GNU_PLATFORM}-${_t_}
TOOLS_CREATE+=	${MACHINE_GNU_PLATFORM}-${_t_}
.  endfor

TOOLS_PATH.ar?=		${TOOLDIR}/bin/${MACHINE_GNU_PLATFORM}-ar
TOOLS_CREATE+=			ar
TOOLS_PATH.ranlib?=		${TOOLDIR}/bin/${MACHINE_GNU_PLATFORM}-ranlib
TOOLS_CREATE+=			ranlib

NATIVE_CC:=	/usr/bin/cc -B /usr/libexec -B /usr/bin
CC=		${TOOLDIR}/bin/${MACHINE_GNU_PLATFORM}-gcc

NATIVE_CXX:=	/usr/bin/c++ -B /usr/libexec -B /usr/bin
CXX=		${TOOLDIR}/bin/${MACHINE_GNU_PLATFORM}-g++

NATIVE_LD:=	/usr/bin/ld
LD=		${TOOLDIR}/bin/${MACHINE_GNU_PLATFORM}-ld

.endif
