# $NetBSD: Makefile,v 1.12 2008/04/29 10:55:02 jmmv Exp $
#

PKGNAME=	libpurple-${PIDGIN_VERSION}
PKGREVISION=	1
COMMENT=	Multi-protocol Instant Messaging client backend

PKG_DESTDIR_SUPPORT=	user-destdir

.include		"../../chat/libpurple/Makefile.common"

CONFIGURE_ENV+=		GCONF_SCHEMA_FILE_DIR=${PREFIX}/share/gconf/schemas/
MAKE_ENV+=		GCONF_SCHEMA_FILE_DIR=${PREFIX}/share/gconf/schemas/

USE_TOOLS+=		msgfmt intltool
## #USE_DIRS+=		xdg-1.2

GCONF_SCHEMAS+=	purple.schemas

PKGCONFIG_OVERRIDE+=	gaim.pc.in
PKGCONFIG_OVERRIDE+=	libpurple/purple.pc.in

CONFIGURE_ARGS+=	--disable-gevolution
CONFIGURE_ARGS+=	--disable-gtkui
CONFIGURE_ARGS+=	--disable-consoleui

.include "options.mk"

BUILD_DIRS=	m4macros libpurple po share/ca-certs share/sounds

## #post-build:
## #	cp ${WRKSRC}/libpurple/gconf/purple.schemas ${WRKSRC}/purple.schemas

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
