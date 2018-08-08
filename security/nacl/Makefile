# $NetBSD: Makefile,v 1.3 2018/08/08 08:10:24 schmonz Exp $

DISTNAME=	nacl-20110221
CATEGORIES=	security
MASTER_SITES=	https://hyperelliptic.org/nacl/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nacl.cr.yp.to
COMMENT=	Secure, usable, fast networking and cryptography library
LICENSE=	public-domain

USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	bin lib include

do-build:
	cd ${WRKSRC} &&							\
	./do &&								\
	${AR} -r build/*/lib/*/libnacl.a build/*/lib/*/randombytes.o

do-install:
	cd ${WRKSRC}/build/* && \
	${INSTALL_PROGRAM} bin/nacl-sha256 ${DESTDIR}${PREFIX}/bin &&	\
	${INSTALL_PROGRAM} bin/nacl-sha512 ${DESTDIR}${PREFIX}/bin &&	\
	${INSTALL_LIB} lib/*/* ${DESTDIR}${PREFIX}/lib &&		\
	${INSTALL_DATA} include/*/* ${DESTDIR}${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
