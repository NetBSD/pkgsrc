# $NetBSD: buildlink3.mk,v 1.35 2018/03/31 04:30:33 schmonz Exp $

BUILDLINK_TREE+=	fontconfig

.if !defined(FONTCONFIG_BUILDLINK3_MK)
FONTCONFIG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fontconfig+=	fontconfig>=2.10.93
BUILDLINK_ABI_DEPENDS.fontconfig+=	fontconfig>=2.13.0
BUILDLINK_PKGSRCDIR.fontconfig?=	../../fonts/fontconfig

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.endif # FONTCONFIG_BUILDLINK3_MK

BUILDLINK_TREE+=	-fontconfig
