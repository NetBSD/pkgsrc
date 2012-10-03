# $NetBSD: Makefile,v 1.24.2.1 2012/10/03 12:08:58 spz Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/totem/Makefile.common"

DEPENDS+=	gst-plugins0.10-soup-[0-9]*:../../net/gst-plugins0.10-soup

PKGNAME=	${DISTNAME:S/totem/totem-browser-plugin/}
PKGREVISION=	19

# override Makefile.common
PLIST_SRC=      ${.CURDIR}/PLIST
GCONF_SCHEMAS=	# none

COMMENT+=	(gecko plugin)

CONFIGURE_ARGS+=	--enable-browser-plugins

BROWSER_PLUGINS=	cone gmp mully narrowspace

INSTALLATION_DIRS=	lib/netscape/plugins
INSTALLATION_DIRS+=	libexec

do-install:
.for plugin in ${BROWSER_PLUGINS}
	cd ${WRKSRC}/browser-plugin && ${LIBTOOL} --mode=install ${INSTALL_DATA} \
	 libtotem-${plugin}-plugin.la ${DESTDIR}${PREFIX}/lib/netscape/plugins
.endfor
	cd ${WRKSRC}/browser-plugin && ${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
	 totem-plugin-viewer ${DESTDIR}${PREFIX}/libexec

BUILDLINK_API_DEPENDS.shared-mime-info+=	shared-mime-info>=0.22
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-good/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
