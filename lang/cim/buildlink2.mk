# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:23:01 jlam Exp $

.if !defined(CIM_BUILDLINK2_MK)
CIM_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		cim
BUILDLINK_DEPENDS.cim?=		cim>=3.30
BUILDLINK_PKGSRCDIR.cim?=	../../lang/cim

EVAL_PREFIX+=			BUILDLINK_PREFIX.cim=cim
BUILDLINK_PREFIX.cim_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.cim=		include/cim.h
BUILDLINK_FILES.cim+=		lib/libcim-atr.*
BUILDLINK_FILES.cim+=		lib/libcim.*

BUILDLINK_TARGETS+=	cim-buildlink

cim-buildlink: _BUILDLINK_USE

.endif	# CIM_BUILDLINK2_MK
