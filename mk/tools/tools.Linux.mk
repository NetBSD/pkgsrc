# $NetBSD: tools.Linux.mk,v 1.68 2022/07/05 20:35:45 markd Exp $
#
# System-supplied tools for the Linux operating system.
#
# Yet all ye who enter be warned: various Linux distributions
# place binaries in a myriad of different paths and have a myriad
# of different userspaces.  No assumptions can be made, so this
# is best-effort.  Some distributions do not follow a remotely
# Unix-like file hierarchy.
#
# This file still assumes (until it is proven wrong) that some
# tools are provided by GNU.

.if exists(/etc/NIXOS)
_LINUX_BINPATHS?=	/run/current-system/sw/bin
.else
_LINUX_BINPATHS?=	/bin /usr/bin /sbin /usr/sbin
.endif

.for _path in ${_LINUX_BINPATHS}
.  if exists(${_path}/autopoint)
TOOLS_PLATFORM.autopoint?=	${_path}/autopoint
.  endif
.  if exists(${_path}/basename)
TOOLS_PLATFORM.basename?=	${_path}/basename
.  endif
.  if exists(${_path}/bash)
TOOLS_PLATFORM.bash?=		${_path}/bash
.  endif
.  if exists(${_path}/bison)
TOOLS_PLATFORM.bison?=		${_path}/bison
.  endif
.  if exists(${_path}/bzcat)
TOOLS_PLATFORM.bzcat?=		${_path}/bzcat
.  endif
.  if exists(${_path}/bzip2)
TOOLS_PLATFORM.bzip2?=		${_path}/bzip2
.  endif
.  if exists(${_path}/cat)
TOOLS_PLATFORM.cat?=		${_path}/cat
.  endif
.  if exists(${_path}/chgrp)
TOOLS_PLATFORM.chgrp?=		${_path}/chgrp
.  endif
.  if exists(${_path}/chmod)
TOOLS_PLATFORM.chmod?=		${_path}/chmod
.  endif
.  if exists(${_path}/chown)
TOOLS_PLATFORM.chown?=		${_path}/chown
.  endif
.  if exists(${_path}/cmp)
TOOLS_PLATFORM.cmp?=		${_path}/cmp
.  endif
.  if exists(${_path}/cp)
TOOLS_PLATFORM.cp?=		${_path}/cp
.  endif
.  if exists(${_path}/tcsh)
TOOLS_PLATFORM.csh?=		${_path}/tcsh
.  endif
.  if exists(${_path}/curl)
TOOLS_PLATFORM.curl?=		${_path}/curl
.  endif
.  if exists(${_path}/cut)
TOOLS_PLATFORM.cut?=		${_path}/cut
.  endif
.  if exists(${_path}/date)
TOOLS_PLATFORM.date?=		${_path}/date
.  endif
.  if exists(${_path}/diff)
TOOLS_PLATFORM.diff?=		${_path}/diff
.  endif
.  if exists(${_path}/diff3)
TOOLS_PLATFORM.diff3?=		${_path}/diff3
.  endif
.  if exists(${_path}/dirname)
TOOLS_PLATFORM.dirname?=	${_path}/dirname
.  endif
.  if exists(${_path}/egrep)
TOOLS_PLATFORM.egrep?=		${_path}/egrep
.  endif
.  if exists(${_path}/env)
TOOLS_PLATFORM.env?=		${_path}/env
.  endif
.  if exists(${_path}/expr)
TOOLS_PLATFORM.expr?=		${_path}/expr
.  endif
.  if exists(${_path}/fgrep)
TOOLS_PLATFORM.fgrep?=		${_path}/fgrep
.  endif
.  if exists(${_path}/file)
TOOLS_PLATFORM.file?=		${_path}/file
.  endif
.  if exists(${_path}/find)
TOOLS_PLATFORM.find?=		${_path}/find
.  endif
.  if exists(${_path}/gettext)
TOOLS_PLATFORM.gettext?=	${_path}/gettext
.  endif
.  if exists(${_path}/m4)
TOOLS_PLATFORM.m4?=		${_path}/m4
.  endif
.  if exists(${_path}/make)
TOOLS_PLATFORM.gmake?=		${_path}/make
.  endif
.  if exists(${_path}/gawk)
TOOLS_PLATFORM.gawk?=		${_path}/gawk
.  endif
.  if exists(${_path}/grep)
TOOLS_PLATFORM.grep?=		${_path}/grep
.  endif
.  if exists(${_path}/groff)
TOOLS_PLATFORM.groff?=		${_path}/groff
.  endif
.  if exists(${_path}/sed)
TOOLS_PLATFORM.sed?=		${_path}/sed
.  endif
.  if exists(${_path}/soelim)
TOOLS_PLATFORM.gsoelim?=	${_path}/soelim
.  endif
.  if exists(${_path}/tar)
TOOLS_PLATFORM.tar?=		${_path}/tar
.  endif
.  if exists(${_path}/gunzip)
TOOLS_PLATFORM.gunzip?=		${_path}/gunzip -f
.  endif
.  if exists(${_path}/zcat)
TOOLS_PLATFORM.gzcat?=		${_path}/zcat
.  endif
.  if exists(${_path}/gzip)
TOOLS_PLATFORM.gzip?=		${_path}/gzip -nf ${GZIP}
.  endif
.  if exists(${_path}/head)
TOOLS_PLATFORM.head?=		${_path}/head
.  endif
.  if exists(${_path}/hostname)
TOOLS_PLATFORM.hostname?=	${_path}/hostname
.  endif
.  if exists(${_path}/id)
TOOLS_PLATFORM.id?=		${_path}/id
.  endif
.  if exists(${_path}/ident)
TOOLS_PLATFORM.ident?=		${_path}/ident
.  endif
.  if exists(${_path}/install)
TOOLS_PLATFORM.install?=	${_path}/install
.  endif
.  if exists(${_path}/install-info)
TOOLS_PLATFORM.install-info?=	${_path}/install-info
.  endif
.  if exists(${_path}/ldconfig)
TOOLS_PLATFORM.ldconfig?=	${_path}/ldconfig
.  endif
.  if exists(${_path}/ln)
TOOLS_PLATFORM.ln?=		${_path}/ln
.  endif
.  if exists(${_path}/ls)
TOOLS_PLATFORM.ls?=		${_path}/ls
.  endif
.  if exists(${_path}/mail)
TOOLS_PLATFORM.mail?=		${_path}/mail	# Debian, Slackware, SuSE
.  endif
.  if exists(${_path}/makeinfo)
TOOLS_PLATFORM.makeinfo?=	${_path}/makeinfo
.  endif
.  if exists(${_path}/mkdir)
TOOLS_PLATFORM.mkdir?=		${_path}/mkdir -p
.  endif
.  if exists(${_path}/mktemp)
TOOLS_PLATFORM.mktemp?=		${_path}/mktemp
.  endif
.  if exists(${_path}/msgconv)
TOOLS_PLATFORM.msgconv?=	${_path}/msgconv
.  endif
.  if exists(${_path}/msgfmt)
TOOLS_PLATFORM.msgfmt?=		${_path}/msgfmt
.  endif
.  if exists(${_path}/msgmerge)
TOOLS_PLATFORM.msgmerge?=	${_path}/msgmerge
.  endif
.  if exists(${_path}/mv)
TOOLS_PLATFORM.mv?=		${_path}/mv
.  endif
.  if exists(${_path}/nice)
TOOLS_PLATFORM.nice?=		${_path}/nice
.  endif
.  if exists(${_path}/nroff)
TOOLS_PLATFORM.nroff?=		${_path}/nroff
.  endif
.  if exists(${_path}/openssl)
TOOLS_PLATFORM.openssl?=	${_path}/openssl
.  endif
.  if exists(${_path}/printf)
TOOLS_PLATFORM.printf?=		${_path}/printf
.  endif
.  if exists(${_path}/pwd)
TOOLS_PLATFORM.pwd?=		${_path}/pwd
.  endif
.  if exists(${_path}/readlink)
TOOLS_PLATFORM.readlink?=	${_path}/readlink
.  endif
.  if exists(${_path}/realpath)
TOOLS_PLATFORM.realpath?=	${_path}/realpath
.  endif
.  if exists(${_path}/rm)
TOOLS_PLATFORM.rm?=		${_path}/rm
.  endif
.  if exists(${_path}/rmdir)
TOOLS_PLATFORM.rmdir?=		${_path}/rmdir
.  endif
.  if exists(${_path}/sdiff)
TOOLS_PLATFORM.sdiff?=		${_path}/sdiff
.  endif
.  if exists(${_path}/sh)
TOOLS_PLATFORM.sh?=		${_path}/sh
.  endif
.  if exists(${_path}/sleep)
TOOLS_PLATFORM.sleep?=		${_path}/sleep
.  endif
.  if exists(${_path}/soelim)
TOOLS_PLATFORM.soelim?=		${_path}/soelim
.  endif
.  if exists(${_path}/sort)
TOOLS_PLATFORM.sort?=		${_path}/sort
.  endif
.  if exists(${_path}/strip)
TOOLS_PLATFORM.strip?=		${_path}/strip
.  endif
.  if exists(${_path}/tail)
TOOLS_PLATFORM.tail?=		${_path}/tail
.  endif
.  if exists(${_path}/tbl)
TOOLS_PLATFORM.tbl?=		${_path}/tbl
.  endif
.  if exists(${_path}/tee)
TOOLS_PLATFORM.tee?=		${_path}/tee
.  endif
.  if exists(${_path}/touch)
TOOLS_PLATFORM.touch?=		${_path}/touch
.  endif
.  if exists(${_path}/tr)
TOOLS_PLATFORM.tr?=		${_path}/tr
.  endif
.  if exists(${_path}/tsort)
TOOLS_PLATFORM.tsort?=		${_path}/tsort
.  endif
.  if exists(${_path}/uniq)
TOOLS_PLATFORM.uniq?=		${_path}/uniq
.  endif
.  if exists(${_path}/wc)
TOOLS_PLATFORM.wc?=		${_path}/wc
.  endif
.  if exists(${_path}/wget)
TOOLS_PLATFORM.wget?=		${_path}/wget
.  endif
.  if exists(${_path}/xargs)
TOOLS_PLATFORM.xargs?=		${_path}/xargs -r
.  endif
.  if exists(${_path}/xgettext)
TOOLS_PLATFORM.xgettext?=	${_path}/xgettext
.  endif
.  if exists(${_path}/yacc)
TOOLS_PLATFORM.yacc?=		${_path}/yacc
.  endif
.  if exists(${_path}/xz)
TOOLS_PLATFORM.xz?=		${_path}/xz
.  endif
.  if exists(${_path}/xzcat)
TOOLS_PLATFORM.xzcat?=		${_path}/xzcat
.  endif
.endfor

