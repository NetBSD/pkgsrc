# $NetBSD: Makefile,v 1.10 2001/07/08 08:09:39 rh Exp $
#

DISTNAME=	plsrc141
PKGNAME=	ploticus-1.41
CATEGORIES=	graphics
MASTER_SITES=	http://www.sgpr.net/download/ \
		http://gd.tuwien.ac.at/visual/ploticus/download/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME:C/src/man/}${EXTRACT_SUFX}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.sgpr.net/
COMMENT=	Versatile data visualization engine

DEPENDS+=	png>=1.0.11:../../graphics/png

NO_CONFIGURE=	YES
USE_X11=	YES
DIST_SUBDIR=	${PKGNAME}

MANSRC=		${WRKSRC:C/plsrc/plman/}
DOCDST=		${PREFIX}/share/doc/ploticus
NROFF?=		nroff -mandoc

do-install:
.for file in pl plpng pltab pltabpng
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin/${file}
.endfor
.for file in pl ploticus plpng pltab
	${INSTALL_MAN} ${MANSRC}/man/man1/${file}.1 \
		${PREFIX}/man/man1/${file}.1
.endfor
	${INSTALL_DATA_DIR} ${DOCDST}
.for file in Changelog Contents Copyright Download Feedback Feedback00	\
	Versions Welcome
	${INSTALL_DATA} ${MANSRC}/man/manpl/${file} ${DOCDST}/${file}
.endfor
.for file in Faq Problems annotate areadef attributetypes autorange	\
	axis bars bevelrect breakaxis catslide color condex config	\
	controlling curvefit dataformat dates datesettings defineunits	\
	drawcommands endproc foo functions getdata gifpatent import	\
	interactive legend legendentry limits line linedetails lineplot	\
	missingdata originaldata page paper pie posters prefabs print	\
	processdata rangebar rangesweep scaleunits scatterplot scripts	\
	slides specialchars symboldetails tabulate textdetails times	\
	trailer transform variables web
	${NROFF} <${MANSRC}/man/manpl/${file} >${WRKDIR}/${file}
	${INSTALL_DATA} ${WRKDIR}/${file} ${DOCDST}/${file}
.endfor

.include "../../mk/bsd.pkg.mk"
