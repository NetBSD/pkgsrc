# $NetBSD: Makefile,v 1.11 2018/10/04 19:11:38 leot Exp $
#

DISTNAME=	zathura-djvu-0.2.8
CATEGORIES=	graphics
MASTER_SITES=	https://pwmt.org/projects/zathura-djvu/download/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://pwmt.org/projects/zathura-djvu/
COMMENT=	Add DjVu support to zathura using djvulibre library
LICENSE=	zlib

USE_TOOLS+=	pkg-config

.include "../../devel/py-meson/build.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/djvulibre-lib/buildlink3.mk"
.include "../../print/zathura/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
