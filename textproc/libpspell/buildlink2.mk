# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 18:40:07 jlam Exp $

.if !defined(LIBPSPELL_BUILDLINK2_MK)
LIBPSPELL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libpspell
BUILDLINK_DEPENDS.libpspell?=	libpspell>=0.12.2nb1
BUILDLINK_PKGSRCDIR.libpspell?=	../../textproc/libpspell

EVAL_PREFIX+=			BUILDLINK_PREFIX.libpspell=libpspell
BUILDLINK_PREFIX.libpspell_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libpspell=		include/pspell/*
BUILDLINK_FILES.libpspell+=		lib/libpspell*

BUILDLINK_TARGETS+=	libpspell-buildlink

libpspell-buildlink: _BUILDLINK_USE

.endif	# LIBPSPELL_BUILDLINK2_MK
