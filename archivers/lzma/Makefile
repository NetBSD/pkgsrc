# $NetBSD: Makefile,v 1.3 2008/10/08 18:08:32 wiz Exp $
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

CONFLICTS+=		lzma-utils-[0-9]*

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lzma ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
