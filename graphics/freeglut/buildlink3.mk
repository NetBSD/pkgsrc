# $NetBSD: buildlink3.mk,v 1.8 2008/11/08 01:10:12 obache Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
FREEGLUT_BUILDLINK3_MK:=	${FREEGLUT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	freeglut
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nfreeglut}
BUILDLINK_PACKAGES+=	freeglut
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}freeglut

.if !empty(FREEGLUT_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.freeglut+=	freeglut>=2.2.0
BUILDLINK_ABI_DEPENDS.freeglut+=	freeglut>=2.2.0nb3
BUILDLINK_PKGSRCDIR.freeglut?=	../../graphics/freeglut
.endif	# FREEGLUT_BUILDLINK3_MK

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
