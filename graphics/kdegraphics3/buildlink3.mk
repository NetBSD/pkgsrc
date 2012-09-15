# $NetBSD: buildlink3.mk,v 1.33 2012/09/15 10:04:59 obache Exp $

BUILDLINK_TREE+=	kdegraphics

.if !defined(KDEGRAPHICS_BUILDLINK3_MK)
KDEGRAPHICS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdegraphics+=	kdegraphics>=3.5.0nb2
BUILDLINK_ABI_DEPENDS.kdegraphics+=	kdegraphics>=3.5.10nb23
BUILDLINK_PKGSRCDIR.kdegraphics?=	../../graphics/kdegraphics3

.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.endif # KDEGRAPHICS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdegraphics
