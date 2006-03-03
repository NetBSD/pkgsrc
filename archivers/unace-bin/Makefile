# $NetBSD: Makefile,v 1.1.1.1 2006/03/03 22:27:44 wiz Exp $
#

DISTNAME=	linunace25
PKGNAME=	unace-bin-2.50
CATEGORIES=	archivers
MASTER_SITES=	http://www.winace.com/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.winace.com/
COMMENT=	Extract, list and test files in ACE archives (Linux binary)

ONLY_FOR_PLATFORM=	*-*-i386

NO_BIN_ON_FTP=		Only original file distribution.
NO_BIN_ON_CDROM=	Only original file distribution.

WRKSRC=		${WRKDIR}

.include "../../emulators/suse_linux/Makefile.application"

.if !defined(USE_NATIVE_LINUX)
DEPENDS+=	suse_base>=6.1:../../emulators/${SUSE_DIR_PREFIX}_base
DEPENDS+=	suse_compat>=6.1:../../emulators/${SUSE_DIR_PREFIX}_compat
.endif

NO_BUILD=	YES
NO_CONFIGURE=	YES
CHECK_SHLIBS=	NO

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unace ${PREFIX}/bin/unace-bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/unace-bin
	${INSTALL_DATA} ${WRKSRC}/licence ${PREFIX}/share/doc/unace-bin

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"
