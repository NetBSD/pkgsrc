# $NetBSD: buildlink3.mk,v 1.23 2012/09/15 10:06:35 obache Exp $

BUILDLINK_TREE+=	xfce4-thunar

.if !defined(XFCE4_THUNAR_BUILDLINK3_MK)
XFCE4_THUNAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-thunar+=	xfce4-thunar>=1.0.0
BUILDLINK_ABI_DEPENDS.xfce4-thunar+=	xfce4-thunar>=1.0.1nb13
BUILDLINK_PKGSRCDIR.xfce4-thunar?=	../../sysutils/xfce4-thunar

pkgbase := xfce4-thunar
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.xfce4-thunar:Mhal)
.include "../../sysutils/hal/buildlink3.mk"
.endif

.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../x11/xfce4-exo/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/fam.buildlink3.mk"
.endif # XFCE4_THUNAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-thunar
