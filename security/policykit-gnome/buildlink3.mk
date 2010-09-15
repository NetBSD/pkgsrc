# $NetBSD: buildlink3.mk,v 1.4 2010/09/15 19:44:53 drochner Exp $

BUILDLINK_TREE+=	policykit-gnome

.if !defined(POLICYKIT_GNOME_BUILDLINK3_MK)
POLICYKIT_GNOME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.policykit-gnome+=	policykit-gnome>=0.9.2
BUILDLINK_ABI_DEPENDS.policykit-gnome+=	policykit-gnome>=0.9.2nb3
BUILDLINK_PKGSRCDIR.policykit-gnome?=	../../security/policykit-gnome

.include "../../security/policykit/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.endif # POLICYKIT_GNOME_BUILDLINK3_MK

BUILDLINK_TREE+=	-policykit-gnome
