# $NetBSD: buildlink2.mk,v 1.3 2002/10/30 04:13:54 rh Exp $

.if !defined(LIBGNOMECANVAS_BUILDLINK2_MK)
LIBGNOMECANVAS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libgnomecanvas
BUILDLINK_DEPENDS.libgnomecanvas?=	libgnomecanvas>2.0.4
BUILDLINK_PKGSRCDIR.libgnomecanvas?=	../../graphics/libgnomecanvas

EVAL_PREFIX+=	BUILDLINK_PREFIX.libgnomecanvas=libgnomecanvas
BUILDLINK_PREFIX.libgnomecanvas_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libgnomecanvas=		include/libgnomecanvas-2.0/libgnomecanvas/*
BUILDLINK_FILES.libgnomecanvas+=	lib/libglade/2.0/libcanvas.*
BUILDLINK_FILES.libgnomecanvas+=	lib/libgnomecanvas-2.*

BUILDLINK_TARGETS+=	libgnomecanvas-buildlink

libgnomecanvas-buildlink: _BUILDLINK_USE

.endif	# LIBGNOMECANVAS_BUILDLINK2_MK
