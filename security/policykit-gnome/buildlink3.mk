# $NetBSD: buildlink3.mk,v 1.9 2020/03/08 16:48:08 wiz Exp $

BUILDLINK_TREE+=	policykit-gnome

.if !defined(POLICYKIT_GNOME_BUILDLINK3_MK)
POLICYKIT_GNOME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.policykit-gnome+=	policykit-gnome>=0.9.2
BUILDLINK_ABI_DEPENDS.policykit-gnome+=	policykit-gnome>=0.9.2nb41
BUILDLINK_PKGSRCDIR.policykit-gnome?=	../../security/policykit-gnome

.include "../../security/policykit/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.endif # POLICYKIT_GNOME_BUILDLINK3_MK

BUILDLINK_TREE+=	-policykit-gnome
