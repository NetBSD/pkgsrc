# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/09/12 13:22:05 jmcneill Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
OPAL_BUILDLINK3_MK:=	${OPAL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	opal
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nopal}
BUILDLINK_PACKAGES+=	opal
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}opal

.if !empty(OPAL_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.opal+=	opal>=3.3.0
BUILDLINK_ABI_DEPENDS.opal?=	opal>=3.3.0
BUILDLINK_PKGSRCDIR.opal?=	../../devel/opal-devel
.endif	# OPAL_BUILDLINK3_MK

.include "../../devel/ptlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
