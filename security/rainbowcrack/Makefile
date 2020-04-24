# $NetBSD: Makefile,v 1.16 2020/04/24 11:41:38 nia Exp $

PKGNAME=		rainbowcrack-1.2
DISTNAME=		rainbowcrack-1.2-src
PKGREVISION=		6
CATEGORIES=		security
MASTER_SITES=		# http://www.rainbowcrack.com/downloads/
EXTRACT_SUFX=		.zip
DISTFILES=		rainbowcrack-1.2-src.zip \
			rainbowcrack-1.2-openbsd-diffs.tar.gz

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		https://project-rainbowcrack.com/
COMMENT=		Hash cracker

BROKEN=			"Fails to build with OpenSSL 1.1"

BUILD_DIRS=		src
USE_LANGUAGES=		c c++
USE_TOOLS+=		patch
MAKE_FILE=		${FILESDIR}/Makefile
INSTALLATION_DIRS=	bin share/doc/rainbowcrack share/rainbowcrack

pre-patch:
	cd ${WRKSRC}/src && ${PATCH} < ${WRKDIR}/Public.cpp.diff

post-install:
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.htm \
		${DESTDIR}${PREFIX}/share/doc/rainbowcrack/
	${INSTALL_DATA} ${WRKSRC}/src/charset.txt ${DESTDIR}${PREFIX}/share/rainbowcrack

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
