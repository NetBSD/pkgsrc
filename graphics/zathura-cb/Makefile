# $NetBSD: Makefile,v 1.12 2018/04/16 14:34:42 wiz Exp $
#

DISTNAME=	zathura-cb-0.1.7
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	https://pwmt.org/projects/zathura-cb/download/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://pwmt.org/projects/zathura-cb/
COMMENT=	Adds comic book support to zathura
LICENSE=	zlib

USE_TOOLS+=	pkg-config gmake
USE_LIBTOOL=	yes

MAKE_FLAGS+=	LIBARCHIVE_INC="-I${BUILDLINK_PREFIX.libarchive}/include"
MAKE_FLAGS+=	LIBARCHIVE_LIB="-L${BUILDLINK_PREFIX.libarchive}/lib -larchive"

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../print/zathura/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
