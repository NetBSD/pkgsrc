# $NetBSD: Makefile,v 1.1.1.1 2007/07/28 12:10:43 gdt Exp $
#

PKGNAME=	libpurple-${VERSION}

COMMENT=	Multi-protocol Instant Messaging client backend

PKG_DESTDIR_SUPPORT=	user-destdir

.include		"../../wip/libpurple/Makefile.common"

# for the pidgin intltool, see TODO
DEPENDS+=		p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser

CONFIGURE_ENV+=		GCONF_SCHEMA_FILE_DIR=${PREFIX}/share/gconf/schemas/
MAKE_ENV+=		GCONF_SCHEMA_FILE_DIR=${PREFIX}/share/gconf/schemas/

USE_TOOLS+=		msgfmt
## #USE_DIRS+=		xdg-1.2

GCONF2_SCHEMAS+=	purple.schemas

PKGCONFIG_OVERRIDE+=	gaim.pc.in
PKGCONFIG_OVERRIDE+=	libpurple/purple.pc.in

CONFIGURE_ARGS+=	--disable-gevolution
CONFIGURE_ARGS+=	--disable-gtkui
CONFIGURE_ARGS+=	--disable-consoleui

.include "options.mk"

## #post-build:
## #	cp ${WRKSRC}/libpurple/gconf/purple.schemas ${WRKSRC}/purple.schemas

# XXX Use textproc/intltool instead of included intltool.
# XXX On NetBSD 3.0: iconv: iconv_open(UTF-8, tis-620): Invalid argument

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
