# $NetBSD: Makefile,v 1.23 2019/06/05 19:06:07 adam Exp $

DISTNAME=	cryptopp820
PKGNAME=	cryptopp-8.2.0
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

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/cryptest.exe ${DESTDIR}${PREFIX}/bin/cryptest

.include "../../mk/bsd.pkg.mk"
