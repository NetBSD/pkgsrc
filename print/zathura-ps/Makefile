# $NetBSD: Makefile,v 1.19 2019/07/21 22:25:39 wiz Exp $

DISTNAME=	zathura-ps-0.2.6
PKGREVISION=	5
CATEGORIES=	print
MASTER_SITES=	https://pwmt.org/projects/zathura-ps/download/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://pwmt.org/projects/zathura-ps/
COMMENT=	Add PS support to zathura using libspectre library
LICENSE=	zlib

USE_TOOLS+=	pkg-config

.include "../../devel/py-meson/build.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../print/libspectre/buildlink3.mk"
.include "../../print/zathura/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
