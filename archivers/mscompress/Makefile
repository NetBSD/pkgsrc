# $NetBSD: Makefile,v 1.10 2006/07/23 14:39:49 rillig Exp $
#

DISTNAME=		mscompress-0.3
CATEGORIES=		archivers
MASTER_SITES=		${MASTER_SITE_SUNSITE:=utils/compress/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		ftp://ftp.penguin.cz/pub/users/mhi/mscompress/
COMMENT=		Microsoft "compress.exe/expand.exe" compatible (de)compressor

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mscompress ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/msexpand ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mscompress.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/msexpand.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
