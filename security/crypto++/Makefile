# $NetBSD: Makefile,v 1.28 2025/02/13 18:18:54 adam Exp $

DISTNAME=	cryptopp890
PKGNAME=	cryptopp-8.9.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=weidai11/}
GITHUB_RELEASE=	CRYPTOPP_8_9_0
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.cryptopp.com/
COMMENT=	Free C++ class library of Cryptographic Primitives
LICENSE=	boost-license

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake
MAKE_FILE=	GNUmakefile
BUILD_TARGET=	all libcryptopp.pc
WRKSRC=		${WRKDIR}
CPPFLAGS+=	-DCRYPTOPP_DISABLE_ASM -fPIC
TEST_TARGET=	test

PKGCONFIG_OVERRIDE=		libcryptopp.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/cryptest.exe ${DESTDIR}${PREFIX}/bin/cryptest

.include "../../mk/bsd.pkg.mk"
