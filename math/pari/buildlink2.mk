# $NetBSD: buildlink2.mk,v 1.3 2004/03/26 02:27:45 wiz Exp $

.if !defined(PARI_BUILDLINK2_MK)
PARI_BUILDLINK2_MK=		# defined

BUILDLINK_PACKAGES+=		pari
BUILDLINK_DEPENDS.pari?=	pari>=2.1.5nb1
BUILDLINK_RECOMMENDED.pari?=	pari>=2.1.5nb3
BUILDLINK_PKGSRCDIR.pari?=	../../math/pari
BUILDLINK_DEPMETHOD.pari?=	build

EVAL_PREFIX+=			BUILDLINK_PREFIX.pari=pari
BUILDLINK_PREFIX.pari_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.pari=		include/pari/*
BUILDLINK_FILES.pari+=		lib/libpari.*

BUILDLINK_TARGETS+=		pari-buildlink

pari-buildlink: _BUILDLINK_USE

.endif # PARI_BUILDLINK2_MK
