# $NetBSD: Makefile,v 1.10 2008/03/03 01:10:06 jlam Exp $
#

DISTNAME=		ProFitV2.2
PKGNAME=		profit-2.2
CATEGORIES=		biology
MASTER_SITES=		http://acrmwww.biochem.ucl.ac.uk/software/profit/235216/

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://acrmwww.biochem.ucl.ac.uk/programs/profit/index.html
COMMENT=		Performs least squares fits of two protein structures

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=		profit
BUILD_DIRS=		src
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/profit ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/profit
.for sufx in dvi ps tex
	${INSTALL_DATA} ${WRKSRC}/doc/ProFit.${sufx}			\
		${DESTDIR}${PREFIX}/share/doc/profit
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/html/profit
	cd ${WRKSRC}/doc/ProFit/ && 					\
		${PAX} -rw . ${DESTDIR}${PREFIX}/share/doc/html/profit/

.include "../../mk/bsd.pkg.mk"
