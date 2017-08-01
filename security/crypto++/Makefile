# $NetBSD: Makefile,v 1.22 2017/08/01 14:59:04 wiz Exp $

DISTNAME=	cryptopp565
PKGNAME=	cryptopp-5.6.5
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
WRKSRC=			${WRKDIR}
CPPFLAGS+=		-DCRYPTOPP_DISABLE_ASM -fPIC
BUILD_TARGET=		all static shared

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/cryptest.exe ${DESTDIR}${PREFIX}/bin/cryptest

.include "../../mk/bsd.pkg.mk"
