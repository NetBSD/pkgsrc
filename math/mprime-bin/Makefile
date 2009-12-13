# $NetBSD: Makefile,v 1.3 2009/12/13 02:01:27 asau Exp $
#

DISTNAME=		mprime2414
PKGNAME=		mprime-bin-24.14
CATEGORIES=		math
MASTER_SITES=		ftp://mersenne.org/gimps/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.mersenne.org/freesoft.htm
COMMENT=		Mersenne prime tester (binary)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base

do-build:

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mprime ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/mprime
	${INSTALL_DATA} ${WRKSRC}/*txt ${DESTDIR}${PREFIX}/share/doc/mprime

.include "../../mk/bsd.pkg.mk"
