# $NetBSD: buildlink3.mk,v 1.13 2023/11/08 13:20:17 wiz Exp $

BUILDLINK_TREE+=	libbluray

.if !defined(LIBBLURAY_BUILDLINK3_MK)
LIBBLURAY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libbluray+=	libbluray>=0.8.1
BUILDLINK_ABI_DEPENDS.libbluray?=	libbluray>=1.3.4nb3
BUILDLINK_PKGSRCDIR.libbluray?=		../../multimedia/libbluray

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif	# LIBBLURAY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libbluray
