# $NetBSD: buildlink2.mk,v 1.13 2004/04/26 04:46:00 jlam Exp $

.if !defined(PERL5_BUILDLINK2_MK)
PERL5_BUILDLINK2_MK=  # defined

USE_PERL5?=	run

.include "../../mk/bsd.prefs.mk"

PERL5_REQD+=			5.0
BUILDLINK_PACKAGES+=		perl
BUILDLINK_DEPENDS.perl?=	{perl>=${_PERL5_REQD},perl-thread>=${_PERL5_REQD}}
BUILDLINK_PKGSRCDIR.perl?=	${PERL5_PKGSRCDIR}

.if ${USE_PERL5} == "build"
BUILDLINK_DEPMETHOD.perl?=	build
.endif

EVAL_PREFIX+=		BUILDLINK_PREFIX.perl=perl
BUILDLINK_PREFIX.perl_DEFAULT=	${LOCALBASE}
PERL5?=			${BUILDLINK_PREFIX.perl}/bin/perl

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
PERL5_SUB_${_var_}!=	\
	eval `${PERL5} -V:${_PERL5_SITEVAR.${_var_}} 2>/dev/null`;	\
	${ECHO} $${${_PERL5_SITEVAR.${_var_}}} |			\
	${SED} -e "s,^${_PERL5_SITEPREFIX}/,,"
MAKEFLAGS+=	PERL5_SUB_${_var_}=${PERL5_SUB_${_var_}:Q}
.    endfor
PERL5_SUB_INSTALLARCHLIB!=	\
	eval `${PERL5} -V:installarchlib 2>/dev/null`;			\
	${ECHO} $$installarchlib |					\
	${SED} -e "s,^${_PERL5_PREFIX}/,,"
MAKEFLAGS+=	PERL5_SUB_INSTALLARCHLIB=${PERL5_SUB_INSTALLARCHLIB:Q}
PERL5_SUB_INSTALLSCRIPT!=	\
	eval `${PERL5} -V:installscript 2>/dev/null`;			\
	${ECHO} $$installscript |					\
	${SED} -e "s,^${_PERL5_PREFIX}/,,"
MAKEFLAGS+=	PERL5_SUB_INSTALLSCRIPT=${PERL5_SUB_INSTALLSCRIPT:Q}
.  endif

BUILDLINK_FILES.perl=							\
	${PERL5_SUB_INSTALLARCHLIB}/CORE/*				\
	${PERL5_SUB_INSTALLARCHLIB}/auto/DynaLoader/DynaLoader.a
.endif

BUILDLINK_TARGETS+=	perl-buildlink

perl-buildlink: _BUILDLINK_USE

.endif  # PERL5_BUILDLINK2_MK
