# $NetBSD: buildlink3.mk,v 1.4 2012/03/03 00:12:21 wiz Exp $
#

BUILDLINK_TREE+=	ibus

.if !defined(IBUS_BUILDLINK3_MK)
IBUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ibus+=	ibus>=1.2.0.20091024
BUILDLINK_ABI_DEPENDS.ibus+=	ibus>=1.3.9nb5
BUILDLINK_PKGSRCDIR.ibus?=	../../inputmethod/ibus

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif	# IBUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ibus
