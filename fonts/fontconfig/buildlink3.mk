# $NetBSD: buildlink3.mk,v 1.16 2004/03/18 09:12:11 jlam Exp $

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
.endif	# FONTCONFIG_BUILDLINK3_MK

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
