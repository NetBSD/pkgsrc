# $NetBSD: Makefile,v 1.68 2024/01/17 23:57:51 gdt Exp $

DISTNAME=	zathura-pdf-mupdf-0.3.9
PKGREVISION=	14
CATEGORIES=	print
MASTER_SITES=	https://pwmt.org/projects/zathura-pdf-mupdf/download/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://pwmt.org/projects/zathura-pdf-mupdf/
COMMENT=	Add PDF support to zathura using mupdf rendering engine
LICENSE=	zlib

USE_TOOLS+=	pkg-config

CPPFLAGS+=	-D_XOPEN_SOURCE=600

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../devel/meson/build.mk"
.include "../../graphics/cairo/buildlink3.mk"
BUILDLINK_API_DEPENDS.mupdf+=	mupdf>=1.16.0
.include "../../print/mupdf/buildlink3.mk"
.include "../../print/zathura/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
