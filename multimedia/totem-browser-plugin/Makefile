# $NetBSD: Makefile,v 1.4 2009/08/26 20:22:52 sno Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/totem/Makefile.common"

PKGNAME=	${DISTNAME:S/totem/totem-browser-plugin/}
PKGREVISION=	1

# override Makefile.common
PLIST_SRC=      ${.CURDIR}/PLIST
GCONF_SCHEMAS=	# none

COMMENT+=	(gecko plugin)

CONFIGURE_ARGS+=	--enable-browser-plugins

BROWSER_PLUGINS=	cone gmp mully narrowspace

INSTALLATION_DIRS=	lib/firefox3/plugins
INSTALLATION_DIRS+=	libexec

do-install:
.for plugin in ${BROWSER_PLUGINS}
	cd ${WRKSRC}/browser-plugin && ${LIBTOOL} --mode=install ${INSTALL_DATA} \
	 libtotem-${plugin}-plugin.la ${DESTDIR}${PREFIX}/lib/firefox3/plugins
.endfor
	cd ${WRKSRC}/browser-plugin && ${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
	 totem-plugin-viewer ${DESTDIR}${PREFIX}/libexec

BUILDLINK_API_DEPENDS.shared-mime-info+=	shared-mime-info>=0.22
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-good/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
# not actually needed to build, but firefox3 owns the plugin directory
.include "../../www/firefox3/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
