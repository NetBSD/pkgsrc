# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/02/26 18:12:55 minskim Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EVAS_BUILDLINK3_MK:=	${EVAS_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	evas
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nevas}
BUILDLINK_PACKAGES+=	evas
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}evas

.if ${EVAS_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.evas+=	evas>=0.9.9.050
BUILDLINK_PKGSRCDIR.evas?=	../../graphics/evas
.endif	# EVAS_BUILDLINK3_MK

.include "../../devel/eet/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
