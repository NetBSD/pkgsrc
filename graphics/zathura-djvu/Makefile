# $NetBSD: Makefile,v 1.1 2016/02/14 13:59:12 leot Exp $
#

DISTNAME=	zathura-djvu-0.2.5
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
