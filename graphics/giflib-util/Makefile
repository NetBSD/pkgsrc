# $NetBSD: Makefile,v 1.1 2011/09/06 18:45:46 drochner Exp $
#

DISTNAME=	giflib-4.1.6
PKGNAME=	giflib-util-4.1.6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=giflib/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://giflib.sourceforge.net/
COMMENT=	GIF image format library
LICENSE=	mit

PATCHDIR=	${.CURDIR}/../../graphics/giflib/patches
DISTINFO_FILE=	${.CURDIR}/../../graphics/giflib/distinfo

CONFLICTS+=	libungif-[0-9]*
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	perl:run
REPLACE_PERL+=	util/gifburst

INSTALL_DIRS+=	util doc
HTMLDIR=	${PREFIX}/share/doc/html/giflib

post-patch:
	${RM} ${WRKSRC}/doc/gif2x11.html

do-build:
	(cd ${WRKSRC}/lib && ${SETENV} ${BUILD_ENV} ${MAKE} libgetarg.a)
	(cd ${WRKSRC}/util && ${SETENV} ${BUILD_ENV} ${MAKE})
	(cd ${WRKSRC}/doc && ${SETENV} ${BUILD_ENV} ${MAKE})

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${HTMLDIR}
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.html *.txt *.png ${DESTDIR}${HTMLDIR}

.include "../../mk/giflib.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
