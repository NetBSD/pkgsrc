# $NetBSD: Makefile,v 1.4 2002/03/21 08:47:06 seb Exp $
#

DISTNAME=	graphviz-1.8.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.research.att.com/sw/tools/graphviz/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.research.att.com/sw/tools/graphviz/
COMMENT=	Graph Drawing Programs from AT&T Research and Lucent Bell Labs

LICENSE=	graphviz-license

GNU_CONFIGURE=		YES
USE_BUILDLINK_ONLY=	YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ENV+=		TCLCONFIG=${BUILDLINK_DIR}/lib/tclConfig.sh
CONFIGURE_ENV+=		TKCONFIG=${BUILDLINK_DIR}/lib/tkConfig.sh
CONFIGURE_ENV+=		X11PREFIX=${X11PREFIX} X11BASE=${X11BASE}

CONFIGURE_ARGS+=	--with-extraincludedir=${BUILDLINK_DIR}/include
CONFIGURE_ARGS+=	--with-extralibdir=${BUILDLINK_DIR}/lib

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

.include "../../devel/zlib/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/freetype2/buildlink.mk"
.include "../../x11/tk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/xaw.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
