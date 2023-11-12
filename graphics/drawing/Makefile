# $NetBSD: Makefile,v 1.11 2023/11/12 13:34:34 wiz Exp $

DISTNAME=	drawing-1.0.2
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GITHUB:=maoschanz/}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/maoschanz/drawing
COMMENT=	Basic image editor, similar to Microsoft Paint
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	appstream-glib-[0-9]*:../../devel/appstream-glib
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
DEPENDS+=	gtk3+-[0-9]*:../../x11/gtk3

USE_TOOLS+=	pkg-config msgfmt xgettext itstool

# Uses python3 command
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../devel/meson/build.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
