# $NetBSD: buildlink2.mk,v 1.5 2003/09/12 23:10:03 jlam Exp $

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

.if !defined(_PERL5_PREFIX)
.  if exists(${PERL5})
_PERL5_PREFIX!=	eval `${PERL5} -V:prefix 2>/dev/null`; ${ECHO} $${prefix}
MAKE_FLAGS+=	_PERL5_PREFIX="${_PERL5_PREFIX}"
.  endif
.endif

BUILDLINK_FILES.perl=							\
	${PERL5_ARCHLIB:S/^${_PERL5_PREFIX}\///}/CORE/*			\
	${PERL5_ARCHLIB:S/^${_PERL5_PREFIX}\///}/auto/DynaLoader/DynaLoader.a

BUILDLINK_TARGETS+=	perl-buildlink

perl-buildlink: _BUILDLINK_USE

.endif  # PERL5_BUILDLINK2_MK
