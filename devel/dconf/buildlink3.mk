# $NetBSD: buildlink3.mk,v 1.7 2012/09/15 10:04:07 obache Exp $

BUILDLINK_TREE+=	dconf

.if !defined(DCONF_BUILDLINK3_MK)
DCONF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dconf+=	dconf>=0.11.0
BUILDLINK_ABI_DEPENDS.dconf?=	dconf>=0.12.1nb1
BUILDLINK_PKGSRCDIR.dconf?=	../../devel/dconf

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.endif	# DCONF_BUILDLINK3_MK

BUILDLINK_TREE+=	-dconf
