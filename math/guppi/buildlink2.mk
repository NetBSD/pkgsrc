# $NetBSD: buildlink2.mk,v 1.7 2004/01/06 18:52:33 jmmv Exp $

.if !defined(GUPPI_BUILDLINK2_MK)
GUPPI_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		guppi
BUILDLINK_DEPENDS.guppi?=	guppi>=0.40.3nb8
BUILDLINK_PKGSRCDIR.guppi?=	../../math/guppi

EVAL_PREFIX+=	BUILDLINK_PREFIX.guppi=guppi
BUILDLINK_PREFIX.guppi_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.guppi=	include/gnome-1.0/libguppi/*
BUILDLINK_FILES.guppi+=	include/gnome-1.0/libguppitank/*
BUILDLINK_FILES.guppi+=	lib/libguppi.*
BUILDLINK_FILES.guppi+=	lib/libguppitank.*

.include "../../devel/bonobo/buildlink2.mk"
.include "../../devel/gal/buildlink2.mk"
.include "../../devel/libglade/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../lang/guile14/buildlink2.mk"
.include "../../print/gnome-print/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"

BUILDLINK_TARGETS+=	guppi-buildlink

guppi-buildlink: _BUILDLINK_USE

.endif	# GUPPI_BUILDLINK2_MK
