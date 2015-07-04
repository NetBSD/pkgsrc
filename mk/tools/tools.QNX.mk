# $NetBSD: tools.QNX.mk,v 1.1 2015/07/04 07:15:22 ryoon Exp $
#
# System-supplied tools for the QNX operating system.

TOOLS_PLATFORM.[?=		[			# shell builtin
TOOLS_PLATFORM.awk?=		/usr/bin/awk
TOOLS_PLATFORM.basename?=	/usr/bin/basename
TOOLS_PLATFORM.bison?=		${QNX_HOST}/usr/bin/bison
TOOLS_PLATFORM.bison-yacc?=	${QNX_HOST}/usr/bin/bison -y
TOOLS_PLATFORM.bzcat?=		/usr/bin/bzcat
TOOLS_PLATFORM.bzip2?=		/usr/bin/bzip2
TOOLS_PLATFORM.cat?=		/bin/cat
TOOLS_PLATFORM.chgrp?=		/bin/chgrp
TOOLS_PLATFORM.chmod?=		/bin/chmod
TOOLS_PLATFORM.chown?=		/bin/chown
TOOLS_PLATFORM.cmp?=		/usr/bin/cmp
TOOLS_PLATFORM.cp?=		/bin/cp
TOOLS_PLATFORM.cpp?=		${QNX_HOST}/usr/bin/cpp
TOOLS_PLATFORM.cut?=		/usr/bin/cut
TOOLS_PLATFORM.date?=		/usr/bin/date
TOOLS_PLATFORM.diff?=		/usr/bin/diff
TOOLS_PLATFORM.diff3?=		/usr/bin/diff3
TOOLS_PLATFORM.dirname?=	/usr/bin/dirname
TOOLS_PLATFORM.echo?=		echo			# shell builtin
TOOLS_PLATFORM.egrep?=		/usr/bin/egrep
TOOLS_PLATFORM.env?=		/usr/bin/env
TOOLS_PLATFORM.expr?=		/usr/bin/expr
TOOLS_PLATFORM.false?=		false			# shell builtin
TOOLS_PLATFORM.fgrep?=		/usr/bin/fgrep
TOOLS_PLATFORM.file?=		/usr/bin/file
TOOLS_PLATFORM.find?=		/usr/bin/find
TOOLS_PLATFORM.flex?=		${QNX_HOST}/usr/bin/flex
TOOLS_PLATFORM.ftp?=		/usr/bin/ftp
TOOLS_PLATFORM.gawk?=		/usr/bin/gawk
TOOLS_PLATFORM.grep?=		/usr/bin/grep
TOOLS_PLATFORM.groff?=		${QNX_HOST}/usr/bin/groff
TOOLS_PLATFORM.gunzip?=		/bin/gunzip -f
TOOLS_PLATFORM.gzcat?=		/bin/gzip -dc
TOOLS_PLATFORM.gzip?=		/bin/gzip -nf ${GZIP}
TOOLS_PLATFORM.head?=		/usr/bin/head
TOOLS_PLATFORM.hostname?=	/bin/hostname
TOOLS_PLATFORM.id?=		/usr/bin/id
TOOLS_PLATFORM.ksh?=		/bin/ksh
TOOLS_PLATFORM.lex?=		${QNX_HOST}/usr/bin/lex
TOOLS_PLATFORM.ln?=		/bin/ln
TOOLS_PLATFORM.ls?=		/bin/ls
TOOLS_PLATFORM.m4?=		${QNX_HOST}/usr/bin/m4
TOOLS_PLATFORM.gmake?=		${QNX_HOST}/usr/bin/make
TOOLS_PLATFORM.mkdir?=		/bin/mkdir -p
TOOLS_PLATFORM.mv?=		/bin/mv
TOOLS_PLATFORM.nice?=		/usr/bin/nice
TOOLS_PLATFORM.nroff?=		${QNX_HOST}/usr/bin/nroff
TOOLS_PLATFORM.openssl?=	/usr/bin/openssl
TOOLS_PLATFORM.patch?=		/usr/bin/patch
TOOLS_PLATFORM.pax?=		/bin/pax
TOOLS_PLATFORM.printf?=		/usr/bin/printf
TOOLS_PLATFORM.pwd?=		/bin/pwd
.if empty(USE_CROSS_COMPILE:M[yY][eE][sS])
TOOLS_PLATFORM.readelf?=	${QNX_HOST}/usr/bin/readelf
.endif
TOOLS_PLATFORM.rm?=		/bin/rm
TOOLS_PLATFORM.rmdir?=		/usr/bin/rmdir
TOOLS_PLATFORM.sed?=		/usr/bin/sed
TOOLS_PLATFORM.sh?=		/bin/sh
TOOLS_PLATFORM.sleep?=		/usr/bin/sleep
TOOLS_PLATFORM.soelim?=		${QNX_HOST}/usr/bin/soelim
TOOLS_PLATFORM.sort?=		/usr/bin/sort
.if empty(USE_CROSS_COMPILE:M[yY][eE][sS])
TOOLS_PLATFORM.strip?=		${QNX_HOST}/usr/bin/strip
.endif
TOOLS_PLATFORM.tail?=		/usr/bin/tail
TOOLS_PLATFORM.tar?=		/usr/bin/tar
TOOLS_PLATFORM.tbl?=		${QNX_HOST}/usr/bin/tbl
TOOLS_PLATFORM.tee?=		/usr/bin/tee
TOOLS_PLATFORM.test?=		test			# shell builtin
TOOLS_PLATFORM.touch?=		/usr/bin/touch
TOOLS_PLATFORM.tr?=		/usr/bin/tr
TOOLS_PLATFORM.true?=		true			# shell builtin
TOOLS_PLATFORM.tsort?=		/usr/bin/tsort
TOOLS_PLATFORM.uniq?=		/usr/bin/uniq
TOOLS_PLATFORM.unzip?=		/usr/bin/unzip
TOOLS_PLATFORM.wc?=		/usr/bin/wc
TOOLS_PLATFORM.xargs?=		/usr/bin/xargs
TOOLS_PLATFORM.yacc?=		${QNX_HOST}/usr/bin/bison -y



.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
.  for _t_ in ar as ld nm objcopy objdump ranlib readelf strip
TOOLS_PATH.${MACHINE_GNU_PLATFORM}-${_t_}?=	\
	${QNX_HOST}/usr/bin/nto${MACHINE_GNU_PLATFORM}-${_t_}
TOOLS_CREATE+=	${MACHINE_GNU_PLATFORM}-${_t_}
.  endfor
TOOLS_PATH.ar?=			${QNX_HOST}/usr/bin/${MACHINE_GNU_PLATFORM}-ar
TOOLS_CREATE+=			ar
TOOLS_PATH.ranlib?=		${QNX_HOST}/usr/bin/${MACHINE_GNU_PLATFORM}-ranlib
TOOLS_CREATE+=			ranlib

NATIVE_CC:=	${QNX_HOST}/usr/bin/qcc
CC=		${QNX_HOST}/usr/bin/qcc -V gcc_nto${MACHINE_GNU_PLATFORM}

NATIVE_CXX:=	${QNX_HOST}/usr/bin/QCC
CXX=		${QNX_HOST}/usr/bin/QCC -V gcc_nto${MACHINE_GNU_PLATFORM}

NATIVE_LD:=	${QNX_HOST}/usr/bin/ld
LD=		${QNX_HOST}/usr/bin/nto${MACHINE_GNU_PLATFORM}-ld

.endif

