# $NetBSD: vars.mk,v 1.1 2005/02/24 22:38:42 jlam Exp $
#
# This Makefile fragment exposes several Perl configuration variables
# to the package Makefiles.  The variables are only defined if the
# ${PERL5} executable exists.

.if !defined(_PERL5_VARS_MK)
_PERL5_VARS_MK=	yes

.include "../../mk/bsd.prefs.mk"

_PERL5_SITEVARS=							\
	INSTALLSITEBIN INSTALLSITELIB INSTALLSITEARCH			\
	INSTALLSITEMAN1DIR INSTALLSITEMAN3DIR				\
	SITELIBEXP SITEARCHEXP

_PERL5_SITEVAR.INSTALLSITEBIN=		installsitebin
_PERL5_SITEVAR.INSTALLSITELIB=		installsitelib
_PERL5_SITEVAR.INSTALLSITEARCH=		installsitearch
_PERL5_SITEVAR.INSTALLSITEMAN1DIR=	installsiteman1dir
_PERL5_SITEVAR.INSTALLSITEMAN3DIR=	installsiteman3dir
_PERL5_SITEVAR.SITELIBEXP=		sitelibexp
_PERL5_SITEVAR.SITEARCHEXP=		sitearchexp

.if exists(${PERL5})
.  if !defined(_PERL5_SITEPREFIX)
_PERL5_PREFIX!=		\
	eval `${PERL5} -V:prefix 2>/dev/null`; ${ECHO} $$prefix
_PERL5_SITEPREFIX!=	\
	eval `${PERL5} -V:siteprefix 2>/dev/null`; ${ECHO} $$siteprefix
MAKEFLAGS+=	_PERL5_PREFIX=${_PERL5_PREFIX:Q}
MAKEFLAGS+=	_PERL5_SITEPREFIX=${_PERL5_SITEPREFIX:Q}

.    for _var_ in ${_PERL5_SITEVARS}
.      if !defined(PERL5_SUB_${_var_})
PERL5_SUB_${_var_}!=	\
	eval `${PERL5} -V:${_PERL5_SITEVAR.${_var_}} 2>/dev/null`;	\
	${ECHO} $${${_PERL5_SITEVAR.${_var_}}} |			\
	${SED} -e "s,^${_PERL5_SITEPREFIX}/,,"
MAKEFLAGS+=	PERL5_SUB_${_var_}=${PERL5_SUB_${_var_}:Q}
.      endif
.    endfor
.    if !defined(PERL5_SUB_INSTALLARCHLIB)
PERL5_SUB_INSTALLARCHLIB!=	\
	eval `${PERL5} -V:installarchlib 2>/dev/null`;			\
	${ECHO} $$installarchlib |					\
	${SED} -e "s,^${_PERL5_PREFIX}/,,"
MAKEFLAGS+=	PERL5_SUB_INSTALLARCHLIB=${PERL5_SUB_INSTALLARCHLIB:Q}
.    endif
.    if !defined(PERL5_SUB_INSTALLSCRIPT)
PERL5_SUB_INSTALLSCRIPT!=	\
	eval `${PERL5} -V:installscript 2>/dev/null`;			\
	${ECHO} $$installscript |					\
	${SED} -e "s,^${_PERL5_PREFIX}/,,"
MAKEFLAGS+=	PERL5_SUB_INSTALLSCRIPT=${PERL5_SUB_INSTALLSCRIPT:Q}
.    endif
.  endif
.endif

.if ${PKG_INSTALLATION_TYPE} == "overwrite"
.  for _var_ in SITELIB SITEARCH ARCHLIB
.    if defined(PERL5_SUB_INSTALL${_var_})
PERL5_${_var_}?=	${LOCALBASE}/${PERL5_SUB_INSTALL${_var_}}
MAKEFLAGS+=		PERL5_${_var_}=${PERL5_${_var_}:Q}
.    endif
.  endfor
.endif

.endif	# _PERL5_VARS_MK
