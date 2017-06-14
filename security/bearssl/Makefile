# $NetBSD: Makefile,v 1.3 2017/06/14 01:14:30 agc Exp $

DISTNAME=	bearssl-0.4
CATEGORIES=	security
MASTER_SITES=	https://bearssl.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bearssl.org/
COMMENT=	Implementation of the SSL/TLS protocol (RFC 5246)
LICENSE=	mit

INSTALLATION_DIRS=	bin include lib

do-install:
	cd ${WRKSRC}/build && \
		${INSTALL_PROGRAM} brssl ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC}/inc && \
		${INSTALL_DATA} *.h ${DESTDIR}${PREFIX}/include
	cd ${WRKSRC}/build && \
		${INSTALL_LIB} libbearssl.* ${DESTDIR}${PREFIX}/lib

do-test:
	cd ${WRKSRC} && \
		./build/testcrypto all && \
		./build/testspeed all && \
		./build/testx509

.include "../../mk/bsd.pkg.mk"
