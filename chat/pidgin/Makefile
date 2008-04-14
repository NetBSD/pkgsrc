# $NetBSD: Makefile,v 1.9 2008/04/14 05:45:23 tnn Exp $
#

PKGNAME=		pidgin-${PIDGIN_VERSION}
COMMENT=		Multi-protocol Instant Messaging client GTK frontend
PKGREVISION=		1

PKG_DESTDIR_SUPPORT=	user-destdir

.include		"../../chat/libpurple/Makefile.common"

USE_DIRS+=		xdg-1.4
USE_TOOLS+=		msgfmt intltool

PKGCONFIG_OVERRIDE+=	gaim.pc.in
PKGCONFIG_OVERRIDE+=	libpurple/purple.pc.in
PKGCONFIG_OVERRIDE+=	pidgin/pidgin.pc.in

CONFIGURE_ARGS+=	--disable-gevolution
CONFIGURE_ARGS+=	--enable-gtkui
CONFIGURE_ARGS+=	--disable-consoleui

BUILD_DIRS=		pidgin

# includes "Arguments to configure" as string
CHECK_WRKREF_SKIP=	bin/pidgin

.include "options.mk"

pre-build:
	# XXX Find a cleaner way.
	${TEST} -r ${WRKSRC}/libpurple/libpurple.la || \
	  ln -s ${BUILDLINK_DIR}/lib/libpurple.la ${WRKSRC}/libpurple/.
	cd ${WRKSRC} && ${BUILD_MAKE_CMD} pidgin.desktop

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/pidgin.desktop \
	  ${DESTDIR}${PREFIX}/share/applications

# XXX install pidgin.1 via doc/Makefile

.include "../../chat/libpurple/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
