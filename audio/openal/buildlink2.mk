# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/03/17 15:57:05 jmmv Exp $
#
# This Makefile fragment is included by packages that use openal.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(OPENAL_BUILDLINK2_MK)
OPENAL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			openal
BUILDLINK_DEPENDS.openal?=		openal>=20030125
BUILDLINK_PKGSRCDIR.openal?=		../../audio/openal

EVAL_PREFIX+=	BUILDLINK_PREFIX.openal=openal
BUILDLINK_PREFIX.openal_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.openal+=	include/AL/*
BUILDLINK_FILES.openal+=	lib/libopenal.*

BUILDLINK_TARGETS+=	openal-buildlink

openal-buildlink: _BUILDLINK_USE

.endif	# OPENAL_BUILDLINK2_MK
