# $NetBSD: Makefile,v 1.1 2019/04/29 15:51:23 bacon Exp $

DISTNAME=	libaec-1.0.4
CATEGORIES=	archivers
MASTER_SITES=	https://gitlab.dkrz.de/k202009/libaec/uploads/ea0b7d197a950b0c110da8dfdecbb71f/

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
