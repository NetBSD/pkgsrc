# $NetBSD: Makefile,v 1.8 2004/07/28 02:47:35 minskim Exp $
#

DISTNAME=		mscompress-0.3
CATEGORIES=		archivers
MASTER_SITES=		${MASTER_SITE_SUNSITE:=utils/compress/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		ftp://ftp.penguin.cz/pub/users/mhi/mscompress/
COMMENT=		Microsoft "compress.exe/expand.exe" compatible (de)compressor

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mscompress ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/msexpand ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mscompress.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/msexpand.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
