# $NetBSD: Makefile,v 1.12 2006/06/07 12:19:24 joerg Exp $

DISTNAME=		EXCH314S
PKGNAME=		exchess-3.14
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		http://pc.astro.brandeis.edu/BRAG/people/dch/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pc.astro.brandeis.edu/BRAG/people/dch/chess.html
COMMENT=		Experimental chess engine

USE_LANGUAGES=		c++
NO_CONFIGURE=		yes

WRKSRC=			${WRKDIR}
LIBDIR=			${PREFIX}/lib/exchess
DOCDIR=			${PREFIX}/share/doc/exchess

post-extract:
	cd ${WRKSRC} && ${MV} search.par search.par.in
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-build:
	${SED}	-e "s,@PREFIX@,${PREFIX},g" \
		< ${WRKSRC}/search.par.in > ${WRKSRC}/search.par

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
