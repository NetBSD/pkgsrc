# $NetBSD: Makefile,v 1.5 2012/09/11 23:04:24 asau Exp $
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

NO_BUILD=		yes
INSTALLATION_DIRS=	bin share/doc/mprime

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mprime ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*txt ${DESTDIR}${PREFIX}/share/doc/mprime

.include "../../mk/bsd.pkg.mk"
