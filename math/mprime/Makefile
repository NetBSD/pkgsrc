# $NetBSD: Makefile,v 1.1.1.1 2008/06/02 12:40:16 wiz Exp $
#

DISTNAME=		mprime2414
PKGNAME=		mprime-bin-24.14
CATEGORIES=		math
MASTER_SITES=		ftp://mersenne.org/gimps/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.mersenne.org/freesoft.htm
COMMENT=		Mersenne prime tester (binary)

WRKSRC=			${WRKDIR}

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base

do-build:

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mprime ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mprime
	${INSTALL_DATA} ${WRKSRC}/*txt ${PREFIX}/share/doc/mprime

.include "../../mk/bsd.pkg.mk"
