# $NetBSD: Makefile,v 1.11 2002/07/02 12:52:53 wiz Exp $

DISTNAME=	pstoedit_3_31
PKGNAME=	pstoedit-3.31
CATEGORIES=	converters graphics print
MASTER_SITES=	http://home.t-online.de/home/helga.glunz/wglunz/pstoedit/
EXTRACT_SUFX=	.zip

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.pstoedit.net/
COMMENT=	Convert PostScript / PDF into various vector graphic formats

# Requires C++ support of plotutils.
DEPENDS+=	plotutils>=2.4.1:../../graphics/plotutils
# Any ghostscript pkg will probably do, if not a font pkg.
DEPENDS+=	ghostscript-[^f]*:../../print/ghostscript

RESTRICTED?=	"The author writes: If you include this program on a CDROM, please send me a copy of the CD, or if it goes with a book, of the book."
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

WRKSRC=		${WRKDIR}/pstoedit_3.31/src

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LIBTOOL="${LIBTOOL}" LIBPLOTTERLA="${X11PREFIX}/lib/libplotter.la"
CONFIGURE_ENV+=	CXXFLAGS="${CFLAGS} -Dunix"
CONFIGURE_ENV+=	LDLIBS="-Wl,-R${X11BASE}/lib -L${X11BASE}/lib"
CONFIGURE_ENV+=	AWK=${AWK} GS=${PREFIX}/bin/gs
CONFIGURE_ARGS+=--datadir=${PREFIX}/share
CONFIGURE_ARGS+=--libdir=${PREFIX}/lib/pstoedit	# plugin dir -- unused for now
ALL_TARGET=

post-extract:
	cd ${WRKSRC} && ${LN} ../config/* .

DOCDIR=		${PREFIX}/share/pstoedit/doc
DOCSRC=		${WRKSRC}/..

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${DOCSRC}/*.htm		${DOCDIR}
	${INSTALL_DATA} ${DOCSRC}/readme.txt	${DOCDIR}

.include "../../mk/bsd.pkg.mk"
