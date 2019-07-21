# $NetBSD: buildlink3.mk,v 1.41 2019/07/21 22:23:57 wiz Exp $

BUILDLINK_TREE+=	audacious

.if !defined(AUDACIOUS_BUILDLINK3_MK)
AUDACIOUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.audacious+=	audacious>=3.10.1
BUILDLINK_ABI_DEPENDS.audacious+=	audacious>=3.10.1nb1
BUILDLINK_PKGSRCDIR.audacious?=		../../audio/audacious

.include "../../mk/bsd.fast.prefs.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"

pkgbase := audacious
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.audacious:Mdbus)
.include "../../sysutils/dbus/buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.audacious:Mgtk2)
.include "../../x11/gtk2/buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.audacious:Mqt5)
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif
.endif # AUDACIOUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-audacious
