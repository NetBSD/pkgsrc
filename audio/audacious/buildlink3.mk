# $NetBSD: buildlink3.mk,v 1.14 2012/03/03 00:12:00 wiz Exp $

BUILDLINK_TREE+=	audacious

.if !defined(AUDACIOUS_BUILDLINK3_MK)
AUDACIOUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.audacious+=	audacious>=1.5.0
BUILDLINK_ABI_DEPENDS.audacious?=	audacious>=1.5.1nb9
BUILDLINK_PKGSRCDIR.audacious?=	../../audio/audacious
BUILDLINK_DEPMETHOD.audacious?=	build

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libmcs/buildlink3.mk"
.include "../../devel/libmowgli/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.endif # AUDACIOUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-audacious
