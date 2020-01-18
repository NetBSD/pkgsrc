# $NetBSD: Makefile,v 1.11 2020/01/18 23:32:01 rillig Exp $

DISTNAME=		book_1.02.pgn
PKGNAME=		gnuchess-book-1.02
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_GNU:=chess/}
EXTRACT_SUFX=		.gz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnu.org/software/chess/
COMMENT=		Chess opening book for GNU Chess (default)
LICENSE=		public-domain

DEPENDS+=		gnuchess>=6:../../games/gnuchess

CONFLICTS+=		gnuchess-book-medium-[0-9]*

WRKSRC=			${WRKDIR}
NO_CONFIGURE=		yes

BOOKDIR=		${PREFIX}/lib/gnuchess

INSTALLATION_DIRS+=	${BOOKDIR}

do-build:
	cd ${WRKSRC} && ${PREFIX}/bin/gnuchess -a ${DISTNAME} </dev/null

do-install:
	${INSTALL_DATA} ${WRKSRC}/book.bin ${DESTDIR}${BOOKDIR}

.include "../../mk/bsd.pkg.mk"
