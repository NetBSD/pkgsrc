# $NetBSD: Makefile,v 1.4 2017/09/22 22:00:57 wiedi Exp $

DISTNAME=	bearssl-0.4
CATEGORIES=	security
MASTER_SITES=	https://bearssl.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bearssl.org/
COMMENT=	Implementation of the SSL/TLS protocol (RFC 5246)
LICENSE=	mit

INSTALLATION_DIRS=	bin include lib

LDFLAGS.SunOS+=	-lsocket -lnsl

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
