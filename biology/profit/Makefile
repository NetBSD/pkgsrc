# $NetBSD: Makefile,v 1.14 2023/12/23 02:13:49 zafer Exp $
#

DISTNAME=		ProFitV2.2
PKGNAME=		profit-2.2
PKGREVISION=		1
CATEGORIES=		biology
MASTER_SITES=		#

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://acrmwww.biochem.ucl.ac.uk/programs/profit/index.html
COMMENT=		Performs least squares fits of two protein structures

USE_TOOLS+=		pax

BUILD_TARGET=		profit
BUILD_DIRS=		src
AUTO_MKDIRS=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/profit ${DESTDIR}${PREFIX}/bin
.for sufx in dvi ps tex
	${INSTALL_DATA} ${WRKSRC}/doc/ProFit.${sufx}			\
		${DESTDIR}${PREFIX}/share/doc/profit
.endfor
	cd ${WRKSRC}/doc/ProFit/ && 					\
		pax -rw . ${DESTDIR}${PREFIX}/share/doc/profit/html/

.include "../../mk/bsd.pkg.mk"
