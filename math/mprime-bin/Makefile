# $NetBSD: Makefile,v 1.4 2009/12/21 20:10:17 joerg Exp $
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

NO_BUILD=		yes
INSTALLATION_DIRS=	bin share/doc/mprime

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mprime ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*txt ${DESTDIR}${PREFIX}/share/doc/mprime

.include "../../mk/bsd.pkg.mk"
