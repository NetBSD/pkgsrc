# $NetBSD: Makefile,v 1.4 2000/08/18 22:46:33 hubertf Exp $
# FreeBSD Id: Makefile,v 1.6 1999/01/27 07:41:12 fenner Exp
#

DISTNAME=		gnuchess-4.0.pl80
PKGNAME=		gnuchess4-4.0.80
WRKSRC=			${WRKDIR}/${DISTNAME}/src
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/chess/chess.html

CONFLICTS=		gnuchess-4.*

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

GNU_CONFIGURE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gnuchess4
	cd ${WRKSRC}/../doc; ${INSTALL_DATA} \
		ARTICLE ARTICLE.2 CHESSTOOL FAQ HEURISTICS MOVE-GEN \
		README.font README.output \
		${PREFIX}/share/doc/gnuchess4

.include "../../mk/bsd.pkg.mk"
