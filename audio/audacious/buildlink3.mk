# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:23:52 joerg Exp $

BUILDLINK_TREE+=	audacious

.if !defined(AUDACIOUS_BUILDLINK3_MK)
AUDACIOUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.audacious+=	audacious>=1.5.0
BUILDLINK_PKGSRCDIR.audacious?=	../../audio/audacious
BUILDLINK_DEPMETHOD.audacious?=	build

PRINT_PLIST_AWK+=       /^@dirrm share\/audacious\/images$$/ \
                                { print "@comment in audacious: " $$0; next; }
PRINT_PLIST_AWK+=       /^@dirrm share\/audacious$$/ \
                                { print "@comment in audacious: " $$0; next; }

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
