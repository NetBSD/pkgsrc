# $NetBSD: buildlink3.mk,v 1.20 2009/03/20 19:25:00 joerg Exp $

BUILDLINK_TREE+=	koffice

.if !defined(KOFFICE_BUILDLINK3_MK)
KOFFICE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.koffice?=	koffice>=1.4.2nb5
BUILDLINK_ABI_DEPENDS.koffice?=	koffice>=1.6.3nb6
BUILDLINK_PKGSRCDIR.koffice?=	../../misc/koffice

.include "../../converters/wv2/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.endif # KOFFICE_BUILDLINK3_MK

BUILDLINK_TREE+=	-koffice