TOOLS_PLATFORM.[?=		[			# shell builtin
TOOLS_PLATFORM.echo?=		echo			# shell builtin
TOOLS_PLATFORM.false?=		false			# shell builtin
TOOLS_PLATFORM.test?=		test			# shell builtin
TOOLS_PLATFORM.true?=		true			# shell builtin

# assuming grep/sed/tar/awk are usually the GNU versions, is this safe?

.if !empty(TOOLS_PLATFORM.bison)
TOOLS_PLATFORM.bison-yacc?=	${TOOLS_PLATFORM.bison} -y
.endif

TOOLS_PLATFORM.awk?=		${TOOLS_PLATFORM.gawk}

TOOLS_PLATFORM.gsed?=		${TOOLS_PLATFORM.sed}
TOOLS_PLATFORM.gtar?=		${TOOLS_PLATFORM.tar}
TOOLS_PLATFORM.gm4?=		${TOOLS_PLATFORM.m4}

TOOLS_PLATFORM.gstrip?=		${TOOLS_PLATFORM.strip}

.if !empty(TOOLS_PLATFORM.grep)
TOOLS_PLATFORM.egrep?=		${TOOLS_PLATFORM.grep} -E
TOOLS_PLATFORM.fgrep?=		${TOOLS_PLATFORM.grep} -F
TOOLS_PLATFORM.ggrep?=		${TOOLS_PLATFORM.grep}
TOOLS_PLATFORM.gegrep?=		${TOOLS_PLATFORM.egrep}
TOOLS_PLATFORM.gfgrep?=		${TOOLS_PLATFORM.fgrep}
.endif

.if !empty(TOOLS_PLATFORM.xz)
TOOLS_PLATFORM.xzcat?=		${TOOLS_PLATFORM.xz} -cd
.endif
.if !empty(TOOLS_PLATFORM.bzip2)
TOOLS_PLATFORM.bzcat?=		${TOOLS_PLATFORM.bzip2} -cd
.endif
.if !empty(TOOLS_PLATFORM.gzip)
TOOLS_PLATFORM.zcat?=		${TOOLS_PLATFORM.gzip} -cd
.endif
