# $NetBSD: coreutils.mk,v 1.3 2005/04/26 23:02:48 jlam Exp $
#
# This Makefile fragment unconditionally replaces the system-supplied
# "core" utilities with the ones from the GNU coreutils package when
# "coreutils" is added to USE_TOOLS.
#
# Set TOOLS_DEPENDS.coreutils to "DEPENDS" to get a run-time dependency
# on coreutils.
#

.if !defined(TOOLS_IGNORE.coreutils) && !empty(USE_TOOLS:Mcoreutils)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=		TOOLS_IGNORE.coreutils=
.  else
TOOLS_DEPENDS.coreutils?=	BUILD_DEPENDS
${TOOLS_DEPENDS.coreutils}+=	coreutils>=5.2.1:../../sysutils/coreutils

# List of core utilities for which we'll create symlinks under
# ${TOOLS_DIR}.  This isn't every utility provided by coreutils, but
# is instead restricted to just the ones that are also listed in
# mk/platform/*.mk.
#
_TOOLS_COREUTILS+=	[ basename cat chgrp chmod chown cp cut date	\
			dirname echo env expr false head hostname id ln	\
			ls mkdir mv nice pwd rm rmdir sort tail tee	\
			test touch tr true tsort wc

_TOOLS_VARNAME.basename=	BASENAME
_TOOLS_VARNAME.cat=		CAT
_TOOLS_VARNAME.chgrp=		CHGRP
_TOOLS_VARNAME.chmod=		CHMOD
_TOOLS_VARNAME.chown=		CHOWN
_TOOLS_VARNAME.cp=		CP
_TOOLS_VARNAME.cut=		CUT
_TOOLS_VARNAME.date=		DATE
_TOOLS_VARNAME.dirname=		DIRNAME
_TOOLS_VARNAME.echo=		ECHO
_TOOLS_VARNAME.env=		SETENV
_TOOLS_VARNAME.expr=		EXPR
_TOOLS_VARNAME.false=		FALSE
_TOOLS_VARNAME.head=		HEAD
_TOOLS_VARNAME.hostname=	HOSTNAME
_TOOLS_VARNAME.id=		ID
_TOOLS_VARNAME.ln=		LN
_TOOLS_VARNAME.ls=		LS
_TOOLS_VARNAME.mkdir=		MKDIR
_TOOLS_VARNAME.mv=		MV
_TOOLS_VARNAME.nice=		NICE
_TOOLS_VARNAME.pwd=		PWD
_TOOLS_VARNAME.rm=		RM
_TOOLS_VARNAME.rmdir=		RMDIR
_TOOLS_VARNAME.sort=		SORT
_TOOLS_VARNAME.tail=		TAIL
_TOOLS_VARNAME.tee=		TEE
_TOOLS_VARNAME.test=		TEST
_TOOLS_VARNAME.touch=		TOUCH
_TOOLS_VARNAME.tr=		TR
_TOOLS_VARNAME.true=		TRUE
_TOOLS_VARNAME.tsort=		TSORT
_TOOLS_VARNAME.wc=		WC

# Create symlinks for each of the coreutils under ${TOOLS_DIR}.
.    for _t_ in ${_TOOLS_COREUTILS}
TOOLS_SYMLINK+=			${_t_}
TOOLS_REAL_CMD.${_t_}=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}${_t_}
.      if defined(_TOOLS_VARNAME.${_t_}) && exists(${TOOLS_REAL_CMD.${_t_}})
${_TOOLS_VARNAME.${_t_}}=	${TOOLS_REAL_CMD.${_t_}}
.      endif
.    endfor
.    undef _t_
#
# Fix up a few definitions, e.g. ${MKDIR} needs to be "mkdir -p".
#
${_TOOLS_VARNAME.mkdir}:=	${${_TOOLS_VARNAME.mkdir}} -p
.  endif
.endif
