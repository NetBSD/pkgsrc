# $NetBSD: buildlink2.mk,v 1.10 2003/12/04 19:33:38 xtraeme Exp $

.if !defined(LIBXML2_BUILDLINK2_MK)
LIBXML2_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libxml2
BUILDLINK_DEPENDS.libxml2?=	libxml2>=2.6.2
BUILDLINK_PKGSRCDIR.libxml2?=	../../textproc/libxml2

EVAL_PREFIX+=	BUILDLINK_PREFIX.libxml2=libxml2
BUILDLINK_PREFIX.libxml2_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libxml2=	include/libxml2/libxml/*
BUILDLINK_FILES.libxml2+=	lib/libxml2.*

.include "../../devel/zlib/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"

BUILDLINK_TARGETS+=	libxml2-buildlink

libxml2-buildlink: _BUILDLINK_USE

.endif	# LIBXML2_BUILDLINK2_MK
