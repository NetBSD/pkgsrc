# $NetBSD: Makefile,v 1.21 2017/09/21 11:20:04 jperkin Exp $

DISTNAME=		medium
PKGNAME=		gnuchess-book-${DISTNAME}-20000511
PKGREVISION=		4
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.cis.uab.edu/pub/hyatt/common/${DISTNAME}/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Chess opening book for GNU Chess (medium)
LICENSE=		public-domain

DEPENDS+=		gnuchess>=6:../../games/gnuchess

CONFLICTS=		gnuchess-book-[0-9]*

WRKSRC=			${WRKDIR}
DIST_SUBDIR=		chessbooks
NO_CONFIGURE=		yes

BOOKDIR=		${PREFIX}/lib/gnuchess

INSTALLATION_DIRS+=	${BOOKDIR}

do-build:
	cd ${WRKSRC} && ${PREFIX}/bin/gnuchess -a book.txt </dev/null

do-install:
	${INSTALL_DATA} ${WRKSRC}/book.dat ${DESTDIR}${BOOKDIR}

.include "../../mk/bsd.pkg.mk"
