# $NetBSD: buildlink3.mk,v 1.15 2004/03/10 17:57:14 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
FONTCONFIG_BUILDLINK3_MK:=	${FONTCONFIG_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	fontconfig
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nfontconfig}
BUILDLINK_PACKAGES+=	fontconfig

.if !empty(FONTCONFIG_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.fontconfig+=		fontconfig>=1.0.1
BUILDLINK_PKGSRCDIR.fontconfig?=	../../fonts/fontconfig

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"

.endif	# FONTCONFIG_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
