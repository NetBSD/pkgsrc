# $NetBSD: buildlink3.mk,v 1.2 2004/01/24 03:26:46 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
FONTCONFIG_BUILDLINK3_MK:=	${FONTCONFIG_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	fontconfig
.endif

.if !empty(FONTCONFIG_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			fontconfig
BUILDLINK_DEPENDS.fontconfig+=		fontconfig>=2.1nb1
BUILDLINK_PKGSRCDIR.fontconfig?=	../../fonts/fontconfig

BUILDLINK_DEPENDS.freetype2+=	freetype2>=2.0.9

.  include "../../devel/zlib/buildlink3.mk"
.  include "../../graphics/freetype2/buildlink3.mk"
.  include "../../textproc/expat/buildlink3.mk"
.endif # FONTCONFIG_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
