# $NetBSD: Makefile,v 1.10 2009/05/21 21:13:15 zafer Exp $
#

DISTNAME=		cryptopp552
PKGNAME=		cryptopp-5.5.2
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cryptopp/} 
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.cryptopp.com/
COMMENT=		Free C++ class library of Cryptographic Primitives

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		gmake
MAKE_FILE=		GNUmakefile
WRKSRC=			${WRKDIR}
USE_LANGUAGES=		c++
CPPFLAGS+=		-DCRYPTOPP_DISABLE_ASM
BUILDLINK_TRANSFORM+=	rm:-pipe rm:-msse2
EXTRACT_OPTS_ZIP=	-aqo

AUTO_MKDIRS=			yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cryptest.exe ${PREFIX}/bin/cryptest
	${INSTALL_DATA} ${WRKSRC}/libcryptopp.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/Readme.txt ${PREFIX}/share/doc/cryptopp/README
	${INSTALL_DATA} ${WRKSRC}/License.txt ${PREFIX}/share/doc/cryptopp/License
	cd ${WRKSRC} && ${INSTALL_DATA} *.h ${PREFIX}/include/cryptopp

.include "../../mk/bsd.pkg.mk"
