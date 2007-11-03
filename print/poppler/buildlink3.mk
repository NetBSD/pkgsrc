# $NetBSD: buildlink3.mk,v 1.11 2007/11/03 16:10:38 drochner Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
POPPLER_BUILDLINK3_MK:=	${POPPLER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	poppler
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npoppler}
BUILDLINK_PACKAGES+=	poppler
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}poppler

.if !empty(POPPLER_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.poppler+=	poppler>=0.5.1
BUILDLINK_PKGSRCDIR.poppler?=	../../print/poppler
.endif	# POPPLER_BUILDLINK3_MK

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
