# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:03:53 jlam Exp $

.if !defined(CDPARANOIA_BUILDLINK2_MK)
CDPARANOIA_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			cdparanoia
BUILDLINK_DEPENDS.cdparanoia?=		cdparanoia>=3.0
BUILDLINK_PKGSRCDIR.cdparanoia?=	../../audio/cdparanoia

EVAL_PREFIX+=	BUILDLINK_PREFIX.cdparanoia=cdparanoia
BUILDLINK_PREFIX.cdparanoia_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.cdparanoia=	include/cdparanoia/*
BUILDLINK_FILES.cdparanoia+=	lib/libcdda_paranoia.*
BUILDLINK_FILES.cdparanoia+=	lib/libcdda_interface.*

BUILDLINK_TARGETS+=	cdparanoia-buildlink

cdparanoia-buildlink: _BUILDLINK_USE

.endif	# CDPARANOIA_BUILDLINK2_MK
