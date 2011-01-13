# $NetBSD: buildlink3.mk,v 1.16 2011/01/13 13:36:06 wiz Exp $

BUILDLINK_TREE+=	gimp-base

.if !defined(GIMP_BASE_BUILDLINK3_MK)
GIMP_BASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gimp-base+=	gimp-base>=1.2.5nb2
BUILDLINK_ABI_DEPENDS.gimp-base+=	gimp-base>=1.2.5nb11
BUILDLINK_PKGSRCDIR.gimp-base?=	../../graphics/gimp1-base

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../multimedia/mpeg-lib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.endif # GIMP_BASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-gimp-base
