# $NetBSD: Makefile,v 1.25 2004/12/03 15:14:59 wiz Exp $

DISTNAME=	pl230src
PKGNAME=	ploticus-2.30
CATEGORIES=	graphics
MASTER_SITES=	http://ploticus.sourceforge.net/download/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://ploticus.sourceforge.net/
COMMENT=	Versatile data visualization engine

WRKSRC=			${WRKDIR}/${DISTNAME}/src
NO_CONFIGURE=		yes
USE_X11=		yes
USE_BUILDLINK3=		yes

BUILD_TARGET=	ploticus
MANSRC=		${WRKDIR}/${DISTNAME}/man
PREFABSRC=	${WRKDIR}/${DISTNAME}/prefabs

DOCDST=		${PREFIX}/share/doc/ploticus
PREFABDST=	${PREFIX}/share/ploticus
NROFF?=		nroff -mandoc

MAKE_ENV+=	XLIBS="-L${X11BASE}/lib -lX11"
MAKE_ENV+=	XINCLUDEDIR="-I${X11BASE}/include"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pl ${PREFIX}/bin/pl
	${INSTALL_DATA_DIR} ${PREFABDST}
.for file in chunk_logtics chunk_xaxis lines.pl stack.pl chron.pl	\
	chunk_read chunk_yaxis multidist.pl vbars.pl chunk_area		\
	chunk_setstd dist.pl pie.pl chunk_logstubs chunk_title draw.pl	\
	scat.pl
	${INSTALL_DATA} ${PREFABSRC}/${file} ${PREFABDST}/${file}
.endfor

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
#.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
