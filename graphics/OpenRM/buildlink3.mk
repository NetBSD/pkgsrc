# $NetBSD: buildlink3.mk,v 1.11 2006/07/08 23:10:50 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
OPENRM_BUILDLINK3_MK:=	${OPENRM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	OpenRM
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NOpenRM}
BUILDLINK_PACKAGES+=	OpenRM
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}OpenRM

.if !empty(OPENRM_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.OpenRM+=	OpenRM>=1.5.1
BUILDLINK_ABI_DEPENDS.OpenRM?=	OpenRM>=1.5.2nb3
BUILDLINK_PKGSRCDIR.OpenRM?=	../../graphics/OpenRM
.endif	# OPENRM_BUILDLINK3_MK

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
