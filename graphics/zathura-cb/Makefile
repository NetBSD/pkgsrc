# $NetBSD: Makefile,v 1.36 2024/12/27 08:20:04 wiz Exp $
#

DISTNAME=	zathura-cb-0.1.10
PKGREVISION=	3
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
