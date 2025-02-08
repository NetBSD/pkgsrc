# $NetBSD: Makefile,v 1.27 2025/02/08 13:26:33 wiz Exp $

DISTNAME=	cryptopp870
PKGNAME=	cryptopp-8.7.0
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${HOMEPAGE}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.cryptopp.com/
COMMENT=	Free C++ class library of Cryptographic Primitives
LICENSE=	boost-license

USE_LANGUAGES=		c++
USE_TOOLS+=		gmake
MAKE_FILE=		GNUmakefile
BUILD_TARGET=		all libcryptopp.pc
WRKSRC=			${WRKDIR}
CPPFLAGS+=		-DCRYPTOPP_DISABLE_ASM -fPIC

PKGCONFIG_OVERRIDE=		libcryptopp.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/cryptest.exe ${DESTDIR}${PREFIX}/bin/cryptest

.include "../../mk/bsd.pkg.mk"
