# $NetBSD: buildlink2.mk,v 1.3 2004/03/29 05:05:41 jlam Exp $

.if !defined(LIBPERL5_BUILDLINK2_MK)
LIBPERL5_BUILDLINK2_MK=  # defined

LIBPERL5_REQD?=			${_PERL5_REQD}
BUILDLINK_PACKAGES+=		libperl
BUILDLINK_PKGBASE.libperl?=	{libperl,perl}
BUILDLINK_DEPENDS.libperl?=	{libperl>=${LIBPERL5_REQD},perl>=5.8.0}
BUILDLINK_PKGSRCDIR.libperl?=	../../lang/libperl

EVAL_PREFIX+=		BUILDLINK_PREFIX.libperl=libperl
BUILDLINK_PREFIX.libperl_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libperl= \
	${PERL5_ARCHLIB:S/^${BUILDLINK_PREFIX.perl}\///}/DynaLoader_pic.o

.include "../../lang/perl5/buildlink2.mk"

BUILDLINK_TARGETS+=	libperl-buildlink

libperl-buildlink: _BUILDLINK_USE

.endif  # LIBPERL5_BUILDLINK2_MK
