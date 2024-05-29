# $NetBSD: Makefile,v 1.15 2024/05/29 16:32:51 adam Exp $

DISTNAME=	dmtx-utils-0.7.6
PKGREVISION=	12
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=dmtx/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dmtx/dmtx-utils
COMMENT=	Command line programs for reading and writing Data Matrix 2D barcodes
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	autoconf automake pkg-config

pre-configure:
	cd ${WRKSRC} && ${TOOLS_PATH.autoreconf} --force --install

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../graphics/libdmtx/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
