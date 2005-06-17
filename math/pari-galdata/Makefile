# $NetBSD: Makefile,v 1.6 2005/06/17 03:50:20 jlam Exp $

DISTNAME=		galdata
PKGNAME=		pari-galdata-2.1
PKGREVISION=		1
CATEGORIES=		math
MASTER_SITES=		ftp://www.gn-50uma.de/gn/gn-50uma.de/pari/ \
			http://www.gn-50uma.de/ftp/pari/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.parigp-home.de/
COMMENT=		Galois group data for pari

DEPENDS+=		pari-[0-9]*:../../math/pari

WRKSRC=			${WRKDIR}
DIST_SUBDIR=		pari-2.1

NO_BUILD=		yes
INSTALLATION_DIRS=	share/pari/galdata

do-install:
	${INSTALL_DATA} ${WRKSRC}/[CR]* ${PREFIX}/share/pari/galdata

.include "../../mk/bsd.pkg.mk"
