# $NetBSD: buildlink2.mk,v 1.1.2.3 2002/06/21 23:00:34 jlam Exp $

.if !defined(PERL5_BUILDLINK2_MK)
PERL5_BUILDLINK2_MK=  # defined

.include "../../mk/bsd.prefs.mk"

PERL5_REQD?=			5.0
BUILDLINK_PACKAGES+=		perl
BUILDLINK_DEPENDS.perl?=	perl>=${PERL5_REQD}
BUILDLINK_PKGSRCDIR.perl?=	../../lang/perl5

EVAL_PREFIX+=		BUILDLINK_PREFIX.perl=perl
BUILDLINK_PREFIX.perl_DEFAULT=	${LOCALBASE}
PERL5?=			${BUILDLINK_PREFIX.perl}/bin/perl

BUILDLINK_FILES.perl=	${PERL5_ARCHLIB:S/^${BUILDLINK_PREFIX.perl}\///}/CORE/*

BUILDLINK_TARGETS+=	perl-buildlink

perl-buildlink: _BUILDLINK_USE

.endif  # PERL5_BUILDLINK2_MK

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
