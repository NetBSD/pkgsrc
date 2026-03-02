# $NetBSD: Makefile,v 1.41 2026/03/02 13:34:37 yhardy Exp $

DISTNAME=	zathura-djvu-2026.02.03
CATEGORIES=	graphics
MASTER_SITES=	https://pwmt.org/projects/zathura-djvu/download/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://pwmt.org/projects/zathura-djvu/
COMMENT=	Add DjVu support to zathura using djvulibre library
LICENSE=	zlib

USE_TOOLS+=	pkg-config

CFLAGS.SunOS+=	-D__EXTENSIONS__

USE_CC_FEATURES=	c17

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../devel/meson/build.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/djvulibre-lib/buildlink3.mk"
.include "../../print/zathura/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
