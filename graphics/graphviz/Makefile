# $NetBSD: Makefile,v 1.6 2002/08/28 13:49:35 seb Exp $
#

DISTNAME=	graphviz-1.8.9
CATEGORIES=	graphics
MASTER_SITES=	http://www.graphviz.org/pub/graphviz/ARCHIVE/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.graphviz.org/
COMMENT=	Graph Drawing Programs from AT&T Research and Lucent Bell Labs

LICENSE=	graphviz-license

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
USE_X11=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ENV+=		TCLCONFIG=${BUILDLINK_PREFIX.tcl}/lib/tclConfig.sh
CONFIGURE_ENV+=		TKCONFIG=${BUILDLINK_PREFIX.tk}/lib/tkConfig.sh
CONFIGURE_ENV+=		X11PREFIX=${X11PREFIX} X11BASE=${X11BASE}
CONFIGURE_ENV+=		BUILDLINK_PREFIX_TCL=${BUILDLINK_PREFIX.tcl}
CONFIGURE_ENV+=		BUILDLINK_PREFIX_TK=${BUILDLINK_PREFIX.tk}

# Not yet...
#CONFIGURE_ARGS+=	--with-dynagraph
#UNLIMIT_RESOURCES=	datasize stacksize memorysize

# clean up a bit to help package maintainer produce patch files
post-extract:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${FIND} ${WRKSRC} -type f -name "*.orig" | ${XARGS} ${RM}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/graphviz
.for __f__ in Dot.ref FAQ.html dotguide.pdf dottyguide.pdf gd.html \
		leftyguide.pdf neatoguide.pdf tcldot.html
	${INSTALL_DATA} ${WRKSRC}/doc/${__f__} ${PREFIX}/share/doc/graphviz
.endfor
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/graphviz
	${INSTALL_DATA} ${WRKSRC}/MINTERMS.txt ${PREFIX}/share/doc/graphviz

.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../x11/tk/buildlink2.mk"
.include "../../mk/xaw.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
