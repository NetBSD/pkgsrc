# $NetBSD: Makefile,v 1.45 2022/06/30 11:18:21 nia Exp $

PYTHON_VERSIONS_INCOMPATIBLE=	27

PKGREVISION= 7
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	pluma-${VERSION:R}.2
CATEGORIES=	editors

COMMENT=	Small and lightweight UTF-8 text editor for MATE

USE_TOOLS+=	bash:run perl
TOOL_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2 # for xmllint

PKGCONFIG_OVERRIDE+=	data/pluma.pc.in

REPLACE_PYTHON+=	plugins/externaltools/data/switch-c.tool.in
REPLACE_BASH+=		plugins/externaltools/data/search-recursive.tool.in

post-install:
	find ${DESTDIR}${PREFIX} -type d -name __pycache__ | xargs rm -rf

.include "options.mk"

.include "../../devel/libpeas/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../lang/python/application.mk"
.include "../../x11/mate-desktop/buildlink3.mk"
.include "../../x11/gtksourceview3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
