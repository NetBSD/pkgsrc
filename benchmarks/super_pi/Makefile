# $NetBSD: Makefile,v 1.3 2012/09/11 22:37:15 asau Exp $
#

DISTNAME=		super_pi
PKGNAME=		super_pi-20030927
CATEGORIES=		benchmarks math
MASTER_SITES=		ftp://pi.super-computing.org/Linux/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		ftp://pi.super-computing.org/Linux/
COMMENT=		Pi calculation program, used for stability testing (binary)
LICENSE=		generic-nonlicense

RESTRICTED=		${LICENSE}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

DIST_SUBDIR=		${PKGNAME_NOREV}

INSTALLATION_DIRS=	bin

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base

WRKSRC=			${WRKDIR}

do-build:

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pi ${DESTDIR}${PREFIX}/bin/super_pi

.include "../../mk/bsd.pkg.mk"
