# $NetBSD: Makefile,v 1.7 2002/12/01 18:33:41 seb Exp $
#

DISTNAME=	graphviz-1.8.10
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

# Dynagraph is left out for now
#UNLIMIT_RESOURCES=	datasize stacksize memorysize
CONFIGURE_ARGS+=	--without-dynagraph

# clean up a bit to help package maintainer produce patch files
post-extract:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${FIND} ${WRKSRC} -type f -name "*.orig" | ${XARGS} ${RM}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/graphviz
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/graphviz
.for __f__ in Dot.ref dotguide.pdf dottyguide.pdf leftyguide.pdf \
		 neatoguide.pdf
	${INSTALL_DATA} ${WRKSRC}/doc/${__f__} ${PREFIX}/share/doc/graphviz
.endfor
.for __f__ in FAQ.html gd.html tcldot.html
	${INSTALL_DATA} ${WRKSRC}/doc/${__f__} ${PREFIX}/share/doc/html/graphviz
.endfor
.if 0	# dynagraph "disabled"
	${INSTALL_DATA} ${WRKSRC}/dynagraph/dynagraph.html ${PREFIX}/share/doc/html/graphviz	
.endif
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/graphviz
	${INSTALL_DATA} ${WRKSRC}/MINTERMS.txt ${PREFIX}/share/doc/graphviz


.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../x11/tk/buildlink2.mk"
.include "../../mk/xaw.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
