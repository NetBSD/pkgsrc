# $NetBSD: Makefile,v 1.7 2017/05/29 11:09:46 jperkin Exp $
#

DISTNAME=	zathura-cb-0.1.6
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://pwmt.org/projects/zathura-cb/download/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	http://pwmt.org/projects/zathura-cb/
COMMENT=	Adds comic book support to zathura
LICENSE=	zlib

USE_TOOLS+=	pkg-config gmake
USE_LIBTOOL=	yes

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../print/zathura/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
