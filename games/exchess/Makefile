# $NetBSD: Makefile,v 1.15 2012/10/06 11:54:36 asau Exp $

DISTNAME=		EXCH314S
# 5.01beta available
PKGNAME=		exchess-3.14
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_LOCAL}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://personal.denison.edu/~homand/EXchess.htm
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

INSTALLATION_DIRS+=	bin lib/exchess ${DOCDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/exchess ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/search.par ${DESTDIR}${PREFIX}/lib/exchess
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
