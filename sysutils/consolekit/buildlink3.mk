# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/11/22 03:32:22 jmcneill Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
CONSOLEKIT_BUILDLINK3_MK:=	${CONSOLEKIT_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	consolekit
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nconsolekit}
BUILDLINK_PACKAGES+=	consolekit
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}consolekit

.if ${CONSOLEKIT_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.consolekit+=	consolekit>=0.3.0
BUILDLINK_PKGSRCDIR.consolekit?=	../../sysutils/consolekit
.endif	# CONSOLEKIT_BUILDLINK3_MK

.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
