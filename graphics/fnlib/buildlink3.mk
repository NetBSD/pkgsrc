# $NetBSD: buildlink3.mk,v 1.1 2004/03/10 13:26:08 xtraeme Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
FNLIB_BUILDLINK3_MK:=	${FNLIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	fnlib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nfnlib}
BUILDLINK_PACKAGES+=	fnlib

.if !empty(FNLIB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.fnlib+=	fnlib>=0.5nb6
BUILDLINK_PKGSRCDIR.fnlib?=	../../graphics/fnlib

.include "../../graphics/imlib/buildlink3.mk"

.endif	# FNLIB_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
