# $NetBSD: Makefile,v 1.1.1.1 2004/06/25 13:56:12 wiz Exp $
#

DISTNAME=		p7zip_0.80
PKGNAME=		p7zip-0.80
CATEGORIES=		archivers
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=p7zip/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://p7zip.sourceforge.net/
COMMENT=		File archiver with high compression

USE_BUILDLINK3=		yes
MAKEFILE=		makefile
NO_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/7z ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/p7zip
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/p7zip

.include "../../mk/bsd.pkg.mk"
