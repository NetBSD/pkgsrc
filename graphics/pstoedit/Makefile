# $NetBSD: Makefile,v 1.8 2002/03/13 17:37:16 fredb Exp $

DISTNAME=	pstoedit_3_20
PKGNAME=	pstoedit-3.20
PKGREVISION=	1
CATEGORIES=	converters graphics print
MASTER_SITES=	http://www.geocities.com/SiliconValley/Network/1958/pstoedit/
EXTRACT_SUFX=	.zip

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.geocities.com/SiliconValley/Network/1958/pstoedit/
COMMENT=	Convert PostScript / PDF into various vector graphic formats

# Requires C++ support of plotutils.
DEPENDS+=	plotutils>=2.4.1nb1:../../graphics/plotutils
# Any ghostscript pkg will probably do, if not a font pkg.
DEPENDS+=	ghostscript-[^f]*:../../print/ghostscript

RESTRICTED?=	"The author writes: If you include this program on a CDROM, please send me a copy of the CD, or if it goes with a book, of the book."
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

WRKSRC=		${WRKDIR}/pstoedit_3.20/src

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CXXFLAGS="${CFLAGS} -Dunix"
CONFIGURE_ENV+=	LDLIBS="-Wl,-R${X11BASE}/lib -L${X11BASE}/lib"
CONFIGURE_ENV+=	AWK=${AWK} GS=${PREFIX}/bin/gs
CONFIGURE_ARGS+=--datadir=${PREFIX}/share/pstoedit
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
