# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/11/22 03:33:38 jmcneill Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
POLICYKIT_BUILDLINK3_MK:=	${POLICYKIT_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	policykit
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npolicykit}
BUILDLINK_PACKAGES+=	policykit
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}policykit

.if ${POLICYKIT_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.policykit+=	policykit>=0.9
BUILDLINK_PKGSRCDIR.policykit?=	../../security/policykit
.endif	# POLICYKIT_BUILDLINK3_MK

.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
