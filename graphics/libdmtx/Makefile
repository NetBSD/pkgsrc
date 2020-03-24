# $NetBSD: Makefile,v 1.4 2020/03/24 14:52:30 nia Exp $

DISTNAME=	libdmtx-0.7.5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=dmtx/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dmtx/libdmtx
COMMENT=	Software for reading and writing Data Matrix 2D barcodes
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_LANGUAGES=	c99
USE_TOOLS+=	autoreconf autoconf automake

PKGCONFIG_OVERRIDE+=	libdmtx.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

.include "../../mk/bsd.pkg.mk"
