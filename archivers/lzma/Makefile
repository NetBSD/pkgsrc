# $NetBSD: Makefile,v 1.2 2008/03/02 03:48:36 jlam Exp $
#

DISTNAME=		lzma443
PKGNAME=		lzma-4.43
CATEGORIES=		archivers
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sevenzip/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jakllsch@kollasch.net
HOMEPAGE=		http://www.7-zip.org/sdk.html
COMMENT=		LZMA compression utility from 7zip

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

WRKSRC=			${WRKDIR}/C/7zip/Compress/LZMA_Alone
MAKE_FILE=		makefile.gcc

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lzma ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
