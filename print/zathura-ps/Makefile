# $NetBSD: Makefile,v 1.26 2021/12/08 16:06:16 adam Exp $

DISTNAME=	zathura-ps-0.2.7
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	https://pwmt.org/projects/zathura-ps/download/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://pwmt.org/projects/zathura-ps/
COMMENT=	Add PS support to zathura using libspectre library
LICENSE=	zlib

USE_TOOLS+=	pkg-config

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../devel/meson/build.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../print/libspectre/buildlink3.mk"
.include "../../print/zathura/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
