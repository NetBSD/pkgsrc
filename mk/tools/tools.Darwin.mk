# $NetBSD: tools.Darwin.mk,v 1.65 2024/03/20 15:59:54 schmonz Exp $
#
# System-supplied tools for the Darwin (Mac OS X) operating system.

OSX_XCRUN=			${SETENV} PATH= /usr/bin/xcrun --no-cache

TOOLS_PLATFORM.[?=		[			# shell builtin
TOOLS_PLATFORM.awk?=		/usr/bin/awk
TOOLS_PLATFORM.basename?=	/usr/bin/basename
TOOLS_PLATFORM.bash?=		/bin/bash
# Native bison (at least up to version 2.3 in OSX Lion) does not work
# well in the tools environment and cannot locate m4sugar.m4 without
# BISON_PKGDATADIR being set.  For now just pull in the pkgsrc tool.
#TOOLS_PLATFORM.bison?=		/usr/bin/bison
#TOOLS_PLATFORM.bison-yacc?=	/usr/bin/bison -y
.if exists(/usr/bin/bsdtar)
TOOLS_PLATFORM.bsdtar?=		/usr/bin/bsdtar
.endif
# CLT 15.3.0.0.1.1708646388 does not provide yacc. Check whether the
# /usr/bin/yacc xcode-select stub's target exists before defaulting to it.
.if !defined(OSX_PATH_TO_YACC)
OSX_PATH_TO_YACC_cmd=		${OSX_XCRUN} --find yacc 2>/dev/null | \
				sed -e 's|^/Library/Developer/CommandLineTools||'
OSX_PATH_TO_YACC=		${OSX_PATH_TO_YACC_cmd:sh}
.endif
MAKEFLAGS+=			OSX_PATH_TO_YACC=${OSX_PATH_TO_YACC:Q}
.if ${OSX_PATH_TO_YACC} != ""
TOOLS_PLATFORM.byacc?=		${OSX_PATH_TO_YACC}
.endif
.if exists(/usr/bin/bzcat)
TOOLS_PLATFORM.bzcat?=		/usr/bin/bzcat
.endif
.if exists(/usr/bin/bzip2)
TOOLS_PLATFORM.bzip2?=		/usr/bin/bzip2
.endif
TOOLS_PLATFORM.cat?=		/bin/cat
TOOLS_PLATFORM.chgrp?=		/usr/bin/chgrp
TOOLS_PLATFORM.chmod?=		/bin/chmod
TOOLS_PLATFORM.chown?=		/usr/sbin/chown
TOOLS_PLATFORM.cmp?=		/usr/bin/cmp
TOOLS_PLATFORM.cp?=		/bin/cp
TOOLS_PLATFORM.csh?=		/bin/tcsh
.if exists(/usr/bin/curl)
TOOLS_PLATFORM.curl?=		/usr/bin/curl
.endif
TOOLS_PLATFORM.cut?=		/usr/bin/cut
TOOLS_PLATFORM.date?=		/bin/date
TOOLS_PLATFORM.diff?=		/usr/bin/diff
TOOLS_PLATFORM.dirname?=	/usr/bin/dirname
TOOLS_PLATFORM.echo?=		echo			# shell builtin
TOOLS_PLATFORM.egrep?=		/usr/bin/egrep
TOOLS_PLATFORM.env?=		/usr/bin/env
TOOLS_PLATFORM.expr?=		/bin/expr
TOOLS_PLATFORM.false?=		false			# shell builtin
TOOLS_PLATFORM.fgrep?=		/usr/bin/fgrep
TOOLS_PLATFORM.file?=		/usr/bin/file
TOOLS_PLATFORM.find?=		/usr/bin/find
TOOLS_PLATFORM.flex?=		/usr/bin/flex
.if exists(/usr/bin/ftp)
TOOLS_PLATFORM.ftp?=		/usr/bin/ftp
.endif
TOOLS_PLATFORM.gerep?=		/usr/bin/egrep
TOOLS_PLATFORM.gfrep?=		/usr/bin/fgrep
TOOLS_PLATFORM.ggrep?=		/usr/bin/grep
#
# Avoid using the native gnumake and gm4.  On systems up to and including Big
# Sur, the version of GNU m4 is from 2006 and unable to build autoconf 2.70.
#
# While this could be more cleanly handled with a GM4_REQD set to a recent
# version, there is a larger problem that Big Sur does not support running
# these XCode programs through a symlink, causing the links in the .tools/bin
# directory to fail.
#
# Avoiding them completely at this time is much simpler.
#
#TOOLS_PLATFORM.gmake?=		/usr/bin/gnumake
#TOOLS_PLATFORM.gm4?=		/usr/bin/gm4
#
TOOLS_PLATFORM.grep?=		/usr/bin/grep
.if exists(/usr/bin/groff)
TOOLS_PLATFORM.groff?=/usr/bin/groff
.endif
.if exists(/usr/bin/gnutar)
TOOLS_PLATFORM.gtar?=		/usr/bin/gnutar
.endif
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
.if exists(/bin/ksh)
TOOLS_PLATFORM.ksh?=		/bin/ksh
.endif
TOOLS_PLATFORM.lex?=		/usr/bin/lex
TOOLS_PLATFORM.ln?=		/bin/ln
TOOLS_PLATFORM.ls?=		/bin/ls
# CLT 15.3.0.0.1.1708646388 does not provide m4. Check whether the
# /usr/bin/m4 xcode-select stub's target exists before defaulting to it.
.if !defined(OSX_PATH_TO_M4)
OSX_PATH_TO_M4_cmd=		${OSX_XCRUN} --find m4 2>/dev/null | \
				sed -e 's|^/Library/Developer/CommandLineTools||'
OSX_PATH_TO_M4=			${OSX_PATH_TO_M4_cmd:sh}
.endif
MAKEFLAGS+=			OSX_PATH_TO_M4=${OSX_PATH_TO_M4:Q}
.if ${OSX_PATH_TO_M4} != ""
TOOLS_PLATFORM.m4?=		${OSX_PATH_TO_M4}
.endif
TOOLS_PLATFORM.mail?=		/usr/bin/mail
.if exists(/usr/bin/makeinfo)
TOOLS_PLATFORM.makeinfo?=	/usr/bin/makeinfo
.endif
.if exists(/usr/bin/mandoc)
TOOLS_PLATFORM.mandoc?=		/usr/bin/mandoc
.endif
TOOLS_PLATFORM.mkdir?=		/bin/mkdir -p
TOOLS_PLATFORM.mktemp?=		/usr/bin/mktemp
TOOLS_PLATFORM.mtree?=		/usr/sbin/mtree
TOOLS_PLATFORM.mv?=		/bin/mv
TOOLS_PLATFORM.nice?=		/usr/bin/nice
TOOLS_PLATFORM.nroff?=		/usr/bin/nroff
TOOLS_PLATFORM.openssl?=	/usr/bin/openssl
TOOLS_PLATFORM.pax?=		/bin/pax
# Don't use GNU patch
#TOOLS_PLATFORM.patch?=		/usr/bin/patch
TOOLS_PLATFORM.printf?=		/usr/bin/printf
TOOLS_PLATFORM.pwd?=		/bin/pwd
TOOLS_PLATFORM.readlink?=	/usr/bin/readlink
TOOLS_PLATFORM.rm?=		/bin/rm
TOOLS_PLATFORM.rmdir?=		/bin/rmdir
TOOLS_PLATFORM.sed?=		/usr/bin/sed
TOOLS_PLATFORM.sh?=		/bin/sh
.if exists(/usr/bin/shlock)
TOOLS_PLATFORM.shlock?=		/usr/bin/shlock
.endif
TOOLS_PLATFORM.sleep?=		/bin/sleep
.if exists(/usr/bin/soelim)
TOOLS_PLATFORM.soelim?=		/usr/bin/soelim
TOOLS_PLATFORM.gsoelim?=	/usr/bin/soelim
.endif
TOOLS_PLATFORM.sort?=		/usr/bin/sort
TOOLS_PLATFORM.strip?=		/usr/bin/strip
TOOLS_PLATFORM.tail?=		/usr/bin/tail
TOOLS_PLATFORM.tar?=		/usr/bin/tar
.if exists(/usr/bin/tbl)
TOOLS_PLATFORM.tbl?=		/usr/bin/tbl
.endif
TOOLS_PLATFORM.tclsh?=		/usr/bin/tclsh
TOOLS_PLATFORM.tee?=		/usr/bin/tee
TOOLS_PLATFORM.test?=		test			# shell builtin
TOOLS_PLATFORM.touch?=		/usr/bin/touch
TOOLS_PLATFORM.tr?=		/usr/bin/tr
TOOLS_PLATFORM.true?=		true			# shell builtin
TOOLS_PLATFORM.tsort?=		/usr/bin/tsort
TOOLS_PLATFORM.uniq?=		/usr/bin/uniq
TOOLS_PLATFORM.unzip?=		/usr/bin/unzip
TOOLS_PLATFORM.wc?=		/usr/bin/wc
.if exists(/usr/bin/wish)
TOOLS_PLATFORM.wish?=		/usr/bin/wish
.endif
TOOLS_PLATFORM.xargs?=		/usr/bin/xargs
.if ${OSX_PATH_TO_YACC} != ""
TOOLS_PLATFORM.yacc?=		${OSX_PATH_TO_YACC}
.endif
