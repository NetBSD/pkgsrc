# $NetBSD: Makefile,v 1.1.1.1 1999/02/08 08:48:37 frueauf Exp $
# FreeBSD Id: Makefile,v 1.6 1999/01/27 07:41:12 fenner Exp
#

DISTNAME=		gnuchess-4.0.pl79
PKGNAME=		gnuchess-4.0.79
WRKSRC=			${WRKDIR}/${DISTNAME}/src
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gnuchess

MAINTAINER=		packages@netbsd.org

GNU_CONFIGURE=		yes

post-install:
	${MKDIR} ${PREFIX}/share/doc/gnuchess
.for file in ARTICLE ARTICLE.2 CHESSTOOL FAQ HEURISTICS MOVE-GEN README.font README.output
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/${file} ${PREFIX}/share/doc/gnuchess
.endfor

.include "../../mk/bsd.pkg.mk"
