# $NetBSD: Makefile,v 1.30 2019/10/21 21:55:03 adam Exp $

DISTNAME=	zathura-0.4.3
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	https://pwmt.org/projects/zathura/download/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://pwmt.org/projects/zathura/
COMMENT=	PDF viewer with vi-like keybindings
LICENSE=	zlib

USE_TOOLS+=	pkg-config

# XXX: msgfmt needs to support `--xml', always use the one from pkgsrc
TOOL_DEPENDS+=	gettext-tools>=0.15:../../devel/gettext-tools

PYTHON_VERSIONED_DEPENDENCIES=	sphinx:tool

# Avoid possible dependency on librsvg
MESON_ARGS+=	-D convert-icon=disabled

CFLAGS.SunOS+=	-D__EXTENSIONS__

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/girara/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
