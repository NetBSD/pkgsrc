# $NetBSD: Makefile,v 1.1.1.1 2007/02/17 12:07:28 obache Exp $
#

DISTNAME=		lzma443
PKGNAME=		lzma-4.43
CATEGORIES=		archivers
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sevenzip/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jakllsch@kollasch.net
HOMEPAGE=		http://www.7-zip.org/sdk.html
COMMENT=		LZMA compression utility from 7zip

USE_LANGUAGES=		c c++

WRKSRC=		${WRKDIR}/C/7zip/Compress/LZMA_Alone

USE_TOOLS+=		gmake

MAKE_FILE=		makefile.gcc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lzma ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
