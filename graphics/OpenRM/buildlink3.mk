# $NetBSD: buildlink3.mk,v 1.3 2004/02/10 10:07:24 wiz Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
OPENRM_BUILDLINK3_MK:=			${OPENRM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=			OpenRM
.endif

.if !empty(OPENRM_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			OpenRM
BUILDLINK_DEPENDS.OpenRM+=		OpenRM>=1.5.1
BUILDLINK_PKGSRCDIR.OpenRM?=		../../graphics/OpenRM

.  include "../../graphics/jpeg/buildlink3.mk"
.  include "../../graphics/Mesa/buildlink3.mk"
.  include "../../mk/pthread.buildlink3.mk"
.endif # OPENRM_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
