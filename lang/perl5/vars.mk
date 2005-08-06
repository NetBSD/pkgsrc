# $NetBSD: vars.mk,v 1.3 2005/08/06 06:18:45 jlam Exp $
#
# This Makefile fragment exposes several Perl configuration variables
# to the package Makefiles.  The variables are only defined if the
# ${PERL5} executable exists.

.include "../../mk/bsd.prefs.mk"

_PERL5_VARS=	INSTALLARCHLIB INSTALLSCRIPT				\
		INSTALLVENDORBIN INSTALLVENDORSCRIPT			\
		INSTALLVENDORLIB INSTALLVENDORARCH			\
		INSTALLVENDORMAN1DIR INSTALLVENDORMAN3DIR

_PERL5_VAR.INSTALLARCHLIB=		installarchlib
_PERL5_VAR.INSTALLSCRIPT=		installscript
_PERL5_VAR.INSTALLVENDORBIN=		installvendorbin
_PERL5_VAR.INSTALLVENDORSCRIPT=		installvendorscript
_PERL5_VAR.INSTALLVENDORLIB=		installvendorlib
_PERL5_VAR.INSTALLVENDORARCH=		installvendorarch
_PERL5_VAR.INSTALLVENDORMAN1DIR=	installvendorman1dir
_PERL5_VAR.INSTALLVENDORMAN3DIR=	installvendorman3dir

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
#
# Define PERL5_SUB_* as the vendor variables minus the installation prefix
# define later variables.
#
.  for _var_ in ${_PERL5_VARS}
.    if !defined(PERL5_SUB_${_var_})
PERL5_SUB_${_var_}!=	\
	eval `${PERL5:Q} -V:${_PERL5_VAR.${_var_}} 2>/dev/null`;	\
	${ECHO} $${${_PERL5_VAR.${_var_}}} | ${SED} -e "s,^${_PERL5_PREFIX}/,,"
.    endif
PERL5_${_var_}?=	${PREFIX}/${PERL5_SUB_${_var_}}
MAKEVARS+=		PERL5_SUB_${_var_}
PLIST_SUBST+=		PERL5_SUB_${_var_}=${PERL5_SUB_${_var_}:Q}
.  endfor
.endif	# PERL5
