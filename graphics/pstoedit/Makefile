# $NetBSD: Makefile,v 1.38 2008/09/10 13:59:43 gdt Exp $

DISTNAME=	pstoedit-3.41
PKGREVISION=	2
CATEGORIES=	converters graphics print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pstoedit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pstoedit.net/
COMMENT=	Convert PostScript / PDF into various vector graphic formats

PKG_DESTDIR_SUPPORT=	user-destdir

# man page indicates that there are many licenses and one has to read all
# the source files
LICENSE=	unclear-license
RESTRICTED=	license is unclear
RESTRICTED?=	"The author writes: If you include this program on a CDROM, please send me a copy of the CD, or if it goes with a book, of the book."
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

# XXX Avoid hard dependency on Ghostscript
#USE_TOOLS+=	gs:run

USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CXXFLAGS="${CFLAGS} -Dunix"
CONFIGURE_ENV+=	ac_cv_path_GS=${LOCALBASE}/bin/gs
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

.include "../../graphics/plotutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
