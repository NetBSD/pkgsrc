# $NetBSD: Makefile,v 1.3 2000/03/21 22:40:54 tron Exp $
#

DISTNAME=	plsrc13
PKGNAME=	ploticus-1.31
CATEGORIES=	graphics
MASTER_SITES=	http://www.sgpr.net/download/ \
		http://gd.tuwien.ac.at/visual/ploticus/download/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${MANDIST}${EXTRACT_SUFX}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.sgpr.net/

DEPENDS+=	png>=1.0.6:../../graphics/png

NO_CONFIGURE=	YES
USE_X11=	YES

MANDIST=	plman13
MANSRC=		${WRKDIR}/${MANDIST}
DOCDST=		${PREFIX}/share/doc/ploticus
NROFF?=		nroff -mandoc

do-install:
.for file in pl plpng pltab pltabpng
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin/${file}
.endfor
.for file in pl ploticus plpng pltab
	${INSTALL_MAN} ${MANSRC}/man1/${file}.1 ${PREFIX}/man/man1/${file}.1
.endfor
	${INSTALL_DATA_DIR} ${DOCDST}
.for file in Faq Problems Util Welcome annotate areadef attributetypes \
	     axis bars bevelrect breakaxis catslide color condex config \
	     controlling curvefit dataformat dates defineunits \
	     drawcommands endproc functions getdata gifpatent import \
	     interactive legend legendentry limits line linedetails \
	     lineplot missingdata originaldata page paper pie posters \
	     print rangebar rangesweep scaleunits scatterplot scripts \
	     slides specialchars symboldetails tabulate textdetails times \
	     trailer transform variables web
	${NROFF} <${MANSRC}/manpl/${file} >${WRKDIR}/${file}
	${INSTALL_DATA} ${WRKDIR}/${file} ${DOCDST}/${file}
.endfor

.include "../../mk/bsd.pkg.mk"
