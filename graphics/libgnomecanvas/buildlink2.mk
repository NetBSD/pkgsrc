# $NetBSD: buildlink2.mk,v 1.11 2004/04/01 18:22:52 jmmv Exp $

.if !defined(LIBGNOMECANVAS_BUILDLINK2_MK)
LIBGNOMECANVAS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libgnomecanvas
BUILDLINK_DEPENDS.libgnomecanvas?=	libgnomecanvas>=2.5.91
BUILDLINK_PKGSRCDIR.libgnomecanvas?=	../../graphics/libgnomecanvas

EVAL_PREFIX+=	BUILDLINK_PREFIX.libgnomecanvas=libgnomecanvas
BUILDLINK_PREFIX.libgnomecanvas_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libgnomecanvas=		include/libgnomecanvas-2.0/libgnomecanvas/*
BUILDLINK_FILES.libgnomecanvas+=	lib/libglade/2.0/libcanvas.*
BUILDLINK_FILES.libgnomecanvas+=	lib/libgnomecanvas-2.*

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../graphics/libart2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

BUILDLINK_TARGETS+=	libgnomecanvas-buildlink

libgnomecanvas-buildlink: _BUILDLINK_USE

.endif	# LIBGNOMECANVAS_BUILDLINK2_MK
