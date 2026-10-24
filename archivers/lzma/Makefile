# $NetBSD: Makefile,v 1.10 2026/10/24 19:27:33 drixter Exp $
#

DISTNAME=		lzma2605
PKGNAME=		lzma-26.05
CATEGORIES=		archivers
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sevenzip/}
EXTRACT_SUFX=		.7z

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.7-zip.org/sdk.html
COMMENT=		LZMA compression utility from 7zip
LICENSE=		public-domain

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

WRKSRC=			${WRKDIR}/CPP/7zip/Bundles/LzmaCon
MAKE_FILE=		makefile.gcc

MAKE_FLAGS+=		LIB2="-lpthread"
MAKE_FLAGS+=		LDFLAGS="-Wl,-z,relro"

CONFLICTS+=		lzma-utils-[0-9]* xz-utils-[0-9]*

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/_o/lzma ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
