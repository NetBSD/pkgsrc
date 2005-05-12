# $NetBSD: vars.mk,v 1.2 2005/05/12 20:59:29 jlam Exp $
#
# This Makefile fragment exposes several Perl configuration variables
# to the package Makefiles.  The variables are only defined if the
# ${PERL5} executable exists.

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

.if defined(PERL5) && exists(${PERL5:Q})
#
# Locate some of the installation prefixes for ${PERL5} that are used to
# define later variables.
#
.  if !defined(_PERL5_PREFIX)
_PERL5_PREFIX!=		\
	eval `${PERL5:Q} -V:prefix 2>/dev/null`; ${ECHO} $$prefix
.  endif
MAKEVARS+=	_PERL5_PREFIX
.  if !defined(_PERL5_SITEPREFIX)
_PERL5_SITEPREFIX!=	\
	eval `${PERL5:Q} -V:siteprefix 2>/dev/null`; ${ECHO} $$siteprefix
.  endif
MAKEVARS+=	_PERL5_SITEPREFIX
#
# Define PERL5_SUB_* as the site variables minus the installation prefix
# define later variables.
#
.  for _var_ in ${_PERL5_SITEVARS}
.    if !defined(PERL5_SUB_${_var_})
PERL5_SUB_${_var_}!=	\
	eval `${PERL5:Q} -V:${_PERL5_SITEVAR.${_var_}} 2>/dev/null`;	\
	${ECHO} $${${_PERL5_SITEVAR.${_var_}}} | ${SED} -e "s,^${_PERL5_SITEPREFIX}/,,"
.    endif
MAKEVARS+=	PERL5_SUB_${_var_}
.  endfor

.  if !defined(PERL5_SUB_INSTALLARCHLIB)
PERL5_SUB_INSTALLARCHLIB!=	\
	eval `${PERL5} -V:installarchlib 2>/dev/null`;			\
	${ECHO} $$installarchlib | ${SED} -e "s,^${_PERL5_PREFIX}/,,"
.  endif
MAKEVARS+=	PERL5_SUB_INSTALLARCHLIB
.  if !defined(PERL5_SUB_INSTALLSCRIPT)
PERL5_SUB_INSTALLSCRIPT!=	\
	eval `${PERL5} -V:installscript 2>/dev/null`;			\
	${ECHO} $$installscript | ${SED} -e "s,^${_PERL5_PREFIX}/,,"
.  endif
MAKEVARS+=	PERL5_SUB_INSTALLSCRIPT
.endif	# PERL5

.if ${PKG_INSTALLATION_TYPE} == "overwrite"
.  for _var_ in SITELIB SITEARCH ARCHLIB
PERL5_${_var_}?=	${LOCALBASE}/${PERL5_SUB_INSTALL${_var_}}
.  endfor
.endif
