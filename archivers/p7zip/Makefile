# $NetBSD: Makefile,v 1.4 2004/10/08 15:57:51 tv Exp $
#

DISTNAME=		p7zip_0.80
PKGNAME=		p7zip-0.80
CATEGORIES=		archivers
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=p7zip/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://p7zip.sourceforge.net/
COMMENT=		File archiver with high compression

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NOT_FOR_PLATFORM=	*-*-m68* *-*-mipseb* *-*-powerpc* *-*-sparc*

USE_BUILDLINK3=		yes
USE_LANGUAGES=		c c++
MAKEFILE=		makefile
NO_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
PTHREAD_OPTS+=		require

GCC_REQD=		3.0

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/7z ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/p7zip
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/p7zip

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
