# $NetBSD: buildlink3.mk,v 1.2 2004/03/18 09:12:11 jlam Exp $

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
.endif	# FNLIB_BUILDLINK3_MK

.include "../../graphics/imlib/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
