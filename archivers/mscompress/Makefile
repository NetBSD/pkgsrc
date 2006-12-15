# $NetBSD: Makefile,v 1.11 2006/12/15 14:34:18 wiz Exp $
#

DISTNAME=		mscompress-0.3
CATEGORIES=		archivers
MASTER_SITES=		${MASTER_SITE_SUNSITE:=utils/compress/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
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
