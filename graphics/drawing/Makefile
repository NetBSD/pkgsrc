# $NetBSD: Makefile,v 1.1 2020/06/17 08:47:30 nia Exp $

DISTNAME=	drawing-0.4.13
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GITHUB:=maoschanz/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/maoschanz/drawing
COMMENT=	Application for drawing for the GNOME desktop
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	appstream-glib-[0-9]*:../../devel/appstream-glib
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
DEPENDS+=	gtk3+-[0-9]*:../../x11/gtk3

USE_TOOLS+=	pkg-config msgfmt xgettext

# XXX msgfmt: unknown option -- desktop
_TOOLS_USE_PKGSRC.msgfmt=	yes

# Uses python3 command
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
