# $NetBSD: Makefile,v 1.12 2002/03/17 16:23:34 fredb Exp $
#

DISTNAME=	plsrc141
PKGNAME=	ploticus-1.41
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL:=${PKGNAME_NOREV}/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME:C/src/man/}${EXTRACT_SUFX}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://ploticus.sourceforge.net/doc/Welcome.html
COMMENT=	Versatile data visualization engine

DEPENDS+=	png>=1.2.1:../../graphics/png

NO_CONFIGURE=	YES
USE_X11=	YES
DIST_SUBDIR=	${PKGNAME_NOREV}

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
