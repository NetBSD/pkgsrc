# $NetBSD: buildlink3.mk,v 1.2 2004/02/09 23:56:32 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
OPENRM_DEVEL_BUILDLINK3_MK:=	${OPENRM_DEVEL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	openrm-devel
.endif

.if !empty(OPENRM_DEVEL_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			openrm-devel
BUILDLINK_DEPENDS.openrm-devel+=	openrm-devel>=1.5.1
BUILDLINK_PKGSRCDIR.openrm-devel?=	../../graphics/OpenRM

.  include "../../graphics/jpeg/buildlink3.mk"
.  include "../../graphics/Mesa/buildlink3.mk"
.  include "../../mk/pthread.buildlink3.mk"
.endif # OPENRM_DEVEL_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
