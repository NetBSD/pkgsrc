# $NetBSD: Makefile,v 1.2 2016/08/03 10:22:57 adam Exp $
#

DISTNAME=	zathura-djvu-0.2.5
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://pwmt.org/projects/zathura-djvu/download/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	http://pwmt.org/projects/zathura-djvu/
COMMENT=	Add DjVu support to zathura using djvulibre library
LICENSE=	zlib

USE_TOOLS+=	pkg-config gmake
USE_LIBTOOL=	yes

.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/djvulibre-lib/buildlink3.mk"
.include "../../print/zathura/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
