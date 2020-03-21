# $NetBSD: Makefile,v 1.20 2020/03/21 14:41:45 rillig Exp $

DISTNAME=		EXchess_v7.97beta
PKGNAME=		exchess-7.97beta
CATEGORIES=		games
MASTER_SITES=		-https://sites.google.com/site/experimentalchessprogram/home/${DISTNAME}${EXTRACT_SUFX}?attredirects=0&d=1
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://personal.denison.edu/~homand/EXchess.htm
COMMENT=		Experimental chess engine
LICENSE=		gnu-gpl-v3

USE_LANGUAGES=		c++

WRKSRC=			${WRKDIR}/${DISTNAME:C/beta//}
LIBDIR=			${PREFIX}/lib/exchess
DOCDIR=			${PREFIX}/share/doc/exchess
AUTO_MKDIRS=		yes

CFLAGS+=		-DEXCHESS_DIR=${LIBDIR}
LDFLAGS+=		${PTHREAD_LDFLAGS}
LIBS+=			${PTHREAD_LIBS}

SUBST_CLASSES+=		dirs
SUBST_STAGE.dirs=	pre-configure
SUBST_FILES.dirs=	search.par
SUBST_SED.dirs=		-e 's,/Users/homand/EXchess/TB,${PREFIX}/share/egtb,'

do-build:
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} \
		${CXX} ${CFLAGS} src/EXchess.cc -o exchess ${LDFLAGS} ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/exchess ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/search.par ${DESTDIR}${PREFIX}/lib/exchess
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DESTDIR}${DOCDIR}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
