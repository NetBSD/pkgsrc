# $NetBSD: buildlink3.mk,v 1.2 2004/10/03 00:14:41 tv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
WINE_BUILDLINK3_MK:=	${WINE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	wine
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nwine}
BUILDLINK_PACKAGES+=	wine

.if !empty(WINE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.wine+=	wine>=20040309
BUILDLINK_RECOMMENDED.wine+=	wine>=20040505nb1
BUILDLINK_PKGSRCDIR.wine?=	../../emulators/wine
.endif	# WINE_BUILDLINK3_MK

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
