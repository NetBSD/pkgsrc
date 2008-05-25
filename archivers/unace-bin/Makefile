# $NetBSD: Makefile,v 1.6 2008/05/25 13:16:10 dillo Exp $
#

DISTNAME=	linunace25
PKGNAME=	unace-bin-2.50
CATEGORIES=	archivers
MASTER_SITES=	http://www.winace.com/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.winace.com/
COMMENT=	Extract, list and test files in ACE archives (Linux binary)

LICENSE=		unace-license
RESTRICTED=		Only original file distribution.
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base compat

WRKSRC=			${WRKDIR}
BUILD_DIRS=		# empty

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unace ${PREFIX}/bin/unace-bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/unace-bin
	${INSTALL_DATA} ${WRKSRC}/licence ${PREFIX}/share/doc/unace-bin

.include "../../mk/bsd.pkg.mk"
