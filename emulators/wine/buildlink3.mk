# $NetBSD: buildlink3.mk,v 1.12 2007/01/10 09:09:49 adam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
WINE_BUILDLINK3_MK:=	${WINE_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	wine
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nwine}
BUILDLINK_PACKAGES+=	wine
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}wine

.if ${WINE_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.wine+=	wine>=0.9.6nb1
BUILDLINK_PKGSRCDIR.wine?=	../../emulators/wine
.endif	# WINE_BUILDLINK3_MK

.include "../../graphics/freetype2/buildlink3.mk"
.if !empty(PKG_BUILD_OPTIONS.wine:Mopengl)
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.endif
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
