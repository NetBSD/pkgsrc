# $NetBSD: Makefile,v 1.48 2022/04/18 19:11:58 adam Exp $

DISTNAME=	zathura-0.4.9
PKGREVISION=	1
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

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
# Needs --desktop and --xml
TOOLS_PLATFORM.msgfmt=
.endif

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/gettext-tools/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
BUILDLINK_ABI_DEPENDS.girara?=	girara>=0.3.7
.include "../../graphics/girara/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
