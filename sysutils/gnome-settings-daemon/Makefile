# $NetBSD: Makefile,v 1.109 2024/05/16 06:15:33 wiz Exp $

DISTNAME=	gnome-settings-daemon-3.38.1
PKGREVISION=	32
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/${PKGBASE}/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/GNOME/gnome-settings-daemon
COMMENT=	GNOME settings daemon
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

TOOL_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

USE_TOOLS+=	pkg-config msgfmt xgettext perl
USE_TOOLS+=	gdbus-codegen

CONFLICTS+=	gnome-control-center<2.22.0

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/gnome-settings-daemon-3.0

MESON_ARGS+=		-Dgudev=false
MESON_ARGS+=		-Drfkill=false
MESON_ARGS+=		-Dnetwork_manager=false
MESON_ARGS+=		-Dsystemd=false
MESON_ARGS+=		-Dwayland=false
MESON_ARGS+=		-Dsmartcard=false
MESON_ARGS+=		-Dwwan=false

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/gnome-settings-daemon.pc

CONF_FILES+=	${PREFIX}/share/examples/xdg/Xwayland-session.d/00-xrdb \
		${PKG_SYSCONFDIR}/xdg/Xwayland-session.d/00-xrdb
CONF_FILES+=	${PREFIX}/share/examples/xdg/autostart/org.gnome.SettingsDaemon.A11ySettings.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/org.gnome.SettingsDaemon.A11ySettings.desktop
CONF_FILES+=	${PREFIX}/share/examples/xdg/autostart/org.gnome.SettingsDaemon.Color.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/org.gnome.SettingsDaemon.Color.desktop
CONF_FILES+=	${PREFIX}/share/examples/xdg/autostart/org.gnome.SettingsDaemon.Datetime.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/org.gnome.SettingsDaemon.Datetime.desktop
CONF_FILES+=	${PREFIX}/share/examples/xdg/autostart/org.gnome.SettingsDaemon.Housekeeping.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/org.gnome.SettingsDaemon.Housekeeping.desktop
CONF_FILES+=	${PREFIX}/share/examples/xdg/autostart/org.gnome.SettingsDaemon.Keyboard.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/org.gnome.SettingsDaemon.Keyboard.desktop
CONF_FILES+=	${PREFIX}/share/examples/xdg/autostart/org.gnome.SettingsDaemon.MediaKeys.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/org.gnome.SettingsDaemon.MediaKeys.desktop
CONF_FILES+=	${PREFIX}/share/examples/xdg/autostart/org.gnome.SettingsDaemon.Power.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/org.gnome.SettingsDaemon.Power.desktop
CONF_FILES+=	${PREFIX}/share/examples/xdg/autostart/org.gnome.SettingsDaemon.PrintNotifications.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/org.gnome.SettingsDaemon.PrintNotifications.desktop
CONF_FILES+=	${PREFIX}/share/examples/xdg/autostart/org.gnome.SettingsDaemon.Rfkill.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/org.gnome.SettingsDaemon.Rfkill.desktop
CONF_FILES+=	${PREFIX}/share/examples/xdg/autostart/org.gnome.SettingsDaemon.ScreensaverProxy.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/org.gnome.SettingsDaemon.ScreensaverProxy.desktop
CONF_FILES+=	${PREFIX}/share/examples/xdg/autostart/org.gnome.SettingsDaemon.Sharing.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/org.gnome.SettingsDaemon.Sharing.desktop
CONF_FILES+=	${PREFIX}/share/examples/xdg/autostart/org.gnome.SettingsDaemon.Smartcard.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/org.gnome.SettingsDaemon.Smartcard.desktop
CONF_FILES+=	${PREFIX}/share/examples/xdg/autostart/org.gnome.SettingsDaemon.Sound.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/org.gnome.SettingsDaemon.Sound.desktop
CONF_FILES+=	${PREFIX}/share/examples/xdg/autostart/org.gnome.SettingsDaemon.UsbProtection.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/org.gnome.SettingsDaemon.UsbProtection.desktop
CONF_FILES+=	${PREFIX}/share/examples/xdg/autostart/org.gnome.SettingsDaemon.Wacom.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/org.gnome.SettingsDaemon.Wacom.desktop
CONF_FILES+=	${PREFIX}/share/examples/xdg/autostart/org.gnome.SettingsDaemon.Wwan.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/org.gnome.SettingsDaemon.Wwan.desktop
CONF_FILES+=	${PREFIX}/share/examples/xdg/autostart/org.gnome.SettingsDaemon.XSettings.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/org.gnome.SettingsDaemon.XSettings.desktop

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} != "Linux"
MESON_ARGS+=		-Dalsa=false
.else
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../devel/dconf/buildlink3.mk"
.include "../../devel/libgweather/buildlink3.mk"
.include "../../geography/geoclue/buildlink3.mk"
.include "../../geography/geocode-glib/buildlink3.mk"
.include "../../graphics/colord/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus-glib+=	dbus-glib>=0.74
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../print/libcups/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
BUILDLINK_API_DEPENDS.gsettings-desktop-schemas+=	gsettings-desktop-schemas>=3.15.4
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../security/polkit/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/upower/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../x11/gnome-desktop3/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
