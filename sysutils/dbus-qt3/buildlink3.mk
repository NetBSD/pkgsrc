# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/04/21 14:31:18 drochner Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
DBUS_QT3_BUILDLINK3_MK:=	${DBUS_QT3_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	dbus-qt3
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ndbus-qt3}
BUILDLINK_PACKAGES+=	dbus-qt3
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}dbus-qt3

.if ${DBUS_QT3_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.dbus-qt3+=	dbus-qt3>=0.70
BUILDLINK_PKGSRCDIR.dbus-qt3?=	../../sysutils/dbus-qt3
.endif	# DBUS_QT3_BUILDLINK3_MK

.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
