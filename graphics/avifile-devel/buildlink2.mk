# $NetBSD: buildlink2.mk,v 1.3 2002/08/28 05:29:41 jlam Exp $

.if !defined(AVIFILE_BUILDLINK2_MK)
AVIFILE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		avifile
BUILDLINK_DEPENDS.avifile?=	avifile>=0.6
BUILDLINK_PKGSRCDIR.avifile?=	../../graphics/avifile-devel

EVAL_PREFIX+=			BUILDLINK_PREFIX.avifile=avifile
BUILDLINK_PREFIX.avifile_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.avifile=	lib/libaviplay.*
BUILDLINK_FILES.avifile+=	lib/avifile-0.6/*
BUILDLINK_FILES.avifile+=	include/avifile/*
BUILDLINK_FILES.avifile+=	include/avifile/wine/*

BUILDLINK_TARGETS+=	avifile-buildlink

avifile-buildlink: _BUILDLINK_USE

.endif	# AVIFILE_BUILDLINK2_MK
