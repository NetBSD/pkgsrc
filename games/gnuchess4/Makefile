# $NetBSD: Makefile,v 1.10 2005/03/24 21:12:54 wiz Exp $

DISTNAME=		gnuchess-4.0.pl80
PKGNAME=		gnuchess4-4.0.80
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/chess/chess.html
COMMENT=		The "classic" GNU chess

CONFLICTS=		gnuchess-4.*

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

WRKSRC=			${WRKDIR}/${DISTNAME}/src
GNU_CONFIGURE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gnuchess4
	cd ${WRKSRC}/../doc; ${INSTALL_DATA} \
		ARTICLE ARTICLE.2 CHESSTOOL FAQ HEURISTICS MOVE-GEN \
		README.font README.output \
		${PREFIX}/share/doc/gnuchess4

.include "../../mk/bsd.pkg.mk"
