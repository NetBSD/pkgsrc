# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:29 jlam Exp $

.if !defined(LIBTABE_BUILDLINK2_MK)
LIBTABE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libtabe
BUILDLINK_DEPENDS.libtabe?=	libtabe>=0.2.5
BUILDLINK_PKGSRCDIR.libtabe?=	../../inputmethod/libtabe

EVAL_PREFIX+=			BUILDLINK_PREFIX.libtabe=libtabe
BUILDLINK_PREFIX.libtabe_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libtabe=		include/bims.h
BUILDLINK_FILES.libtabe+=		include/tabe.h
BUILDLINK_FILES.libtabe+=		lib/libbims.*
BUILDLINK_FILES.libtabe+=		lib/libtabe.*

BUILDLINK_TARGETS+=	libtabe-buildlink

libtabe-buildlink: _BUILDLINK_USE

.endif	# LIBTABE_BUILDLINK2_MK
