# $NetBSD: Makefile,v 1.17 2003/10/11 13:40:19 grant Exp $
#

DISTNAME=	graphviz-1.10
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.graphviz.org/pub/graphviz/ARCHIVE/

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://www.graphviz.org/
COMMENT=	Graph Drawing Programs from AT&T Research and Lucent Bell Labs

LICENSE=	graphviz-license

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
USE_X11=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
XAW_TYPE=		standard

CONFIGURE_ENV+=		TCLCONFIG=${BUILDLINK_PREFIX.tcl}/lib/tclConfig.sh
CONFIGURE_ENV+=		TKCONFIG=${BUILDLINK_PREFIX.tk}/lib/tkConfig.sh
CONFIGURE_ENV+=		X11PREFIX=${X11PREFIX} X11BASE=${X11BASE}
CONFIGURE_ENV+=		BUILDLINK_PREFIX_TCL=${BUILDLINK_PREFIX.tcl}
CONFIGURE_ENV+=		BUILDLINK_PREFIX_TK=${BUILDLINK_PREFIX.tk}

CONFIGURE_ARGS+=	--with-zincludedir=${BUILDLINK_PREFIX.zlib}/include
CONFIGURE_ARGS+=	--with-zlibdir=${BUILDLINK_PREFIX.zlib}/lib
CONFIGURE_ARGS+=	--with-iconvincludedir=${BUILDLINK_PREFIX.iconv}/include
CONFIGURE_ARGS+=	--with-iconvlibdir=${BUILDLINK_PREFIX.iconv}/lib
CONFIGURE_ARGS+=	--with-jpegincludedir=${BUILDLINK_PREFIX.jpeg}/include
CONFIGURE_ARGS+=	--with-jpeglibdir=${BUILDLINK_PREFIX.jpeg}/lib
CONFIGURE_ARGS+=	--with-expatincludedir=${BUILDLINK_PREFIX.expat}/include
CONFIGURE_ARGS+=	--with-expatlibdir=${BUILDLINK_PREFIX.expat}/lib
# curl support... Not yet
#CONFIGURE_ARGS+=	--with-curlincludedir=${BUILDLINK_PREFIX.curl}/include
#CONFIGURE_ARGS+=	--with-curllibdir=${BUILDLINK_PREFIX.curl}/lib

# Dynagraph is left out for now
#UNLIMIT_RESOURCES=	datasize stacksize memorysize
CONFIGURE_ARGS+=	--without-dynagraph

post-configure:
	${TOUCH} ${WRKSRC}/configure.in ${WRKSRC}/aclocal.m4 \
		${WRKSRC}/stamp-h.in ${WRKSRC}/configure \
		${WRKSRC}/config.status ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/graphviz
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/graphviz
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/graphviz/info
.for __f__ in Dot.ref dotguide.pdf dottyguide.pdf leftyguide.pdf	\
		 neatoguide.pdf
	${INSTALL_DATA} ${WRKSRC}/doc/${__f__} ${PREFIX}/share/doc/graphviz
.endfor
.for __f__ in FAQ.html tcldot.html
	${INSTALL_DATA} ${WRKSRC}/doc/${__f__} ${PREFIX}/share/doc/html/graphviz
.endfor
.if 0	# dynagraph "disabled"
	${INSTALL_DATA} ${WRKSRC}/dynagraph/dynagraph.html ${PREFIX}/share/doc/html/graphviz
.endif
	for f in ${WRKSRC}/doc/info/*.html ${WRKSRC}/doc/info/*.gif; do	\
		${INSTALL_DATA} $${f} ${PREFIX}/share/doc/html/graphviz/info; \
	done
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/graphviz
	${INSTALL_DATA} ${WRKSRC}/MINTERMS.txt ${PREFIX}/share/doc/graphviz

.include "../../graphics/png/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../x11/tk/buildlink2.mk"
# .include "../../www/curl/buildlink2.mk"
.include "../../textproc/expat/buildlink2.mk"
.include "../../mk/xaw.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
