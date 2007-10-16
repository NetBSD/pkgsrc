# $NetBSD: buildlink3.mk,v 1.25 2007/10/16 18:12:56 reed Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
FONTCONFIG_BUILDLINK3_MK:=	${FONTCONFIG_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	fontconfig
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nfontconfig}
BUILDLINK_PACKAGES+=	fontconfig
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}fontconfig

.if !empty(FONTCONFIG_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.fontconfig+=	fontconfig>=2.4.2
BUILDLINK_PKGSRCDIR.fontconfig?=	../../fonts/fontconfig
.endif	# FONTCONFIG_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
