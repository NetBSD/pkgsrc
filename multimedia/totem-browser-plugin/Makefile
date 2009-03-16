# $NetBSD: Makefile,v 1.2 2009/03/16 12:13:31 jmcneill Exp $
#

.include "../../multimedia/totem/Makefile.common"

PKGNAME=	${DISTNAME:S/totem/totem-browser-plugin/}
# override Makefile.common
PLIST_SRC=      ${.CURDIR}/PLIST
GCONF_SCHEMAS=	# none

COMMENT+=	(gecko plugin)

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--enable-browser-plugins

BROWSER_PLUGINS=	cone gmp mully narrowspace

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
