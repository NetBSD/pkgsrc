# $NetBSD: Makefile,v 1.11 2018/11/12 03:52:43 ryoon Exp $

PKGREVISION= 1
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-user-share-${VERSION}
CATEGORIES=	net

COMMENT=	MATE user-leve file shareing

DEPENDS+=	${APACHE_PKG_PREFIX}-dnssd>=0.6:../../www/ap22-dnssd
TOOL_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool
TOOL_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2 # for xmllint

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
CONFIGURE_ARGS+=	--with-httpd=${BUILDLINK_PREFIX.apache}/sbin/httpd
CONFIGURE_ARGS+=	--with-modules-path=${BUILDLINK_PREFIX.apache}/lib/httpd

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/${PKGBASE}

MAKE_DIRS+=	${PKG_SYSCONFBASEDIR}/xdg/autostart
CONF_FILES+=	${PREFIX}/share/examples/${PKGBASE}/xdg/autostart/mate-user-share-obexftp.desktop \
		${PKG_SYSCONFBASEDIR}/xdg/autostart/mate-user-share-obexftp.desktop
CONF_FILES+=	${PREFIX}/share/examples/${PKGBASE}/xdg/autostart/mate-user-share-obexpush.desktop \
		${PKG_SYSCONFBASEDIR}/xdg/autostart/mate-user-share-obexpush.desktop
CONF_FILES+=	${PREFIX}/share/examples/${PKGBASE}/xdg/autostart/mate-user-share-webdav.desktop \
		${PKG_SYSCONFBASEDIR}/xdg/autostart/mate-user-share-webdav.desktop

.include "../../devel/glib2/schemas.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../sysutils/caja/buildlink3.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
