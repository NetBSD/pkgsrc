# $NetBSD: Makefile,v 1.3 2025/10/05 19:26:15 js Exp $

DISTNAME=	libcupsfilters-2.1.1
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenPrinting/}
GITHUB_PROJECT=	libcupsfilters
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/OpenPrinting/libcupsfilters
COMMENT=	Library for cups-filters
LICENSE=	apache-2.0 # with gnu-gpl-v2 and gnu-lgpl-v2 exception

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libcupsfilters.pc.in

.include "options.mk"

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../print/ghostscript/buildlink3.mk"
.include "../../print/libcups/buildlink3.mk"
.include "../../print/mupdf/buildlink3.mk"
.include "../../print/poppler-cpp/buildlink3.mk"
.include "../../print/qpdf/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
