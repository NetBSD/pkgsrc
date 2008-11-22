# $NetBSD: buildlink3.mk,v 1.1 2008/11/22 21:21:48 jmcneill Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
POLICYKIT_GNOME_BUILDLINK3_MK:=	${POLICYKIT_GNOME_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	policykit-gnome
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npolicykit-gnome}
BUILDLINK_PACKAGES+=	policykit-gnome
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}policykit-gnome

.if ${POLICYKIT_GNOME_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.policykit-gnome+=	policykit-gnome>=0.9.2
BUILDLINK_PKGSRCDIR.policykit-gnome?=	../../security/policykit-gnome
.endif	# POLICYKIT_GNOME_BUILDLINK3_MK

.include "../../security/policykit/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
