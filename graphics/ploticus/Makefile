# $NetBSD: Makefile,v 1.9 2001/05/22 09:32:22 wiz Exp $
#

DISTNAME=	plsrc13
PKGNAME=	ploticus-1.39
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
DIST_SUBDIR=	ploticus-1.39

WRKSRC=		${WRKDIR}/ploticus/src
MANSRC=		${WRKDIR}/ploticus/man
DOCDST=		${PREFIX}/share/doc/ploticus
NROFF?=		nroff -mandoc

do-install:
.for file in pl plpng pltab pltabpng
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin/${file}
.endfor
.for file in pl ploticus plpng pltab
	${INSTALL_MAN} ${MANSRC}/../man/man1/${file}.1 \
		${PREFIX}/man/man1/${file}.1
.endfor
	${INSTALL_DATA_DIR} ${DOCDST}
.for file in Faq Problems Util annotate areadef attributetypes axis bars bevelrect breakaxis catslide color condex config controlling curvefit dataformat dates datesettings defineunits drawcommands endproc functions getdata gifpatent import interactive legend legendentry limits line linedetails lineplot missingdata originaldata page paper pie posters print processdata rangebar rangesweep scaleunits scatterplot scripts slides specialchars symboldetails tabulate textdetails times trailer transform variables web
	${NROFF} <${MANSRC}/../man/manpl/${file} >${WRKDIR}/${file}
	${INSTALL_DATA} ${WRKDIR}/${file} ${DOCDST}/${file}
.endfor

.include "../../mk/bsd.pkg.mk"
