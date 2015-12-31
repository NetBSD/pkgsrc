# $NetBSD: Makefile,v 1.1.1.1 2015/12/31 02:57:35 agc Exp $

DISTNAME=	boringssl-20151230
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://boringssl.googlesource.com/boringssl/
COMMENT=	Fork of OpenSSL designed to meet Google's needs
LICENSE=	openssl

WRKSRC=		${WRKDIR}/boringssl

USE_TOOLS+=	cmake perl
USE_LANGUAGES+=	c c++

AUTO_MKDIRS=	yes

do-build:
	mkdir -p ${WRKSRC}/build
	cd ${WRKSRC}/build && cmake ..
	cd ${WRKSRC}/build && make

do-install:
	for d in bssl/bin bssl/lib bssl/include/openssl; do		\
		mkdir -p ${DESTDIR}${PREFIX}/$$d; 			\
	done
	${INSTALL_LIB} ${WRKSRC}/build/crypto/libcrypto.a ${DESTDIR}${PREFIX}/bssl/lib
	${INSTALL_LIB} ${WRKSRC}/build/ssl/libssl.a ${DESTDIR}${PREFIX}/bssl/lib
	${INSTALL_PROGRAM} ${WRKSRC}/build/ssl/test/bssl_shim ${DESTDIR}${PREFIX}/bssl/bin/bssl_shim
	${INSTALL_PROGRAM} ${WRKSRC}/build/ssl/ssl_test ${DESTDIR}${PREFIX}/bssl/bin/ssl_test
	${INSTALL_PROGRAM} ${WRKSRC}/build/tool/bssl ${DESTDIR}${PREFIX}/bssl/bin/bssl
	(cd ${WRKSRC}/include/openssl &&				\
		for f in *.h; do					\
			${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/bssl/include/openssl/$$f; \
		done)

.include "../../mk/bsd.pkg.mk"
