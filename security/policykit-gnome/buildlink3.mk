# $NetBSD: buildlink3.mk,v 1.11 2021/12/08 16:02:35 adam Exp $

BUILDLINK_TREE+=	policykit-gnome

.if !defined(POLICYKIT_GNOME_BUILDLINK3_MK)
POLICYKIT_GNOME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.policykit-gnome+=	policykit-gnome>=0.9.2
BUILDLINK_ABI_DEPENDS.policykit-gnome+=	policykit-gnome>=0.9.2nb46
BUILDLINK_PKGSRCDIR.policykit-gnome?=	../../security/policykit-gnome

.include "../../security/policykit/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.endif # POLICYKIT_GNOME_BUILDLINK3_MK

BUILDLINK_TREE+=	-policykit-gnome
