# $NetBSD: Makefile,v 1.58 2014/01/30 22:12:05 wiz Exp $

COMMENT=		Multi-protocol Instant Messaging client GTK frontend

PYTHON_VERSIONS_INCOMPATIBLE=	33 # not yet ported as of 2.10.7

.include		"../../chat/libpurple/Makefile.common"

PKGREVISION=		5
USE_TOOLS+=		msgfmt intltool

PKGCONFIG_OVERRIDE+=	gaim.pc.in
PKGCONFIG_OVERRIDE+=	libpurple/purple.pc.in
PKGCONFIG_OVERRIDE+=	pidgin/pidgin.pc.in

CONFIGURE_ARGS+=	--enable-gtkui

BUILD_DIRS=		pidgin
INSTALLATION_DIRS=	share/applications

# includes "Arguments to configure" as string
CHECK_WRKREF_SKIP=	bin/pidgin

.include "options.mk"

pre-build:
	# XXX Find a cleaner way.
	${TEST} -r ${WRKSRC}/libpurple/libpurple.la || \
	  ln -s ${BUILDLINK_DIR}/lib/libpurple.la ${WRKSRC}/libpurple/.
	cd ${WRKSRC} && ${BUILD_MAKE_CMD} pidgin.desktop

INSTALL_DIRS=		pidgin doc

post-install:
	${INSTALL_DATA} ${WRKSRC}/pidgin.desktop \
	  ${DESTDIR}${PREFIX}/share/applications

.include "../../chat/libpurple/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
