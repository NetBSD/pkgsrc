# $NetBSD: buildlink3.mk,v 1.11 2006/07/10 21:12:03 adam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
WINE_BUILDLINK3_MK:=	${WINE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	wine
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nwine}
BUILDLINK_PACKAGES+=	wine

BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}wine

.if !empty(WINE_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.wine+=	wine>=0.9.6nb1
BUILDLINK_PKGSRCDIR.wine?=	../../emulators/wine
.endif	# WINE_BUILDLINK3_MK

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
