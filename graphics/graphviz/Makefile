# $NetBSD: Makefile,v 1.23 2004/10/03 00:14:52 tv Exp $
#

DISTNAME=	graphviz-1.12
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.graphviz.org/pub/graphviz/ARCHIVE/

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://www.graphviz.org/
COMMENT=	Graph Drawing Programs from AT&T Research and Lucent Bell Labs

LICENSE=	graphviz-license

DIST_SUBDIR=	${PKGNAME_NOREV}

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
USE_X11=		yes
XAW_TYPE=		standard

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ENV+=		TCLCONFIG=${TCLCONFIG_SH}
CONFIGURE_ENV+=		TKCONFIG=${TKCONFIG_SH}
CONFIGURE_ENV+=		X11PREFIX=${X11PREFIX} X11BASE=${X11BASE}

CONFIGURE_ARGS+=	--with-zincludedir=${BUILDLINK_PREFIX.zlib}/include
CONFIGURE_ARGS+=	--with-zlibdir=${BUILDLINK_PREFIX.zlib}/lib
CONFIGURE_ARGS+=	--with-jpegincludedir=${BUILDLINK_PREFIX.jpeg}/include
CONFIGURE_ARGS+=	--with-jpeglibdir=${BUILDLINK_PREFIX.jpeg}/lib
CONFIGURE_ARGS+=	--with-expatincludedir=${BUILDLINK_PREFIX.expat}/include
CONFIGURE_ARGS+=	--with-expatlibdir=${BUILDLINK_PREFIX.expat}/lib
CONFIGURE_ARGS+=	--with-freetypeincludedir=${BUILDLINK_PREFIX.freetype2}/include
CONFIGURE_ARGS+=	--with-freetypelibdir=${BUILDLINK_PREFIX.freetype2}/lib

# Dynagraph is left out for now
#UNLIMIT_RESOURCES=	datasize stacksize memorysize
CONFIGURE_ARGS+=	--without-dynagraph

post-extract:
	${FIND} ${WRKSRC} -name "*.orig" -print | ${XARGS} ${RM} -f

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

.include "../../graphics/png/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
# .include "../../www/curl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
