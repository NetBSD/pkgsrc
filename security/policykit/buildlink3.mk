# $NetBSD: buildlink3.mk,v 1.9 2020/03/08 16:48:08 wiz Exp $

BUILDLINK_TREE+=	policykit

.if !defined(POLICYKIT_BUILDLINK3_MK)
POLICYKIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.policykit+=	policykit>=0.9
BUILDLINK_ABI_DEPENDS.policykit+=	policykit>=0.9nb23
BUILDLINK_PKGSRCDIR.policykit?=		../../security/policykit

.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.endif # POLICYKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-policykit
