# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/04/25 15:49:30 kefren Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
NDESK_DBUS_GLIB_BUILDLINK3_MK:=	${NDESK_DBUS_GLIB_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	ndesk-dbus-glib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nndesk-dbus-glib}
BUILDLINK_PACKAGES+=	ndesk-dbus-glib
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}ndesk-dbus-glib

.if ${NDESK_DBUS_GLIB_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.ndesk-dbus-glib+=	ndesk-dbus-glib>=0.4.1
BUILDLINK_PKGSRCDIR.ndesk-dbus-glib?=	../../sysutils/ndesk-dbus-glib
.endif	# NDESK_DBUS_GLIB_BUILDLINK3_MK

.include "../../lang/mono/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
