# $NetBSD: Makefile,v 1.48 2010/04/09 01:38:32 obache Exp $

DISTNAME=	pstoedit-3.45
PKGREVISION=	7
CATEGORIES=	converters graphics print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pstoedit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pstoedit.net/
COMMENT=	Convert PostScript / PDF into various vector graphic formats
LICENSE=	unclear-license

# man page indicates that there are many licenses and one has to read all
# the source files
RESTRICTED=	license is unclear
RESTRICTED?=	"The author writes: If you include this program on a CDROM, please send me a copy of the CD, or if it goes with a book, of the book."
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

USE_TOOLS+=	gs:run

USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CXXFLAGS="${CFLAGS} -Dunix"
CONFIGURE_ENV+=	ac_cv_path_GS=${LOCALBASE}/bin/gs

# needs libEMF which has build problems on alpha and probably
# other 64-bit systems
CONFIGURE_ARGS+=--without-emf

CONFIGURE_ARGS+=--datadir=${PREFIX}/share
CONFIGURE_ARGS+=--libdir=${PREFIX}/lib/pstoedit	# plugin dir -- unused for now
BUILD_TARGET=

LIBS.SunOS+=	-ldl

DOCDIR=		${PREFIX}/share/doc/pstoedit
HTMLDIR=	${PREFIX}/share/doc/html/pstoedit
DOCSRC=		${WRKSRC}/doc

INSTALLATION_DIRS=	${DOCDIR} ${HTMLDIR}

post-install:
	for f in ${DOCSRC}/*.htm; do			\
	   ${INSTALL_DATA} $${f}	${DESTDIR}${HTMLDIR};	\
	done
	${INSTALL_DATA} ${DOCSRC}/readme.txt	${DESTDIR}${DOCDIR}

.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../graphics/plotutils/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../..//multimedia/ming/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
