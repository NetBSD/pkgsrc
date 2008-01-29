# $NetBSD: vars.mk,v 1.4 2008/01/29 16:41:36 tnn Exp $
#
# This Makefile fragment exposes several Perl configuration variables
# to the package Makefiles.  The variables are only defined if the
# ${PERL5} executable exists.

.include "../../mk/bsd.prefs.mk"

_PERL5_VARS=	INSTALLARCHLIB INSTALLSCRIPT				\
		INSTALLVENDORBIN INSTALLVENDORSCRIPT			\
		INSTALLVENDORLIB INSTALLVENDORARCH			\
		INSTALLVENDORMAN1DIR INSTALLVENDORMAN3DIR

.if defined(PERL5) && exists(${PERL5:Q})
#
# Locate some of the installation prefixes for ${PERL5} that are used to
# define later variables.
#
.  if !defined(_PERL5_VARS_OUT)
_PERL5_VARS_CMD=	${PERL5:Q} -V:prefix ${_PERL5_VARS:tl:S/^/-V:/}
_PERL5_VARS_OUT:=	${_PERL5_VARS_CMD:sh:ts,:S/'//g:S/;//g:Q:S/,/ /g}
MAKEVARS+=		_PERL5_VARS_OUT
.  endif

.  if !defined(_PERL5_PREFIX)
_PERL5_PREFIX:=		${_PERL5_VARS_OUT:Mprefix=*:C/^prefix=//}
MAKEVARS+=		_PERL5_PREFIX
.  endif
#
# Define PERL5_SUB_* as the vendor variables minus the installation prefix
# define later variables.
#
.  for _var_ in ${_PERL5_VARS}
.    if !defined(PERL5_SUB_${_var_})
PERL5_SUB_${_var_}:=	${_PERL5_VARS_OUT:M${_var_:tl}=*:S/^${_var_:tl}=${_PERL5_PREFIX:=/}//}
.    endif
PERL5_${_var_}?=	${PREFIX}/${PERL5_SUB_${_var_}}
MAKEVARS+=		PERL5_SUB_${_var_}
PLIST_SUBST+=		PERL5_SUB_${_var_}=${PERL5_SUB_${_var_}:Q}
.  endfor
.endif	# PERL5
