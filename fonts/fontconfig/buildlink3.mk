# $NetBSD: buildlink3.mk,v 1.18 2005/04/21 17:40:19 kristerw Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
FONTCONFIG_BUILDLINK3_MK:=	${FONTCONFIG_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	fontconfig
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nfontconfig}
BUILDLINK_PACKAGES+=	fontconfig

.if !empty(FONTCONFIG_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.fontconfig+=		fontconfig>=1.0.1
BUILDLINK_RECOMMENDED.fontconfig+=	fontconfig>=2.2.96nb1
BUILDLINK_PKGSRCDIR.fontconfig?=	../../fonts/fontconfig
.endif	# FONTCONFIG_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
