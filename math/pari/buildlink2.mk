# $NetBSD: buildlink2.mk,v 1.1 2003/07/07 21:57:50 jtb Exp $

.if !defined(PARI_BUILDLINK2_MK)
PARI_BUILDLINK2_MK=		# defined

BUILDLINK_PACKAGES+=		pari
BUILDLINK_DEPENDS.pari?=	pari>=2.1.5
BUILDLINK_PKGSRCDIR.pari?=	../../math/pari
BUILDLINK_DEPMETHOD.pari?=	build

EVAL_PREFIX+=			BUILDLINK_PREFIX.pari=pari
BUILDLINK_PREFIX.pari_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.pari=		include/pari/*
BUILDLINK_FILES.pari+=		lib/libpari.*

BUILDLINK_TARGETS+=		pari-buildlink

pari-buildlink: _BUILDLINK_USE

.endif # PARI_BUILDLINK2_MK
