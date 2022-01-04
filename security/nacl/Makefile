# $NetBSD: Makefile,v 1.5 2022/01/04 20:53:20 schmonz Exp $

DISTNAME=	nacl-20110221
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	https://hyperelliptic.org/nacl/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nacl.cr.yp.to/
COMMENT=	Secure, usable, fast networking and cryptography library
LICENSE=	public-domain

USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	bin lib include

do-build:
	cd ${WRKSRC} &&							\
	./do &&								\
	${AR} -r build/*/lib/*/libnacl.a build/*/lib/*/randombytes.o

do-install:
	cd ${WRKSRC}/build/* &&						\
	for i in nacl-sha256 nacl-sha512				\
		curvecpclient curvecpserver				\
		curvecpmakekey curvecpprintkey curvecpmessage; do	\
		${INSTALL_PROGRAM} bin/$${i} ${DESTDIR}${PREFIX}/bin;	\
	done &&								\
	for i in lib/*/*; do						\
		${INSTALL_LIB} $${i} ${DESTDIR}${PREFIX}/lib;		\
	done &&								\
	for i in include/*/*; do					\
		${INSTALL_DATA} $${i} ${DESTDIR}${PREFIX}/include;	\
	done

.include "../../mk/bsd.pkg.mk"
