# $NetBSD: buildlink2.mk,v 1.4 2004/04/08 16:35:21 reed Exp $

.if !defined(EXPAT_BUILDLINK2_MK)
EXPAT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		expat
BUILDLINK_DEPENDS.expat?=	expat>=1.95.7
BUILDLINK_PKGSRCDIR.expat?=	../../textproc/expat

EVAL_PREFIX+=	BUILDLINK_PREFIX.expat=expat
BUILDLINK_PREFIX.expat_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.expat=		include/expat.h
BUILDLINK_FILES.expat+=		lib/libexpat.*

BUILDLINK_TARGETS+=	expat-buildlink

expat-buildlink: _BUILDLINK_USE

.endif	# EXPAT_BUILDLINK2_MK
