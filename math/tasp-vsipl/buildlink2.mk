# $NetBSD: buildlink2.mk,v 1.1 2003/07/10 12:43:09 jtb Exp $

.if !defined(TASP_VSIPL_BUILDLINK2_MK)
TASP_VSIPL_BUILDLINK2_MK=              # defined

BUILDLINK_PACKAGES+=			tasp-vsipl
BUILDLINK_DEPENDS.tasp-vsipl?=		tasp-vsipl>=20030710
BUILDLINK_PKGSRCDIR.tasp-vsipl?=	../../math/tasp-vsipl
BUILDLINK_DEPMETHOD.tasp-vsipl?=	build

EVAL_PREFIX+=				BUILDLINK_PREFIX.tasp-vsipl=tasp-vsipl
BUILDLINK_PREFIX.tasp-vsipl_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.tasp-vsipl=		include/VU.h
BUILDLINK_FILES.tasp-vsipl+=		include/VUX.h
BUILDLINK_FILES.tasp-vsipl+=		include/vsipl.h
BUILDLINK_FILES.tasp-vsipl+=		lib/libVU.*
BUILDLINK_FILES.tasp-vsipl+=		lib/libVUX.*
BUILDLINK_FILES.tasp-vsipl+=		lib/libvsip.*

BUILDLINK_TARGETS+=			tasp-vsipl-buildlink

tasp-vsipl-buildlink: _BUILDLINK_USE

.endif # TASP_VSIPL_BUILDLINK2_MK
