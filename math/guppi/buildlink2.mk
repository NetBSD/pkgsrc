# $NetBSD: buildlink2.mk,v 1.5 2003/11/12 01:31:50 salo Exp $

.if !defined(GUPPI_BUILDLINK2_MK)
GUPPI_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		guppi
BUILDLINK_DEPENDS.guppi?=	guppi>=0.40.3nb6
BUILDLINK_PKGSRCDIR.guppi?=	../../math/guppi

EVAL_PREFIX+=	BUILDLINK_PREFIX.guppi=guppi
BUILDLINK_PREFIX.guppi_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.guppi=	include/gnome-1.0/libguppi/*
BUILDLINK_FILES.guppi+=	include/gnome-1.0/libguppitank/*
BUILDLINK_FILES.guppi+=	lib/libguppi.*
BUILDLINK_FILES.guppi+=	lib/libguppitank.*

.include "../../devel/libglade/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../x11/gnome-core/buildlink2.mk"

BUILDLINK_TARGETS+=	guppi-buildlink

guppi-buildlink: _BUILDLINK_USE

.endif	# GUPPI_BUILDLINK2_MK
