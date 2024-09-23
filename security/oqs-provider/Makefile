# $NetBSD: Makefile,v 1.2 2024/09/23 12:30:56 wiz Exp $

VERSION=	0.6.1
DISTNAME=	oqs-provider-${VERSION}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=open-quantum-safe/}

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	https://openquantumsafe.org/applications/tls.html
COMMENT=	Open Quantum Safe provider for OpenSSL
LICENSE=	mit

PLIST_SUBST+=	VERSION="${VERSION}"

do-test:
	cd ${WRKSRC}/${CMAKE_BUILD_DIR} && ${PREFIX}/ctest --test-dir .

do-install:
	mkdir -p ${DESTDIR}${PREFIX}/lib/ossl-modules
	mkdir -p ${DESTDIR}${PREFIX}/include/oqsprov
	${INSTALL_DATA} ${WRKSRC}/oqsprov/oqs_prov.h 			\
		${DESTDIR}${PREFIX}/include/oqsprov/oqs_prov.h
	${INSTALL_DATA} ${WRKSRC}/${CMAKE_BUILD_DIR}/lib/oqsprovider.so \
		${DESTDIR}${PREFIX}/lib/ossl-modules/oqsprovider.so.${VERSION}
	ln -s oqsprovider.so.${VERSION} ${DESTDIR}${PREFIX}/lib/ossl-modules/oqsprovider.so

.include "../../devel/cmake/build.mk"
BUILDLINK_API_DEPENDS.openssl+=	openssl>=3.0
.include "../../security/openssl/buildlink3.mk"
.include "../../security/liboqs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
