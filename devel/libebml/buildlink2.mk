# $NetBSD: buildlink2.mk,v 1.1.1.1 2004/01/18 20:14:59 kristerw Exp $

.if !defined(LIBEBML_BUILDLINK2_MK)
LIBEBML_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libebml
BUILDLINK_DEPENDS.libebml?=	libebml>=0.6.3
BUILDLINK_PKGSRCDIR.libebml?=	../../devel/libebml

EVAL_PREFIX+=	BUILDLINK_PREFIX.libebml=libebml
BUILDLINK_PREFIX.libebml_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libebml +=	include/ebml/*
BUILDLINK_FILES.libebml +=	include/ebml/c/*
BUILDLINK_FILES.libebml +=	lib/libebml.*

BUILDLINK_TARGETS+=	libebml-buildlink

libebml-buildlink: _BUILDLINK_USE

.endif	# LIBEBML_BUILDLINK2_MK
