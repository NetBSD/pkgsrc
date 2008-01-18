# $NetBSD: buildlink3.mk,v 1.19 2008/01/18 05:08:36 tnn Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
KOFFICE_BUILDLINK3_MK:=	${KOFFICE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	koffice
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nkoffice}
BUILDLINK_PACKAGES+=	koffice
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}koffice

.if !empty(KOFFICE_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.koffice?=	koffice>=1.4.2nb5
BUILDLINK_ABI_DEPENDS.koffice?=	koffice>=1.6.3nb6
BUILDLINK_PKGSRCDIR.koffice?=	../../misc/koffice
.endif	# KOFFICE_BUILDLINK3_MK

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

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
