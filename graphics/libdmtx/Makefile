# $NetBSD: Makefile,v 1.5 2022/04/24 22:07:56 tnn Exp $

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

CHECK_PORTABILITY_SKIP+=	autogen.sh
CHECK_PORTABILITY_SKIP+=	script/check*
CHECK_PORTABILITY_SKIP+=	test/compare_test/*

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

.include "../../mk/bsd.pkg.mk"
