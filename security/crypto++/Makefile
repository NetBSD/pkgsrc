# $NetBSD: Makefile,v 1.1.1.1 2004/07/26 15:18:44 minskim Exp $
#

DISTNAME=		crypto51
PKGNAME=		crypto++-5.1
CATEGORIES=		security
MASTER_SITES=		http://www.eskimo.com/~weidai/ \
			http://prdownloads.sourceforge.net/cryptopp/ \
			http://gd.tuwien.ac.at/privacy/crypto/libs/cryptlib/
EXTRACT_SUFX=           .zip

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.cryptopp.com/
COMMENT=		Free C++ class library of Cryptographic Primitives

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_GNU_TOOLS+=		make
MAKEFILE=		GNUmakefile
WRKSRC=			${WRKDIR}
USE_LANGUAGES=		c++

INSTALLATION_DIRS=	bin lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cryptest ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libcryptopp.a ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${PREFIX}/include/cryptopp ${PREFIX}/share/doc/cryptopp

	${INSTALL_DATA} ${WRKSRC}/Readme.txt ${PREFIX}/share/doc/cryptopp/README
	${INSTALL_DATA} ${WRKSRC}/License.txt ${PREFIX}/share/doc/cryptopp/License

	for f in ${WRKSRC}/*.h; do	\
		${INSTALL_DATA} $$f ${PREFIX}/include/cryptopp;	\
	done

.include "../../mk/bsd.pkg.mk"
