# $NetBSD: Makefile,v 1.20 2004/04/10 23:49:20 snj Exp $
#

DISTNAME=	plsrc210
PKGNAME=	ploticus-2.10
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://ploticus.sourceforge.net/download/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://ploticus.sourceforge.net/doc/Welcome.html
COMMENT=	Versatile data visualization engine

WRKSRC=		${WRKDIR}/${DISTNAME}/src
NO_CONFIGURE=	YES
USE_X11=	YES
USE_BUILDLINK3=	YES

ALL_TARGET=	ploticus
MANSRC=		${WRKDIR}/${DISTNAME}/man
PREFABSRC=	${WRKDIR}/${DISTNAME}/prefabs

DOCDST=		${PREFIX}/share/doc/ploticus
PREFABDST=	${PREFIX}/share/ploticus
NROFF?=		nroff -mandoc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pl ${PREFIX}/bin/pl
	${INSTALL_MAN} ${MANSRC}/man1/pl.1 ${PREFIX}/man/man1/pl.1
	${INSTALL_DATA_DIR} ${PREFABDST}
.for file in chunk_logtics chunk_xaxis lines.pl stack.pl chron.pl	\
	chunk_read chunk_yaxis multidist.pl vbars.pl chunk_area		\
	chunk_setstd dist.pl pie.pl chunk_logstubs chunk_title draw.pl	\
	scat.pl
	${INSTALL_DATA} ${PREFABSRC}/${file} ${PREFABDST}/${file}
.endfor
	${INSTALL_DATA_DIR} ${DOCDST}
.for file in Changelog Contents Copyright Download Feedback Feedback00	\
	Versions Welcome
	${INSTALL_DATA} ${MANSRC}/manpl/${file} ${DOCDST}/${file}
.endfor
.for file in Faq Problems annotate api areadef attributetypes autorange	\
	axis bars breakaxis catslide cgi clickmap color commalist	\
	condex config control controlling curvefit dataformat dates	\
	defineunits drawcommands dynamic fonts functions getdata	\
	gifpatent import interactive legend legendentry limits line	\
	linedetails lineplot page paper pie plshellsql posters prefabs	\
	prepress print processdata rangebar rangesweep rect scaleunits	\
	scatterplot scripts settings shell slides specialchars sql svg	\
	symboldetails tabulate textdetails times trailer usedata	\
	variables vector web
	${NROFF} <${MANSRC}/manpl/${file} >${WRKDIR}/${file}
	${INSTALL_DATA} ${WRKDIR}/${file} ${DOCDST}/${file}
.endfor

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
