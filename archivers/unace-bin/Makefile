# $NetBSD: Makefile,v 1.8 2009/05/19 08:59:00 wiz Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base compat

WRKSRC=			${WRKDIR}
BUILD_DIRS=		# empty

INSTALLATION_DIRS=	bin share/doc/unace-bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unace ${DESTDIR}${PREFIX}/bin/unace-bin
	${INSTALL_DATA} ${WRKSRC}/licence ${DESTDIR}${PREFIX}/share/doc/unace-bin

.include "../../mk/bsd.pkg.mk"
