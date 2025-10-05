# $NetBSD: Makefile,v 1.3 2025/10/05 19:26:15 js Exp $

DISTNAME=	libppd-2.1.1
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenPrinting/}
GITHUB_PROJECT=	libppd
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/OpenPrinting/libppd
COMMENT=	Library for CUPS 2.x PPD files
LICENSE=	apache-2.0 # with gnu-gpl-v2 and gnu-lgpl-v2 exception

DEPENDS+=	poppler-utils-[0-9]*:../../print/poppler-utils

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libppd.pc.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../print/ghostscript/buildlink3.mk"
.include "../../print/libcupsfilters/buildlink3.mk"
.include "../../print/mupdf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
