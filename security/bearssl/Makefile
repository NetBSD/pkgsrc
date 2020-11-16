# $NetBSD: Makefile,v 1.8 2020/11/16 07:43:25 schmonz Exp $

DISTNAME=	bearssl-0.6
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bearssl.org/
COMMENT=	Implementation of the SSL/TLS protocol (RFC 5246)
LICENSE=	mit

INSTALLATION_DIRS=	bin include lib

LDFLAGS.SunOS+=	-lsocket -lnsl

pre-build:
	${MKDIR} ${WRKSRC}/build/obj

do-install:
	cd ${WRKSRC}/build && \
		${INSTALL_PROGRAM} brssl ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC}/inc && \
		${INSTALL_DATA} *.h ${DESTDIR}${PREFIX}/include
	cd ${WRKSRC}/build && \
		${INSTALL_DATA} libbearssl.* ${DESTDIR}${PREFIX}/lib

do-test:
	cd ${WRKSRC} && \
		./build/testcrypto all && \
		./build/testspeed all && \
		./build/testx509

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"

SUBST_CLASSES+=		dylib
SUBST_STAGE.dylib=	pre-configure
SUBST_FILES.dylib=	conf/Unix.mk
SUBST_SED.dylib=	-e 's|\.so|.dylib|g'

.PHONY: fix-darwin-install-name
post-install: fix-darwin-install-name
fix-darwin-install-name:
	for f in ${DESTDIR}${PREFIX}/lib/lib*.dylib; do \
	    install_name_tool -id `${ECHO} $$f | ${SED} -e 's,${DESTDIR},,g'` $$f; \
	done

.endif

.include "../../mk/bsd.pkg.mk"
