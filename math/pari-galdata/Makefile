# $NetBSD: Makefile,v 1.3 2003/12/30 17:27:31 cjep Exp $

DISTNAME=		galdata
PKGNAME=		pari-galdata-2.1
WRKSRC=			${WRKDIR}
CATEGORIES=		math
MASTER_SITES=		ftp://www.gn-50uma.de/gn/gn-50uma.de/pari/ \
			http://www.gn-50uma.de/ftp/pari/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.parigp-home.de/
COMMENT=		Galois group data for pari

DEPENDS+=		pari-[0-9]*:../../math/pari

DIST_SUBDIR=		pari-2.1

NO_BUILD=		yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/[CR]* ${PREFIX}/share/pari/galdata

.include "../../mk/bsd.pkg.mk"
