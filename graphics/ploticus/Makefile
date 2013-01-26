# $NetBSD: Makefile,v 1.45 2013/01/26 21:37:57 adam Exp $

DISTNAME=	pl231src
PKGNAME=	ploticus-2.31pl4
PKGREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	http://ploticus.sourceforge.net/download/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://ploticus.sourceforge.net/
COMMENT=	Versatile data visualization engine

WRKSRC=			${WRKDIR}/${DISTNAME}/src
NO_CONFIGURE=		yes

BUILD_TARGET=	ploticus
MANSRC=		${WRKDIR}/${DISTNAME}/man
PREFABSRC=	${WRKDIR}/${DISTNAME}/prefabs

DOCDST=		${PREFIX}/share/doc/ploticus
PREFABDST=	${PREFIX}/share/ploticus

MAKE_ENV+=	XLIBS="-L${X11BASE}/lib -lX11"
MAKE_ENV+=	XINCLUDEDIR="-I${X11BASE}/include"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pl ${DESTDIR}${PREFIX}/bin/pl
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFABDST}
.for file in \
	README chron.pl chunk_area chunk_chronfilter chunk_doheatmap \
	chunk_heatmapfilter chunk_logstubs chunk_logtics chunk_read \
	chunk_setstd chunk_stackareafilter chunk_title chunk_vdistfilter \
	chunk_xaxis chunk_yaxis compare.pl cumufrac.pl dist.pl draw.pl \
	heatmap.pl lines.pl multidist.pl pie.pl processdata.pl scat.pl \
	stack.pl vbars.pl vdist.pl
	${INSTALL_DATA} ${PREFABSRC}/${file} ${DESTDIR}${PREFABDST}/${file}
.endfor

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
