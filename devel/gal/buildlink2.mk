# $NetBSD: buildlink2.mk,v 1.3 2002/09/10 16:06:38 wiz Exp $

.if !defined(GAL_BUILDLINK2_MK)
GAL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		gal
BUILDLINK_DEPENDS.gal?=		gal>=0.19.3nb1
BUILDLINK_PKGSRCDIR.gal?=	../../devel/gal

EVAL_PREFIX+=			BUILDLINK_PREFIX.gal=gal
BUILDLINK_PREFIX.gal_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.gal+=		include/gal/*
BUILDLINK_FILES.gal+=		include/gal/*/*
BUILDLINK_FILES.gal+=		lib/libgal.*

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/bonobo/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libglade/buildlink2.mk"
.include "../../print/gnome-print/buildlink2.mk"
.include "../../sysutils/gnome-vfs/buildlink2.mk"

BUILDLINK_TARGETS+=		gal-buildlink

gal-buildlink: _BUILDLINK_USE

.endif	# GAL_BUILDLINK2_MK
