# $NetBSD: Makefile,v 1.7 2004/01/20 12:15:40 agc Exp $

DISTNAME=		EXCH314S
PKGNAME=		exchess-3.14
CATEGORIES=		games
MASTER_SITES=		http://pc.astro.brandeis.edu/BRAG/people/dch/
EXTRACT_SUFX=		.zip

MAINTAINER=		jlam@NetBSD.org
HOMEPAGE=		http://pc.astro.brandeis.edu/BRAG/people/dch/chess.html
COMMENT=		Experimental chess engine

NO_CONFIGURE=		# defined

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
