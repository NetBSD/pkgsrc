# $NetBSD: buildlink3.mk,v 1.2 2004/02/01 10:09:26 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GLE_BUILDLINK3_MK:=	${GLE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gle
.endif

.if !empty(GLE_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		gle
BUILDLINK_DEPENDS.gle+=		gle>=3.0.3
BUILDLINK_PKGSRCDIR.gle?=	../../graphics/gle

.  include "../../graphics/Mesa/buildlink3.mk"
.endif # GLE_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
