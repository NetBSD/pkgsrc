# $NetBSD: Makefile,v 1.17 2018/11/16 23:01:48 nia Exp $

# XXX: meta-pkgs/mate/Makefile.common includes pyversion.mk which sets the
# python version too early and clashes with PYTHON_VERSIONS_INCOMPATIBLE
# from libpeas bl3, so we include it early to ensure a valid version is
# chosen.  This is not ideal, please fix it properly at some point.
.include "../../devel/libpeas/buildlink3.mk"
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	pluma-${VERSION:R}.1
CATEGORIES=	editors
PKGREVISION=	3

COMMENT=	Small and lightweight UTF-8 text editor for MATE

USE_TOOLS+=	bash:run
TOOL_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool
TOOL_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2 # for xmllint

PKGCONFIG_OVERRIDE+=	data/pluma.pc.in

CONFIGURE_ARGS+=	--disable-updater # only for OS X and Windows

REPLACE_PYTHON+=	plugins/externaltools/data/switch-c.tool.in
REPLACE_BASH+=		plugins/externaltools/data/search-recursive.tool.in

.include "options.mk"

.include "../../devel/glib2/schemas.mk"
.include "../../lang/python/application.mk"
.include "../../x11/mate-desktop/buildlink3.mk"
.include "../../x11/gtksourceview3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
