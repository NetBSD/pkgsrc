# $NetBSD: Makefile,v 1.11 2021/08/10 11:40:40 nia Exp $

DISTNAME=	imv-4.3.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=eXeC64/}
GITHUB_PROJECT=	imv
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/eXeC64/imv
COMMENT=	Image viewer for X11/Wayland
LICENSE=	mit

TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

USE_TOOLS+=	pkg-config bash:run
USE_LANGUAGES=	c99

REPLACE_BASH+=	contrib/imv-folder

# alphasort
CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

MESON_ARGS+=	-Dlibtiff=enabled
MESON_ARGS+=	-Dlibpng=enabled

CONF_FILES+=	${PREFIX}/share/examples/imv/imv_config \
		${PKG_SYSCONFDIR}/imv_config

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	src/imv.c
SUBST_VARS.paths=	PKG_SYSCONFDIR

PYTHON_FOR_BUILD_ONLY=	tool

.include "options.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freeimage/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/inih/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
