# $NetBSD: Makefile,v 1.15 2022/08/11 05:08:42 gutteridge Exp $

DISTNAME=	v4.3.1
DIST_SUBDIR=	imv
PKGNAME=	imv-${DISTNAME:S/^v//g}
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	https://git.sr.ht/~exec64/imv/archive/

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://sr.ht/~exec64/imv/
COMMENT=	Image viewer for X11/Wayland
LICENSE=	mit

TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

WRKSRC=		${WRKDIR}/imv-${DISTNAME}

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
