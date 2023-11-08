# $NetBSD: buildlink3.mk,v 1.62 2023/11/08 13:18:03 wiz Exp $

BUILDLINK_TREE+=	audacious

.if !defined(AUDACIOUS_BUILDLINK3_MK)
AUDACIOUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.audacious+=	audacious>=3.10.1
BUILDLINK_ABI_DEPENDS.audacious+=	audacious>=4.1nb12
BUILDLINK_PKGSRCDIR.audacious?=		../../audio/audacious

.include "../../mk/bsd.fast.prefs.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

pkgbase := audacious
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.audacious:Mdbus)
.include "../../sysutils/dbus/buildlink3.mk"
.endif

.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif # AUDACIOUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-audacious
