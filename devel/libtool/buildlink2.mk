# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 18:38:34 jlam Exp $

.if !defined(LTDL_BUILDLINK2_MK)
LTDL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		ltdl
BUILDLINK_DEPENDS.ltdl?=	libtool-base>=${LIBTOOL_REQD}
BUILDLINK_PKGSRCDIR.ltdl?=	../../devel/libtool-base

EVAL_PREFIX+=	BUILDLINK_PREFIX.ltdl=libtool-base
BUILDLINK_PREFIX.ltdl_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.ltdl=	include/ltdl.h
BUILDLINK_FILES.ltdl+=	lib/libltdl.*

BUILDLINK_TARGETS+=	ltdl-buildlink

ltdl-buildlink: _BUILDLINK_USE

.endif	# LTDL_BUILDLINK2_MK
