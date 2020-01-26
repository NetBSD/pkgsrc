# $NetBSD: Makefile,v 1.8 2020/01/26 17:30:40 rillig Exp $
#

DISTNAME=		lzma465
PKGNAME=		lzma-4.65
CATEGORIES=		archivers
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sevenzip/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.7-zip.org/sdk.html
COMMENT=		LZMA compression utility from 7zip
LICENSE=		public-domain

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

WRKSRC=			${WRKDIR}/CPP/7zip/Compress/LZMA_Alone
MAKE_FILE=		makefile.gcc

CONFLICTS+=		lzma-utils-[0-9]* xz-utils-[0-9]*

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lzma ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
