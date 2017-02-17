# $NetBSD: Makefile,v 1.2 2017/02/17 17:09:16 joerg Exp $

DISTNAME=	amath-1.6.2
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://suyai.innolan.net/

MAINTAINER=	cs@innolan.dk
HOMEPAGE=	http://amath.innolan.net/
COMMENT=	Simple command line calculator
LICENSE=	2-clause-bsd

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	bin
BINNAME=		amath

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${BINNAME} ${DESTDIR}${PREFIX}/bin/${BINNAME}

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ./${BINNAME} test

.include "../../mk/bsd.pkg.mk"
