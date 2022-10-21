# $NetBSD: Makefile,v 1.2 2022/10/21 12:55:31 adam Exp $

DISTNAME=	libaec-1.0.6
CATEGORIES=	archivers
MASTER_SITES=	https://gitlab.dkrz.de/k202009/libaec/uploads/45b10e42123edd26ab7b3ad92bcf7be2/

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://gitlab.dkrz.de/k202009/libaec
COMMENT=	Adaptive entropy coding library
LICENSE=	2-clause-bsd

CONFLICTS=	szip-[0-9]*

USE_TOOLS+=	autoconf automake autoreconf
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

pre-configure:
	cd ${WRKSRC} && autoreconf -if

.include "../../mk/bsd.pkg.mk"
