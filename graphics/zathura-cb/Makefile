# $NetBSD: Makefile,v 1.21 2021/04/12 12:57:14 nia Exp $
#

DISTNAME=	zathura-cb-0.1.8
PKGREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	https://pwmt.org/projects/zathura-cb/download/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://pwmt.org/projects/zathura-cb/
COMMENT=	Adds comic book support to zathura
LICENSE=	zlib

USE_TOOLS+=	pkg-config

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../devel/meson/build.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../print/zathura/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
