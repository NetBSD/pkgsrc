# $NetBSD: buildlink2.mk,v 1.1 2003/03/02 09:04:03 jtb Exp $

.if !defined(NTL_BUILDLINK2_MK)
NTL_BUILDLINK2_MK=		# defined

BUILDLINK_PACKAGES+=		ntl
BUILDLINK_DEPENDS.ntl?=		ntl>=5.3.1
BUILDLINK_PKGSRCDIR.ntl?=	../../math/ntl

EVAL_PREFIX+=			BUILDLINK_PREFIX.ntl=ntl
BUILDLINK_PREFIX.ntl_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.ntl=		include/NTL/*
BUILDLINK_FILES.ntl+=		lib/libntl.*

BUILDLINK_TARGETS+=	ntl-buildlink

ntl-buildlink: _BUILDLINK_USE

.endif	# NTL_BUILDLINK2_MK
