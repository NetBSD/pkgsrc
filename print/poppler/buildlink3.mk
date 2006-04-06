# $NetBSD: buildlink3.mk,v 1.7 2006/04/06 06:22:36 reed Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
POPPLER_BUILDLINK3_MK:=	${POPPLER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	poppler
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npoppler}
BUILDLINK_PACKAGES+=	poppler

.if !empty(POPPLER_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.poppler+=	poppler>=0.5.1
BUILDLINK_PKGSRCDIR.poppler?=	../../print/poppler
.endif	# POPPLER_BUILDLINK3_MK

.include "../../fonts/fontconfig/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
