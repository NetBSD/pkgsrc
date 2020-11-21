# $NetBSD: Makefile,v 1.48 2020/11/21 09:34:58 wiz Exp $

DISTNAME=	zathura-pdf-poppler-0.3.0
PKGREVISION=	3
CATEGORIES=	print
MASTER_SITES=	https://pwmt.org/projects/zathura-pdf-poppler/download/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	degroote@NetBSD.org
HOMEPAGE=	https://pwmt.org/projects/zathura-pdf-poppler/
COMMENT=	Add PDF support to zathura using poppler rendering engine
LICENSE=	zlib

USE_TOOLS+=	pkg-config

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../devel/meson/build.mk"
.include "../../graphics/girara/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../print/zathura/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
