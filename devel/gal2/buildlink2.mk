# $NetBSD: buildlink2.mk,v 1.8 2003/12/13 00:45:22 wiz Exp $
#

.if !defined(GAL2_BUILDLINK2_MK)
GAL2_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gal2
BUILDLINK_DEPENDS.gal2?=		gal2>=1.99.10nb1
BUILDLINK_PKGSRCDIR.gal2?=		../../devel/gal2

EVAL_PREFIX+=	BUILDLINK_PREFIX.gal2=gal2
BUILDLINK_PREFIX.gal2_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gal2+=	include/gal-2.0/gal/a11y/e-table/*.h
BUILDLINK_FILES.gal2+=	include/gal-2.0/gal/a11y/e-text/*.h
BUILDLINK_FILES.gal2+=	include/gal-2.0/gal/a11y/*.h
BUILDLINK_FILES.gal2+=	include/gal-2.0/gal/e-table/*.h
BUILDLINK_FILES.gal2+=	include/gal-2.0/gal/e-text/*.h
BUILDLINK_FILES.gal2+=	include/gal-2.0/gal/menus/*.h
BUILDLINK_FILES.gal2+=	include/gal-2.0/gal/shortcut-bar/*.h
BUILDLINK_FILES.gal2+=	include/gal-2.0/gal/util/*.h
BUILDLINK_FILES.gal2+=	include/gal-2.0/gal/widgets/*.h
BUILDLINK_FILES.gal2+=	lib/libgal-2.0.*
BUILDLINK_FILES.gal2+=	lib/libgal-a11y-2.0.*

.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../print/libgnomeprintui/buildlink2.mk"

BUILDLINK_TARGETS+=	gal2-buildlink

gal2-buildlink: _BUILDLINK_USE

.endif	# GAL2_BUILDLINK2_MK
