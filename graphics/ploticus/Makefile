# $NetBSD: Makefile,v 1.13 2002/09/20 11:41:15 rh Exp $
#

DISTNAME=	plsrc204
PKGNAME=	ploticus-2.04
CATEGORIES=	graphics
MASTER_SITES=	http://ploticus.sourceforge.net/download/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://ploticus.sourceforge.net/doc/Welcome.html
COMMENT=	Versatile data visualization engine

NO_CONFIGURE=	YES
USE_X11=	YES
USE_BUILDLINK2=	YES

ALL_TARGET=	ploticus
WRKSRC=		${WRKDIR}/${DISTNAME}/src
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
.for file in Faq Problems annotate areadef attributetypes autorange	\
	axis bars breakaxis catslide cgi clickmap color commalist	\
	condex config control controlling curvefit dataformat dates	\
	defineunits drawcommands dynamic endproc fonts functions	\
	getdata gifpatent import interactive legend legenddriven	\
	legendentry limits line linedetails lineplot missingdata	\
	originaldata page paper pie plshellsql posters prefabs prepress	\
	print processdata rangebar rangesweep rect scaleunits		\
	scatterplot scripts settings shell slides specialchars sql svg	\
	symboldetails tabulate textdetails times trailer transform	\
	variables web
	${NROFF} <${MANSRC}/manpl/${file} >${WRKDIR}/${file}
	${INSTALL_DATA} ${WRKDIR}/${file} ${DOCDST}/${file}
.endfor

.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/gd/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/freetype-lib/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
