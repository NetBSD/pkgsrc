# $NetBSD: Makefile,v 1.1.1.1 2000/03/26 14:44:41 jlam Exp $
# FreeBSD Id: Makefile,v 1.6 1999/01/27 07:41:12 fenner Exp
#

DISTNAME=		gnuchess-4.0.pl80
PKGNAME=		gnuchess-4.0.80
WRKSRC=			${WRKDIR}/${DISTNAME}/src
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/chess/chess.html

CONFLICTS=		gnuchess-*

MIRROR_DISTFILE=	no

GNU_CONFIGURE=		yes

post-install:
	${MKDIR} ${PREFIX}/share/doc/gnuchess
.for file in ARTICLE ARTICLE.2 CHESSTOOL FAQ HEURISTICS MOVE-GEN README.font README.output
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/${file} ${PREFIX}/share/doc/gnuchess
.endfor

.include "../../mk/bsd.pkg.mk"
