# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/05/11 02:09:17 jlam Exp $
#
# This Makefile fragment is included by packages that use perl.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.perl to the dependency pattern
#     for the version of perl desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(PERL5_BUILDLINK2_MK)
PERL5_BUILDLINK2_MK=  # defined

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.buildlink2.mk"

PERL5_REQD?=			5.0
BUILDLINK_DEPENDS.perl?=	perl>=${PERL5_REQD}

BUILDLINK_PREFIX.perl?=	${LOCALBASE}
PERL5?=			${BUILDLINK_PREFIX.perl}/bin/perl

DEPENDS+=		${BUILDLINK_DEPENDS.perl}:../../lang/perl5

.if exists(${PERL5})
.  if exists(${BUILDLINK_PREFIX.perl}/share/mk/bsd.perl.mk)
.    include "${BUILDLINK_PREFIX.perl}/share/mk/bsd.perl.mk"
.  elif !defined(PERL5_SITELIB) || !defined(PERL5_SITEARCH) || !defined(PERL5_ARCHLIB)
PERL5_SITELIB!=		eval `${PERL5} -V:installsitelib 2>/dev/null`;	\
			${ECHO} $${installsitelib}
PERL5_SITEARCH!=	eval `${PERL5} -V:installsitearch 2>/dev/null`;	\
			${ECHO} $${installsitearch}
PERL5_ARCHLIB!=		eval `${PERL5} -V:installarchlib 2>/dev/null`;	\
			${ECHO} $${installarchlib}
MAKEFLAGS+=		PERL5_SITELIB=${PERL5_SITELIB}
MAKEFLAGS+=		PERL5_SITEARCH=${PERL5_SITEARCH}
MAKEFLAGS+=		PERL5_ARCHLIB=${PERL5_ARCHLIB}
.  endif # !exists(bsd.perl.mk) && !defined(PERL5_*)
.endif # exists($PERL5)

BUILDLINK_FILES.perl=	${PERL5_ARCHLIB:S/^${BUILDLINK_PREFIX.perl}\///}/CORE/*

BUILDLINK_TARGETS+=	perl-buildlink

perl-buildlink: _BUILDLINK_USE

.endif  # PERL5_BUILDLINK2_MK
