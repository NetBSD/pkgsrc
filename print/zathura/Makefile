# $NetBSD: Makefile,v 1.43 2021/08/14 07:36:55 nia Exp $

DISTNAME=	zathura-0.4.8
CATEGORIES=	print
MASTER_SITES=	https://pwmt.org/projects/zathura/download/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://pwmt.org/projects/zathura/
COMMENT=	PDF viewer with vi-like keybindings
LICENSE=	zlib

USE_TOOLS+=	pkg-config

PYTHON_VERSIONED_DEPENDENCIES=	sphinx:tool

# Avoid possible dependency on librsvg
MESON_ARGS+=	-D convert-icon=disabled

CFLAGS.SunOS+=	-D__EXTENSIONS__

SUBST_CLASSES+=		py
SUBST_STAGE.py=		pre-configure
SUBST_MESSAGE.py=	Setting Python version variables.
SUBST_FILES.py+=	doc/meson.build
SUBST_VARS.py+=		PYVERSSUFFIX

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../graphics/cairo/buildlink3.mk"
BUILDLINK_ABI_DEPENDS.girara?=	girara>=0.3.6
.include "../../graphics/girara/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
