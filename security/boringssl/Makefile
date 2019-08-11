# $NetBSD: Makefile,v 1.12 2019/08/11 13:22:45 wiz Exp $

DISTNAME=	boringssl-20151230
PKGREVISION=	9
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://boringssl.googlesource.com/boringssl/
COMMENT=	Fork of OpenSSL designed to meet Google's needs
LICENSE=	openssl

WRKSRC=		${WRKDIR}/boringssl

.include "../../lang/go/version.mk"

BUILD_DEPENDS+=	${GO_PACKAGE_DEP}

USE_TOOLS+=	cmake perl
USE_LANGUAGES+=	c c++

AUTO_MKDIRS=	yes

SUBST_CLASSES+=		go
SUBST_STAGE.go=		post-patch
SUBST_FILES.go=		CMakeLists.txt
SUBST_SED.go=		-e '/find_program.GO_EXECUTABLE/s,go,${GO},'

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
