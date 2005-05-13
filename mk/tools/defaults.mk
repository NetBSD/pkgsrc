# $NetBSD: defaults.mk,v 1.11 2005/05/13 22:08:20 jlam Exp $

.if !defined(TOOLS_DEFAULTS_MK)
TOOLS_DEFAULTS_MK=	defined

# These are the platform-specific lists of system-supplied tools.
#
# XXX These should eventually just migrate over to the appropriate
# XXX pkgsrc/mk/platform/${OPSYS}.mk file.
#
.include "../../mk/tools/bootstrap.mk"
.if exists(../../mk/tools/tools.${OPSYS}.mk)
.  include "../../mk/tools/tools.${OPSYS}.mk"
.endif

# "TOOL" variable names associated with each of the tools
_TOOLS_VARNAME.awk=		AWK
_TOOLS_VARNAME.basename=	BASENAME
_TOOLS_VARNAME.bison=		YACC
_TOOLS_VARNAME.bzcat=		BZCAT
_TOOLS_VARNAME.cat=		CAT
_TOOLS_VARNAME.chgrp=		CHGRP
_TOOLS_VARNAME.chmod=		CHMOD
_TOOLS_VARNAME.chown=		CHOWN
_TOOLS_VARNAME.cmp=		CMP
_TOOLS_VARNAME.cp=		CP
_TOOLS_VARNAME.cut=		CUT
_TOOLS_VARNAME.date=		DATE
_TOOLS_VARNAME.dirname=		DIRNAME
_TOOLS_VARNAME.echo=		ECHO
_TOOLS_VARNAME.egrep=		EGREP
_TOOLS_VARNAME.env=		SETENV
_TOOLS_VARNAME.expr=		EXPR
_TOOLS_VARNAME.false=		FALSE
_TOOLS_VARNAME.fgrep=		FGREP
_TOOLS_VARNAME.file=		FILE_CMD
_TOOLS_VARNAME.find=		FIND
_TOOLS_VARNAME.gawk=		AWK
_TOOLS_VARNAME.gm4=		M4
_TOOLS_VARNAME.gmake=		GMAKE
_TOOLS_VARNAME.grep=		GREP
_TOOLS_VARNAME.gsed=		SED
_TOOLS_VARNAME.gtar=		GTAR
_TOOLS_VARNAME.gunzip=		GUNZIP_CMD
_TOOLS_VARNAME.gzcat=		GZCAT
_TOOLS_VARNAME.gzip=		GZIP_CMD
_TOOLS_VARNAME.head=		HEAD
_TOOLS_VARNAME.hostname=	HOSTNAME_CMD
_TOOLS_VARNAME.id=		ID
_TOOLS_VARNAME.imake=		IMAKE
_TOOLS_VARNAME.install=		INSTALL
_TOOLS_VARNAME.ldconfig=	LDCONFIG
_TOOLS_VARNAME.lex=		LEX
_TOOLS_VARNAME.lha=		LHA
_TOOLS_VARNAME.ln=		LN
_TOOLS_VARNAME.ls=		LS
_TOOLS_VARNAME.m4=		M4
_TOOLS_VARNAME.mail=		MAIL_CMD
_TOOLS_VARNAME.mkdir=		MKDIR
_TOOLS_VARNAME.mtree=		MTREE
_TOOLS_VARNAME.mv=		MV
_TOOLS_VARNAME.nice=		NICE
_TOOLS_VARNAME.patch=		PATCH
_TOOLS_VARNAME.pax=		PAX
_TOOLS_VARNAME.pwd=		PWD_CMD
_TOOLS_VARNAME.rm=		RM
_TOOLS_VARNAME.rmdir=		RMDIR
_TOOLS_VARNAME.sed=		SED
_TOOLS_VARNAME.sh=		SH
_TOOLS_VARNAME.shlock=		SHLOCK
_TOOLS_VARNAME.sort=		SORT
_TOOLS_VARNAME.tail=		TAIL
_TOOLS_VARNAME.tbl=		TBL
_TOOLS_VARNAME.tee=		TEE
_TOOLS_VARNAME.test=		TEST
_TOOLS_VARNAME.touch=		TOUCH
_TOOLS_VARNAME.tr=		TR
_TOOLS_VARNAME.true=		TRUE
_TOOLS_VARNAME.tsort=		TSORT
_TOOLS_VARNAME.unrar=		UNRAR
_TOOLS_VARNAME.unzip=		UNZIP
_TOOLS_VARNAME.unzoo=		UNZOO
_TOOLS_VARNAME.wc=		WC
_TOOLS_VARNAME.xargs=		XARGS
_TOOLS_VARNAME.xmkmf=		XMKMF_CMD
_TOOLS_VARNAME.yacc=		YACC

######################################################################

# Set a default value for the TOOL names for each of the tools we claim
# we'll use in PKGSRC_USE_TOOLS to point to the platform command, e.g.,
# TBL, YACC, etc.  These tools are used in the top-level make(1), not
# just in the targets, so these must be defined here, and this file be
# included by bsd.prefs.mk.
#
.for _t_ in ${PKGSRC_USE_TOOLS:O:u}
.  if defined(_TOOLS_VARNAME.${_t_}) && \
      defined(TOOLS_PLATFORM.${_t_}) && !empty(TOOLS_PLATFORM.${_t_})
.    for _v_ in ${_TOOLS_VARNAME.${_t_}}
${_v_}?=	${TOOLS_PLATFORM.${_t_}}
.    endfor
.    undef _v_
.  endif
.endfor
.undef _t_

.endif	# TOOLS_DEFAULTS_MK
