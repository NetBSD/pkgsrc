# $NetBSD: Makefile,v 1.10 2000/10/15 01:53:39 jlam Exp $
# FreeBSD Id: Makefile,v 1.6 1999/01/27 07:41:12 fenner Exp
#

DISTNAME=	chess-5.00
PKGNAME=	gnuchess-5.00nb1
WRKSRC=		${WRKDIR}/${DISTNAME}/src
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU:=chess/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/chess/chess.html

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	gnuchess

BOOKDIR=	${PREFIX}/lib/gnuchess
DOCDIR=		${PREFIX}/share/doc/gnuchess

post-build:
	${SED} -e "s,@PREFIX@,${PREFIX},g" ${FILESDIR}/gnuchessx.sh \
		> ${WRKDIR}/gnuchessx.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gnuchess ${PREFIX}/bin/gnuchess
	${INSTALL_SCRIPT} ${WRKDIR}/gnuchessx.sh ${PREFIX}/bin/gnuchessx
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/README ${DOCDIR}
	${INSTALL_DATA_DIR} ${BOOKDIR}
	${TOUCH} ${BOOKDIR}/.directory

.include "../../mk/bsd.pkg.mk"
