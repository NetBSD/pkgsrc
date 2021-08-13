# $NetBSD: Makefile,v 1.5 2021/08/13 12:08:58 nia Exp $

DISTNAME=	drawing-0.8.3
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GITHUB:=maoschanz/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/maoschanz/drawing
COMMENT=	Basic image editor, similar to Microsoft Paint
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	appstream-glib-[0-9]*:../../devel/appstream-glib
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
DEPENDS+=	gtk3+-[0-9]*:../../x11/gtk3

USE_TOOLS+=	pkg-config msgfmt xgettext

.include "../../mk/bsd.prefs.mk"

# XXX: msgfmt: unknown option -- desktop
.if ${OPSYS} == "NetBSD"
TOOLS_PLATFORM.msgfmt=
.endif

# Uses python3 command
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
