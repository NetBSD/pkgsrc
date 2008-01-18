# $NetBSD: Makefile,v 1.3 2008/01/18 05:09:41 tnn Exp $
#

PKGNAME=		rainbowcrack-1.2
DISTNAME=		rainbowcrack-1.2-src
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		http://www.rainbowcrack.com/downloads/
EXTRACT_SUFX=		.zip
DISTFILES=		rainbowcrack-1.2-src.zip \
                        rainbowcrack-1.2-openbsd-diffs.tar.gz

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://www.antsight.com/zsl/rainbowcrack/
COMMENT=		Hash cracker

BUILD_DIRS=		src
EXTRACT_OPTS_ZIP=	-aqo
USE_LANGUAGES=		c c++
USE_TOOLS+=		patch
MAKE_FILE=		${FILESDIR}/Makefile
USE_OLD_DES_API=	yes
INSTALLATION_DIRS=	bin share/doc/rainbowcrack share/rainbowcrack

post-patch:
	cd ${WRKSRC}/src && ${PATCH} < ${WRKDIR}/Public.cpp.diff

post-install:
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.htm \
		${PREFIX}/share/doc/rainbowcrack/
	${INSTALL_DATA} ${WRKSRC}/src/charset.txt ${PREFIX}/share/rainbowcrack

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
