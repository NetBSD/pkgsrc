# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/11/22 15:20:51 jmcneill Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
HAL_BUILDLINK3_MK:=	${HAL_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	hal
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nhal}
BUILDLINK_PACKAGES+=	hal
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}hal

.if ${HAL_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.hal+=	hal>=0.5.11
BUILDLINK_PKGSRCDIR.hal?=	../../sysutils/hal
.endif	# HAL_BUILDLINK3_MK

.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
