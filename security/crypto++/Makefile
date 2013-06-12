# $NetBSD: Makefile,v 1.15 2013/06/12 12:00:08 ryoon Exp $
#

DISTNAME=		cryptopp562
PKGNAME=		cryptopp-5.6.2
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

AUTO_MKDIRS=			yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cryptest.exe ${DESTDIR}${PREFIX}/bin/cryptest
	${INSTALL_DATA} ${WRKSRC}/libcryptopp.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/Readme.txt ${DESTDIR}${PREFIX}/share/doc/cryptopp/README
	${INSTALL_DATA} ${WRKSRC}/License.txt ${DESTDIR}${PREFIX}/share/doc/cryptopp/License
	cd ${WRKSRC} && ${INSTALL_DATA} *.h ${DESTDIR}${PREFIX}/include/cryptopp

.include "../../mk/bsd.pkg.mk"
