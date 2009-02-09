# $NetBSD: Makefile,v 1.7 2009/02/09 23:38:34 joerg Exp $
#

DISTNAME=	linunace25
PKGNAME=	unace-bin-2.50
CATEGORIES=	archivers
MASTER_SITES=	http://www.winace.com/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.winace.com/
COMMENT=	Extract, list and test files in ACE archives (Linux binary)

PKG_DESTDIR_SUPPORT=	user-destdir

LICENSE=		unace-license
RESTRICTED=		Only original file distribution.
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base compat

WRKSRC=			${WRKDIR}
BUILD_DIRS=		# empty

INSTALLATION_DIRS=	bin share/doc/unace-bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unace ${DESTDIR}${PREFIX}/bin/unace-bin
	${INSTALL_DATA} ${WRKSRC}/licence ${DESTDIR}${PREFIX}/share/doc/unace-bin

.include "../../mk/bsd.pkg.mk"
