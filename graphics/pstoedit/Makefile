# $NetBSD: Makefile,v 1.23 2004/10/03 00:14:57 tv Exp $

DISTNAME=	pstoedit_3_31
PKGNAME=	pstoedit-3.31
PKGREVISION=	2
CATEGORIES=	converters graphics print
MASTER_SITES=	http://home.t-online.de/home/helga.glunz/wglunz/pstoedit/
EXTRACT_SUFX=	.zip

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.pstoedit.net/
COMMENT=	Convert PostScript / PDF into various vector graphic formats

RESTRICTED?=	"The author writes: If you include this program on a CDROM, please send me a copy of the CD, or if it goes with a book, of the book."
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

WRKSRC=		${WRKDIR}/pstoedit_3.31/src
USE_X11=	yes
USE_LIBTOOL=	yes
USE_BUILDLINK3=	yes
USE_GCC_SHLIB=	yes
USE_LANGUAGES=	c++
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LIBTOOL="${LIBTOOL}" LIBPLOTTERLA="${X11PREFIX}/lib/libplotter.la"
CONFIGURE_ENV+=	CXXFLAGS="${CFLAGS} -Dunix"
CONFIGURE_ENV+=	LDLIBS="${X11_LDFLAGS}"
CONFIGURE_ENV+=	AWK=${AWK} GS=${LOCALBASE}/bin/gs
CONFIGURE_ARGS+=--datadir=${PREFIX}/share
CONFIGURE_ARGS+=--libdir=${PREFIX}/lib/pstoedit	# plugin dir -- unused for now
ALL_TARGET=

LIBS.SunOS+=	-ldl

post-extract:
	cd ${WRKSRC} && ${LN} ../config/* .

DOCDIR=		${PREFIX}/share/doc/pstoedit
HTMLDIR=	${PREFIX}/share/doc/html/pstoedit
DOCSRC=		${WRKSRC}/..

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}
	for f in ${DOCSRC}/*.htm; do			\
	   ${INSTALL_DATA} $${f}	${HTMLDIR};	\
	done
	${INSTALL_DATA} ${DOCSRC}/readme.txt	${DOCDIR}

.include "../../graphics/plotutils/buildlink3.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
