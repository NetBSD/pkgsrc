# $NetBSD: buildlink3.mk,v 1.1 2004/04/12 09:17:00 xtraeme Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PSICONV_BUILDLINK3_MK:=	${PSICONV_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	psiconv
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npsiconv}
BUILDLINK_PACKAGES+=	psiconv

.if !empty(PSICONV_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.psiconv+=	psiconv>=0.8.3nb1
BUILDLINK_PKGSRCDIR.psiconv?=	../../converters/psiconv
.endif	# PSICONV_BUILDLINK3_MK

.include "../../graphics/ImageMagick/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
