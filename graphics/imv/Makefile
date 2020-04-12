# $NetBSD: Makefile,v 1.4 2020/04/12 08:28:49 adam Exp $

DISTNAME=	imv-4.1.0
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=eXeC64/}
GITHUB_PROJECT=	imv
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/eXeC64/imv
COMMENT=	Image viewer for X11/Wayland
LICENSE=	mit

TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c99

MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}

MAKE_FLAGS+=	BACKEND_LIBTIFF="yes"
MAKE_FLAGS+=	BACKEND_LIBPNG="yes"

.include "options.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freeimage/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
