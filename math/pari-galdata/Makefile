# $NetBSD: Makefile,v 1.14 2020/01/26 17:31:39 rillig Exp $

DISTNAME=		galdata
PKGNAME=		pari-galdata-2.2
CATEGORIES=		math
MASTER_SITES=		https://pari.math.u-bordeaux.fr/pub/pari/packages/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://pari.math.u-bordeaux.fr/
COMMENT=		Galois group data for pari

DEPENDS+=		pari>=2.2.7:../../math/pari

WRKSRC=			${WRKDIR}/data/galdata

DIST_SUBDIR=		pari-2.2

NO_BUILD=		yes
INSTALLATION_DIRS=	share/pari/galdata

do-install:
	${INSTALL_DATA} ${WRKSRC}/* ${DESTDIR}${PREFIX}/share/pari/galdata

.include "../../mk/bsd.pkg.mk"
