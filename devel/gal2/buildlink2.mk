# $NetBSD: buildlink2.mk,v 1.6 2003/11/12 01:31:48 salo Exp $
#
# This Makefile fragment is included by packages that use gal2.
#
# This file was created automatically using createbuildlink 2.2.
#

.if !defined(GAL2_BUILDLINK2_MK)
GAL2_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gal2
BUILDLINK_DEPENDS.gal2?=		gal2>=0.0.7nb5
BUILDLINK_PKGSRCDIR.gal2?=		../../devel/gal2

EVAL_PREFIX+=	BUILDLINK_PREFIX.gal2=gal2
BUILDLINK_PREFIX.gal2_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gal2+=	include/gal-2-0/gal/e-paned/*.h
BUILDLINK_FILES.gal2+=	include/gal-2-0/gal/e-table/*.h
BUILDLINK_FILES.gal2+=	include/gal-2-0/gal/e-text/*.h
BUILDLINK_FILES.gal2+=	include/gal-2-0/gal/menus/*.h
BUILDLINK_FILES.gal2+=	include/gal-2-0/gal/shortcut-bar/*.h
BUILDLINK_FILES.gal2+=	include/gal-2-0/gal/util/*.h
BUILDLINK_FILES.gal2+=	include/gal-2-0/gal/widgets/*.h
BUILDLINK_FILES.gal2+=	lib/libgal-2-0.*
BUILDLINK_FILES.gal2+=	lib/pkgconfig/gal-2.0.pc

.include "../../graphics/libgnomecanvas/buildlink2.mk"
.include "../../print/libgnomeprintui/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"

BUILDLINK_TARGETS+=	gal2-buildlink

gal2-buildlink: _BUILDLINK_USE

.endif	# GAL2_BUILDLINK2_MK
