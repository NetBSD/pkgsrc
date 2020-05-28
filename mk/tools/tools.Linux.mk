# $NetBSD: tools.Linux.mk,v 1.64 2020/05/28 14:47:36 nia Exp $
#
# System-supplied tools for the Linux operating system.

TOOLS_PLATFORM.[?=		[			# shell builtin
.if exists(/etc/debian_version)
TOOLS_PLATFORM.awk?=		/usr/bin/awk
.else
TOOLS_PLATFORM.awk?=		${TOOLS_PLATFORM.gawk}
.endif
.if exists(/usr/bin/autopoint)
TOOLS_PLATFORM.autopoint?=	/usr/bin/autopoint
.endif
.if exists(/bin/basename)
TOOLS_PLATFORM.basename?=	/bin/basename
.elif exists(/usr/bin/basename)
TOOLS_PLATFORM.basename?=	/usr/bin/basename
.endif
.if exists(/bin/bash)
TOOLS_PLATFORM.bash?=		/bin/bash
.endif
.if exists(/usr/bin/bison)
TOOLS_PLATFORM.bison?=		/usr/bin/bison
TOOLS_PLATFORM.bison-yacc?=	/usr/bin/bison -y
.endif
.if exists(/usr/bin/bzcat)
TOOLS_PLATFORM.bzcat?=		/usr/bin/bzcat
.elif exists(/bin/bzcat)
TOOLS_PLATFORM.bzcat?=		/bin/bzcat
.elif exists(/usr/bin/bzip2)
TOOLS_PLATFORM.bzcat?=		/usr/bin/bzip2 -cd
.endif
.if exists(/usr/bin/bzip2)
TOOLS_PLATFORM.bzip2?=		/usr/bin/bzip2
.elif exists(/bin/bzip2)
TOOLS_PLATFORM.bzip2?=		/bin/bzip2
.endif
TOOLS_PLATFORM.cat?=		/bin/cat
.if exists(/bin/chgrp)
TOOLS_PLATFORM.chgrp?=		/bin/chgrp
.elif exists(/usr/bin/chgrp)
TOOLS_PLATFORM.chgrp?=		/usr/bin/chgrp
.endif
TOOLS_PLATFORM.chmod?=		/bin/chmod
.if exists(/bin/chown)
TOOLS_PLATFORM.chown?=		/bin/chown
.elif exists(/usr/sbin/chown)
TOOLS_PLATFORM.chown?=		/usr/sbin/chown
.endif
.if exists(/bin/cmp)
TOOLS_PLATFORM.cmp?=		/bin/cmp
.elif exists(/usr/bin/cmp)
TOOLS_PLATFORM.cmp?=		/usr/bin/cmp
.endif
TOOLS_PLATFORM.cp?=		/bin/cp
.if exists(/bin/tcsh)
TOOLS_PLATFORM.csh?=		/bin/tcsh
.endif
.if exists(/usr/bin/curl)
TOOLS_PLATFORM.curl?=		/usr/bin/curl
.endif
.if exists(/bin/cut)
TOOLS_PLATFORM.cut?=		/bin/cut
.elif exists(/usr/bin/cut)
TOOLS_PLATFORM.cut?=		/usr/bin/cut
.endif
TOOLS_PLATFORM.date?=		/bin/date
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
.if exists(/bin/egrep)
TOOLS_PLATFORM.egrep?=		/bin/egrep
TOOLS_PLATFORM.gegrep?=		/bin/egrep
.elif exists(/usr/bin/egrep)
TOOLS_PLATFORM.egrep?=		/usr/bin/egrep
TOOLS_PLATFORM.gegrep?=		/usr/bin/egrep
.endif
TOOLS_PLATFORM.env?=		/usr/bin/env
.if exists(/usr/bin/expr)
TOOLS_PLATFORM.expr?=		/usr/bin/expr
.elif exists(/bin/expr)
TOOLS_PLATFORM.expr?=		/bin/expr
.endif
TOOLS_PLATFORM.false?=		false			# shell builtin
.if exists(/bin/fgrep)
TOOLS_PLATFORM.fgrep?=		/bin/fgrep
TOOLS_PLATFORM.gfgrep?=		/bin/fgrep
.elif exists(/usr/bin/fgrep)
TOOLS_PLATFORM.fgrep?=		/usr/bin/fgrep
TOOLS_PLATFORM.gfgrep?=		/usr/bin/fgrep
.endif
TOOLS_PLATFORM.file?=		/usr/bin/file
TOOLS_PLATFORM.find?=		/usr/bin/find
.if exists(/etc/debian_version)
.  if exists(/usr/bin/gawk)
TOOLS_PLATFORM.gawk?=		/usr/bin/gawk
.  endif
.else
.  if exists(/bin/awk)
TOOLS_PLATFORM.gawk?=		/bin/awk
.  else
TOOLS_PLATFORM.gawk?=		/usr/bin/awk
.  endif
.endif
.if exists(/usr/bin/gettext)
TOOLS_PLATFORM.gettext?=	/usr/bin/gettext
.endif
.if exists(/usr/bin/m4)
TOOLS_PLATFORM.gm4?=		/usr/bin/m4
.endif
.if exists(/usr/bin/make)
TOOLS_PLATFORM.gmake?=		/usr/bin/make
.endif
.if exists(/bin/grep)
TOOLS_PLATFORM.grep?=		/bin/grep
TOOLS_PLATFORM.ggrep?=		/bin/grep
.elif exists(/usr/bin/grep)
TOOLS_PLATFORM.grep?=		/usr/bin/grep
TOOLS_PLATFORM.ggrep?=		/usr/bin/grep
.endif
.if exists(/usr/bin/groff)
TOOLS_PLATFORM.groff?=		/usr/bin/groff
.endif
.if exists(/bin/sed)
TOOLS_PLATFORM.gsed?=		/bin/sed
.elif exists(/usr/bin/sed)
TOOLS_PLATFORM.gsed?=		/usr/bin/sed
.endif
.if exists(/usr/bin/soelim)
TOOLS_PLATFORM.gsoelim?=	/usr/bin/soelim
.endif
TOOLS_PLATFORM.gstrip?=		/usr/bin/strip
.if exists(/bin/tar)
TOOLS_PLATFORM.gtar?=		/bin/tar
.elif exists(/usr/bin/tar)
TOOLS_PLATFORM.gtar?=		/usr/bin/tar
.endif
.if exists(/bin/gunzip)
TOOLS_PLATFORM.gunzip?=		/bin/gunzip -f
.elif exists(/usr/bin/gunzip)
TOOLS_PLATFORM.gunzip?=		/usr/bin/gunzip -f
.endif
.if exists(/bin/zcat)
TOOLS_PLATFORM.gzcat?=		/bin/zcat
.elif exists(/usr/bin/zcat)
TOOLS_PLATFORM.gzcat?=		/usr/bin/zcat
.endif
.if exists(/bin/gzip)
TOOLS_PLATFORM.gzip?=		/bin/gzip -nf ${GZIP}
.elif exists(/usr/bin/gzip)
TOOLS_PLATFORM.gzip?=		/usr/bin/gzip -nf ${GZIP}
.endif
.if exists(/bin/head)
TOOLS_PLATFORM.head?=		/bin/head
.elif exists(/usr/bin/head)
TOOLS_PLATFORM.head?=		/usr/bin/head
.endif
TOOLS_PLATFORM.hostname?=	/bin/hostname
.if exists(/bin/id)
TOOLS_PLATFORM.id?=		/bin/id
.elif exists(/usr/bin/id)
TOOLS_PLATFORM.id?=		/usr/bin/id
.endif
.if exists(/usr/bin/ident)
TOOLS_PLATFORM.ident?=		/usr/bin/ident
.endif
.if exists(/bin/install)
TOOLS_PLATFORM.install?=	/bin/install
.else
TOOLS_PLATFORM.install?=	/usr/bin/install
.endif
.if exists(/sbin/install-info)
TOOLS_PLATFORM.install-info?=	/sbin/install-info
.elif exists(/usr/sbin/install-info)
TOOLS_PLATFORM.install-info?=	/usr/sbin/install-info
.elif exists(/usr/bin/install-info)
TOOLS_PLATFORM.install-info?=	/usr/bin/install-info
.endif
TOOLS_PLATFORM.ldconfig?=	/sbin/ldconfig
TOOLS_PLATFORM.ln?=		/bin/ln
TOOLS_PLATFORM.ls?=		/bin/ls
TOOLS_PLATFORM.m4?=		${TOOLS_PLATFORM.gm4}
.if exists(/bin/mail)
TOOLS_PLATFORM.mail?=		/bin/mail	# RH, Mandrake
.elif exists(/usr/bin/mail)
TOOLS_PLATFORM.mail?=		/usr/bin/mail	# Debian, Slackware, SuSE
.endif
.if exists(/usr/bin/makeinfo)
TOOLS_PLATFORM.makeinfo?=	/usr/bin/makeinfo
.endif
TOOLS_PLATFORM.mkdir?=		/bin/mkdir -p
.if exists(/usr/bin/mktemp)
TOOLS_PLATFORM.mktemp?=		/usr/bin/mktemp
.elif exists(/bin/mktemp)
TOOLS_PLATFORM.mktemp?=		/bin/mktemp
.endif
.if exists(/usr/bin/msgconv)
TOOLS_PLATFORM.msgconv?=	/usr/bin/msgconv
.endif
.if exists(/usr/bin/msgfmt)
TOOLS_PLATFORM.msgfmt?=		/usr/bin/msgfmt
.endif
.if exists(/usr/bin/msgmerge)
TOOLS_PLATFORM.msgmerge?=	/usr/bin/msgmerge
.endif
TOOLS_PLATFORM.mv?=		/bin/mv
.if exists(/bin/nice)
TOOLS_PLATFORM.nice?=		/bin/nice
.elif exists(/usr/bin/nice)
TOOLS_PLATFORM.nice?=		/usr/bin/nice
.endif
.if exists(/usr/bin/nroff)
TOOLS_PLATFORM.nroff?=		/usr/bin/nroff
.endif
.if exists(/usr/bin/openssl)
TOOLS_PLATFORM.openssl?=	/usr/bin/openssl
.endif
# Don't use GNU patch
#TOOLS_PLATFORM.patch?=		/usr/bin/patch
.if exists(/usr/bin/printf)
TOOLS_PLATFORM.printf?=		/usr/bin/printf
.endif
TOOLS_PLATFORM.pwd?=		/bin/pwd
TOOLS_PLATFORM.readlink?=	/bin/readlink
TOOLS_PLATFORM.rm?=		/bin/rm
TOOLS_PLATFORM.rmdir?=		/bin/rmdir
.if exists(/bin/sdiff)
TOOLS_PLATFORM.sdiff?=		/bin/sdiff
.elif exists(/usr/bin/sdiff)
TOOLS_PLATFORM.sdiff?=		/usr/bin/sdiff
.endif
TOOLS_PLATFORM.sed?=		${TOOLS_PLATFORM.gsed}
TOOLS_PLATFORM.sh?=		/bin/sh
.if exists(/usr/bin/sleep)
TOOLS_PLATFORM.sleep?=		/usr/bin/sleep
.else
TOOLS_PLATFORM.sleep?=		/bin/sleep
.endif
.if exists(/usr/bin/soelim)
TOOLS_PLATFORM.soelim?=		/usr/bin/soelim
.endif
.if exists(/bin/sort)
TOOLS_PLATFORM.sort?=		/bin/sort
.elif exists(/usr/bin/sort)
TOOLS_PLATFORM.sort?=		/usr/bin/sort
.endif
TOOLS_PLATFORM.strip?=		/usr/bin/strip
TOOLS_PLATFORM.tail?=		/usr/bin/tail
TOOLS_PLATFORM.tar?=		${TOOLS_PLATFORM.gtar}
.if exists(/usr/bin/tbl)
TOOLS_PLATFORM.tbl?=		/usr/bin/tbl
.endif
TOOLS_PLATFORM.tee?=		/usr/bin/tee
TOOLS_PLATFORM.test?=		test			# shell builtin
.if exists(/bin/touch)
TOOLS_PLATFORM.touch?=		/bin/touch
.elif exists(/usr/bin/touch)
TOOLS_PLATFORM.touch?=		/usr/bin/touch
.endif
TOOLS_PLATFORM.tr?=		/usr/bin/tr
TOOLS_PLATFORM.true?=		true			# shell builtin
TOOLS_PLATFORM.tsort?=		/usr/bin/tsort
.if exists(/bin/uniq)
TOOLS_PLATFORM.uniq?=		/bin/uniq
.elif exists(/usr/bin/uniq)
TOOLS_PLATFORM.uniq?=		/usr/bin/uniq
.endif
.if exists(/bin/wc)
TOOLS_PLATFORM.wc?=		/bin/wc
.elif exists(/usr/bin/wc)
TOOLS_PLATFORM.wc?=		/usr/bin/wc
.endif
.if exists(/usr/bin/wget)
TOOLS_PLATFORM.wget?=		/usr/bin/wget
.endif
TOOLS_PLATFORM.xargs?=		/usr/bin/xargs -r
.if exists(/usr/bin/xgettext)
TOOLS_PLATFORM.xgettext?=	/usr/bin/xgettext
.endif
.if exists(/usr/bin/yacc)
TOOLS_PLATFORM.yacc?=		/usr/bin/yacc
.endif
.if exists(/usr/bin/xz)
TOOLS_PLATFORM.xz?=		/usr/bin/xz
.endif
.if exists(/usr/bin/xzcat)
TOOLS_PLATFORM.xzcat?=		/usr/bin/xzcat
.endif

