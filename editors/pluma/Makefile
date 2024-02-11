# $NetBSD: Makefile,v 1.58 2024/02/11 18:20:27 triaxx Exp $

PYTHON_VERSIONS_INCOMPATIBLE=	27

PKGREVISION= 6
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	pluma-${VERSION:R}.1
CATEGORIES=	editors

COMMENT=	Small and lightweight UTF-8 text editor for MATE

USE_TOOLS+=	bash:run perl

PKGCONFIG_OVERRIDE+=	data/pluma.pc.in

REPLACE_PYTHON+=	plugins/externaltools/data/switch-c.tool.in
REPLACE_BASH+=		plugins/externaltools/data/search-recursive.tool.in
REPLACE_SH+=		data/pluma-bugreport.sh.in \
			plugins/externaltools/data/build.tool.in \
			plugins/externaltools/data/open-terminal-here.tool.in \
			plugins/externaltools/data/remove-trailing-spaces.tool.in \
			plugins/externaltools/data/run-command.tool.in

post-install:
	find ${DESTDIR}${PREFIX} -type d -name __pycache__ | xargs rm -rf

.include "options.mk"

.include "../../devel/libpeas/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../lang/python/application.mk"
.include "../../x11/mate-desktop/buildlink3.mk"
.include "../../x11/gtksourceview4/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
