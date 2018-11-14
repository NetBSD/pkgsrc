# $NetBSD: buildlink3.mk,v 1.39 2018/11/14 22:20:59 kleink Exp $

BUILDLINK_TREE+=	audacious

.if !defined(AUDACIOUS_BUILDLINK3_MK)
AUDACIOUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.audacious+=	audacious>=3.5.1
BUILDLINK_ABI_DEPENDS.audacious+=	audacious>=3.5.2nb10
BUILDLINK_PKGSRCDIR.audacious?=		../../audio/audacious

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif # AUDACIOUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-audacious
