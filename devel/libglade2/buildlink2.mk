# $NetBSD: buildlink2.mk,v 1.10 2004/04/01 18:16:46 jmmv Exp $

.if !defined(LIBGLADE2_BUILDLINK2_MK)
LIBGLADE2_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libglade2
BUILDLINK_DEPENDS.libglade2?=	libglade2>=2.3.6
BUILDLINK_PKGSRCDIR.libglade2?=	../../devel/libglade2

EVAL_PREFIX+=			BUILDLINK_PREFIX.libglade2=libglade2
BUILDLINK_PREFIX.libglade2_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libglade2=	include/libglade-2.0/glade/*
BUILDLINK_FILES.libglade2+=	lib/libglade-2.0.*

.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

BUILDLINK_TARGETS+=		libglade2-buildlink

libglade2-buildlink: _BUILDLINK_USE

.endif	# LIBGLADE2_BUILDLINK2_MK
