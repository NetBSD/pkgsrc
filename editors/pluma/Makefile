# $NetBSD: Makefile,v 1.50 2023/01/29 21:15:56 ryoon Exp $

PYTHON_VERSIONS_INCOMPATIBLE=	27

PKGREVISION= 2
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	pluma-${VERSION}
CATEGORIES=	editors

COMMENT=	Small and lightweight UTF-8 text editor for MATE

USE_TOOLS+=	bash:run perl
TOOL_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2 # for xmllint

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
.include "../../mk/bsd.pkg.mk"
