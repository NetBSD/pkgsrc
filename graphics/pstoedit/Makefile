# $NetBSD: Makefile,v 1.29 2005/08/12 19:29:29 drochner Exp $

DISTNAME=	pstoedit-3.41
CATEGORIES=	converters graphics print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pstoedit/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.pstoedit.net/
COMMENT=	Convert PostScript / PDF into various vector graphic formats

RESTRICTED?=	"The author writes: If you include this program on a CDROM, please send me a copy of the CD, or if it goes with a book, of the book."
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_LIBTOOL=	yes
USE_LANGUAGES=	c++
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CXXFLAGS="${CFLAGS} -Dunix"
CONFIGURE_ENV+=	GS=${LOCALBASE}/bin/gs
CONFIGURE_ARGS+=--datadir=${PREFIX}/share
CONFIGURE_ARGS+=--libdir=${PREFIX}/lib/pstoedit	# plugin dir -- unused for now
BUILD_TARGET=

LIBS.SunOS+=	-ldl

DOCDIR=		${PREFIX}/share/doc/pstoedit
HTMLDIR=	${PREFIX}/share/doc/html/pstoedit
DOCSRC=		${WRKSRC}/doc

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}
	for f in ${DOCSRC}/*.htm; do			\
	   ${INSTALL_DATA} $${f}	${HTMLDIR};	\
	done
	${INSTALL_DATA} ${DOCSRC}/readme.txt	${DOCDIR}

.include "../../graphics/plotutils/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
#.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
