# $NetBSD: buildlink2.mk,v 1.4 2002/09/05 20:43:19 jlam Exp $

.if !defined(PERL5_BUILDLINK2_MK)
PERL5_BUILDLINK2_MK=  # defined

USE_PERL5?=	run

.include "../../mk/bsd.prefs.mk"

PERL5_REQD?=			5.0
BUILDLINK_PACKAGES+=		perl
BUILDLINK_DEPENDS.perl?=	perl>=${PERL5_REQD}
BUILDLINK_PKGSRCDIR.perl?=	../../lang/perl5

.if ${USE_PERL5} == "build"
BUILDLINK_DEPMETHOD.perl?=	build
.endif

EVAL_PREFIX+=		BUILDLINK_PREFIX.perl=perl
BUILDLINK_PREFIX.perl_DEFAULT=	${LOCALBASE}
PERL5?=			${BUILDLINK_PREFIX.perl}/bin/perl

BUILDLINK_FILES.perl=							\
	${PERL5_ARCHLIB:S/^${BUILDLINK_PREFIX.perl}\///}/CORE/*		\
	${PERL5_ARCHLIB:S/^${BUILDLINK_PREFIX.perl}\///}/auto/DynaLoader/DynaLoader.a

BUILDLINK_TARGETS+=	perl-buildlink

perl-buildlink: _BUILDLINK_USE

.endif  # PERL5_BUILDLINK2_MK
