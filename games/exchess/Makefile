# $NetBSD: Makefile,v 1.17 2014/09/11 16:59:16 jperkin Exp $

DISTNAME=		EXchess_v7.31beta
PKGNAME=		exchess-7.31beta
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_LOCAL}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://personal.denison.edu/~homand/EXchess.htm
COMMENT=		Experimental chess engine
LICENSE=		gnu-gpl-v3

USE_LANGUAGES=		c++
NO_CONFIGURE=		yes

WRKSRC=			${WRKDIR}/${DISTNAME:C/beta//}
LIBDIR=			${PREFIX}/lib/exchess
DOCDIR=			${PREFIX}/share/doc/exchess

CFLAGS+=		-DEXCHESS_DIR=${LIBDIR:Q}
LDFLAGS+=		${PTHREAD_LDFLAGS}
LIBS+=			${PTHREAD_LIBS}

post-extract:
	cd ${WRKSRC} && ${MV} search.par search.par.in

do-build:
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} \
		${CXX} ${CFLAGS} src/EXchess.cc -o exchess ${LDFLAGS} ${LIBS}

post-build:
	${SED}	-e "s,@PREFIX@,${PREFIX},g" \
		< ${WRKSRC}/search.par.in > ${WRKSRC}/search.par

INSTALLATION_DIRS+=	bin lib/exchess ${DOCDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/exchess ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/search.par ${DESTDIR}${PREFIX}/lib/exchess
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DESTDIR}${DOCDIR}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
