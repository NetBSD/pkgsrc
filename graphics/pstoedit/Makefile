# $NetBSD: Makefile,v 1.1.1.1 2000/07/18 07:46:40 itohy Exp $

DISTNAME=	pstoedit_3_20
PKGNAME=	pstoedit-3.20
CATEGORIES=	converters graphics print
MASTER_SITES=	http://www.geocities.com/SiliconValley/Network/1958/pstoedit/
EXTRACT_SUFX=	.zip

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.geocities.com/SiliconValley/Network/1958/pstoedit/

# Requires C++ support of plotutils.
DEPENDS+=	plotutils-2.3.0:../../graphics/plotutils
# Any ghostscript pkg will probably do, if not a font pkg.
DEPENDS+=	ghostscript-[^f]*:../../print/ghostscript

NO_CDROM+=	"The author writes: If you include this program on a CDROM, please send me a copy of the CD, or if it goes with a book, of the book."

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
	${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${DOCSRC}/*.htm		${DOCDIR}
	${INSTALL_DATA} ${DOCSRC}/readme.txt	${DOCDIR}

.include "../../mk/bsd.pkg.mk"
