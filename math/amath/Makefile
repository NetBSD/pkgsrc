# $NetBSD: Makefile,v 1.5 2017/07/25 12:26:05 leot Exp $

DISTNAME=	amath-1.8.3
CATEGORIES=	math
MASTER_SITES=	http://dist1.innolan.net/
MASTER_SITES+=	http://dist2.innolan.net/
MASTER_SITES+=	https://amath.innolan.net/

MAINTAINER=	cs@innolan.net
HOMEPAGE=	https://amath.innolan.net/
COMMENT=	Simple command line calculator
LICENSE=	2-clause-bsd

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=man
CONFIGURE_ARGS+=	--with-libm
CONFIGURE_ARGS+=	CFLAGS=${CFLAGS:Q}
CONFIGURE_ARGS+=	CXXFLAGS=${CXXFLAGS:Q}
CONFIGURE_ARGS+=	LDFLAGS=${LDFLAGS:Q}

BUILD_TARGET=		static
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/amath ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/amath.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ./amath test

.include "../../mk/bsd.pkg.mk"
