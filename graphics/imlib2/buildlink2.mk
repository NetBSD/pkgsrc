# $NetBSD: buildlink2.mk,v 1.6 2003/12/04 19:37:52 xtraeme Exp $

.if !defined(IMLIB2_BUILDLINK2_MK)
IMLIB2_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		imlib2
BUILDLINK_DEPENDS.imlib2?=	imlib2>=1.1.0
BUILDLINK_PKGSRCDIR.imlib2?=	../../graphics/imlib2

EVAL_PREFIX+=		BUILDLINK_PREFIX.imlib2=imlib2
BUILDLINK_PREFIX.imlib2_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.imlib2=		bin/imlib2-config
BUILDLINK_FILES.imlib2+=	include/Imlib2.h
BUILDLINK_FILES.imlib2+=	lib/libImlib2.*
BUILDLINK_FILES.imlib2+=	lib/loaders/filter/*
BUILDLINK_FILES.imlib2+=	lib/loaders/image/*

.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/libungif/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"

BUILDLINK_TARGETS+=	imlib2-buildlink

imlib2-buildlink: _BUILDLINK_USE

.endif	# IMLIB2_BUILDLINK2_MK
