# $NetBSD: Makefile,v 1.8 2000/03/26 14:45:50 jlam Exp $
# FreeBSD Id: Makefile,v 1.6 1999/01/27 07:41:12 fenner Exp
#

DISTNAME=	chess-5.00
PKGNAME=	gnuchess-5.00
WRKSRC=		${WRKDIR}/${DISTNAME}/src
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU:=chess/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/chess/chess.html

CONFLICTS=	gnuchess4-*

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	gnuchess

post-build:
	${SED} -e "s,@PREFIX@,${PREFIX},g" ${FILESDIR}/gnuchessx.sh \
		> ${WRKDIR}/gnuchessx.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gnuchess ${PREFIX}/bin/gnuchess
	${INSTALL_SCRIPT} ${WRKDIR}/gnuchessx.sh ${PREFIX}/bin/gnuchessx
	${INSTALL_DATA_DIR} ${PREFIX}/share/gnuchess
	${INSTALL_DATA} ${WRKSRC}/book.dat ${WRKSRC}/book.pgn \
		${PREFIX}/share/gnuchess
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gnuchess
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/README \
		${PREFIX}/share/doc/gnuchess

.include "../../mk/bsd.pkg.mk"
