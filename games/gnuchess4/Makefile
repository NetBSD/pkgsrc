# $NetBSD: Makefile,v 1.12 2006/03/04 21:29:42 jlam Exp $

DISTNAME=		gnuchess-4.0.pl80
PKGNAME=		gnuchess4-4.0.80
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/chess/chess.html
COMMENT=		The "classic" GNU chess

CONFLICTS=		gnuchess-4.*

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		src
BUILD_DIRS=		${CONFIGURE_DIRS}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gnuchess4
	cd ${WRKSRC}/doc; ${INSTALL_DATA} \
		ARTICLE ARTICLE.2 CHESSTOOL FAQ HEURISTICS MOVE-GEN \
		README.font README.output \
		${PREFIX}/share/doc/gnuchess4

.include "../../mk/bsd.pkg.mk"
