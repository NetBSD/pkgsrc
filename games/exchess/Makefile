# $NetBSD: Makefile,v 1.16 2014/02/09 16:50:45 wiedi Exp $

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

CFLAGS.SunOS+=		-Du_int64_t=uint64_t

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
