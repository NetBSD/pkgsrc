# $NetBSD: Makefile,v 1.1.1.1 2000/10/25 08:40:00 jlam Exp $

DISTNAME=		EXCH314S
PKGNAME=		exchess-3.14
CATEGORIES=		games
MASTER_SITES=		http://pc.astro.brandeis.edu/BRAG/people/dch/
EXTRACT_SUFX=		.zip

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://pc.astro.brandeis.edu/BRAG/people/dch/chess.html

NO_WRKSUBDIR=		# defined
NO_CONFIGURE=		# defined

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
