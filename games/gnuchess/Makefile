# $NetBSD: Makefile,v 1.13 2001/11/29 01:12:33 hubertf Exp $
# FreeBSD Id: Makefile,v 1.6 1999/01/27 07:41:12 fenner Exp
#

DISTNAME=	chess-5.00
PKGNAME=	gnuchess-5.00
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU:=chess/}

PATCHFILES=	gnu500+.patch
PATCH_SITES=	http://www.tim-mann.org/xboard/
PATCH_DIST_ARGS=	-d ${WRKDIR}/${DISTNAME} --quiet -E ${PATCH_STRIP}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/chess/chess.html
COMMENT=	GNU chess engine

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
ALL_TARGET=	gnuchess
WRKSRC=		${WRKDIR}/${DISTNAME}/src

BOOKDIR=	${PREFIX}/lib/gnuchess
DOCDIR=		${PREFIX}/share/doc/gnuchess

post-build:
	${SED} -e "s|@PREFIX@|${PREFIX}|g"				\
		${FILESDIR}/gnuchessx.sh > ${WRKDIR}/gnuchessx.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gnuchess ${PREFIX}/bin/gnuchess
	${INSTALL_SCRIPT} ${WRKDIR}/gnuchessx.sh ${PREFIX}/bin/gnuchessx
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/README ${DOCDIR}
	${INSTALL_DATA_DIR} ${BOOKDIR}
	${TOUCH} ${BOOKDIR}/.directory

.include "../../mk/bsd.pkg.mk"
