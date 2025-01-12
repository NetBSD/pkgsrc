# $NetBSD: options.mk,v 1.2 2025/01/12 19:20:26 riastradh Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.at-spi2-core

#
# Make dbus optional. Note that turning dbus off does not actually
# make at-spi2 work without dbus; it tells it to build only atk, and
# makes this package approximately equivalent to the standalone atk
# package that used to exist. This in turn avoids incurring a
# mandatory dbus dependency for a large number of applications that
# never previously had one.
#
# However, anything that actually needs at-spi2 will not work with
# dbus turned off, and probably not build either.
#
PKG_SUPPORTED_OPTIONS=	dbus introspection
PKG_SUGGESTED_OPTIONS=	dbus ${${USE_CROSS_COMPILE:tl} == "yes":?:introspection}

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	dbus
PLIST_VARS+=	introspection

.if !empty(PKG_OPTIONS:Mdbus)
PLIST.dbus=	yes

#
# These files only get installed when dbus is in use.
#
MAKE_DIRS+=	${PKG_SYSCONFDIR}/at-spi2
CONF_FILES=	${EGDIR}/at-spi2/accessibility.conf \
		${PKG_SYSCONFDIR}/at-spi2/accessibility.conf
CONF_FILES+=	${EGDIR}/xdg/autostart/at-spi-dbus-bus.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/at-spi-dbus-bus.desktop
post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}/xdg/autostart
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/xdg/autostart/at-spi-dbus-bus.desktop \
	      ${DESTDIR}${EGDIR}/xdg/autostart/at-spi-dbus-bus.desktop

.include "../../sysutils/dbus/buildlink3.mk"

.else
MESON_ARGS+=	-Datk_only=true
.endif

.if ${PKG_OPTIONS:Mintrospection}
PLIST.introspection=	yes
BUILDLINK_DEPMETHOD.gobject-introspection=	build
.  include "../../devel/gobject-introspection/buildlink3.mk"
.endif

.include "../../mk/bsd.prefs.mk"
