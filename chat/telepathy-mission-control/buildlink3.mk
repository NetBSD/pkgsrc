# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/11/14 22:59:03 wiz Exp $

BUILDLINK_DEPTH:=				${BUILDLINK_DEPTH}+
TELEPATHY_MISSION_CONTROL_BUILDLINK3_MK:=	${TELEPATHY_MISSION_CONTROL_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	telepathy-mission-control
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ntelepathy-mission-control}
BUILDLINK_PACKAGES+=	telepathy-mission-control
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}telepathy-mission-control

.if ${TELEPATHY_MISSION_CONTROL_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.telepathy-mission-control+=	telepathy-mission-control>=4.67
BUILDLINK_PKGSRCDIR.telepathy-mission-control?=	../../chat/telepathy-mission-control
.endif	# TELEPATHY_MISSION_CONTROL_BUILDLINK3_MK

.include "../../chat/libtelepathy/buildlink3.mk"
.include "../../chat/telepathy-glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"

BUILDLINK_DEPTH:=				${BUILDLINK_DEPTH:S/+$//}
