# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:23:04 jlam Exp $

.if !defined(DRAC_BUILDLINK2_MK)
DRAC_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		drac
BUILDLINK_DEPENDS.drac?=	drac>=1.10
BUILDLINK_PKGSRCDIR.drac?=	../../mail/drac

EVAL_PREFIX+=	BUILDLINK_PREFIX.drac=drac
BUILDLINK_PREFIX.drac_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.drac+=	include/drac.h
BUILDLINK_FILES.drac+=	lib/libdrac.*

BUILDLINK_TARGETS+=	drac-buildlink

drac-buildlink: _BUILDLINK_USE

.endif	# DRAC_BUILDLINK2_MK
