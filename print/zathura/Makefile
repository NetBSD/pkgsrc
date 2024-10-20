# $NetBSD: Makefile,v 1.68 2024/10/20 14:04:29 wiz Exp $

DISTNAME=	zathura-0.5.8
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	https://pwmt.org/projects/zathura/download/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://pwmt.org/projects/zathura/
COMMENT=	PDF viewer with vi-like keybindings
LICENSE=	zlib

TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

USE_TOOLS+=	pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	39 # py-sphinx

# Avoid possible dependency on librsvg
MESON_ARGS+=	-D convert-icon=disabled

CFLAGS.SunOS+=	-D__EXTENSIONS__

USE_CC_FEATURES+=	c17

SUBST_CLASSES+=		py
SUBST_STAGE.py=		pre-configure
SUBST_MESSAGE.py=	Setting Python version variables.
SUBST_FILES.py+=	doc/meson.build
SUBST_VARS.py+=		PYVERSSUFFIX

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
# Needs --desktop and --xml
TOOLS_PLATFORM.msgfmt=
.elif ${OPSYS} == "Darwin"
.include "../../x11/gtk-mac-integration/buildlink3.mk"
.endif

USE_BUILTIN.file=	no # pkgconfig files are needed

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/gettext-tools/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
BUILDLINK_API_DEPENDS.girara+=	girara>=0.4.3
.include "../../graphics/girara/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
