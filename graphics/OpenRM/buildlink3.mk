# $NetBSD: buildlink3.mk,v 1.4 2004/03/05 19:25:12 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
OPENRM_BUILDLINK3_MK:=	${OPENRM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	OpenRM
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NOpenRM}
BUILDLINK_PACKAGES+=	OpenRM

.if !empty(OPENRM_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.OpenRM+=	OpenRM>=1.5.1
BUILDLINK_PKGSRCDIR.OpenRM?=	../../graphics/OpenRM

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"

.endif	# OPENRM_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
