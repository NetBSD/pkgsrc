# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/30 06:24:07 jlam Exp $

.if !defined(SAM_BUILDLINK2_MK)
SAM_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		sam
BUILDLINK_DEPENDS.sam?=		sam>=4.3nb1
BUILDLINK_PKGSRCDIR.sam?=	../../editors/sam

# This adds a build-dependency as sam only has static libraries.
BUILDLINK_DEPMETHOD.sam?=	build

EVAL_PREFIX+=	BUILDLINK_PREFIX.sam=sam
BUILDLINK_PREFIX.sam_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.sam=	include/sam/*
BUILDLINK_FILES.sam+=	lib/libXg.a
BUILDLINK_FILES.sam+=	lib/libframe.a

BUILDLINK_TARGETS+=	sam-buildlink

sam-buildlink: _BUILDLINK_USE

.endif	# SAM_BUILDLINK2_MK
