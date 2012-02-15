# $NetBSD: Makefile,v 1.2 2012/02/15 11:08:46 obache Exp $
#

.include "../../graphics/giflib/Makefile.common"

PKGNAME=	giflib-util-4.1.6

COMMENT=	GIF image format utility

CONFLICTS+=	libungif-[0-9]*
PKG_DESTDIR_SUPPORT=	user-destdir

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
.if ${GIFLIB_IMPLEMENTATION} == "libungif"
PKG_FAIL_REASON= "please use graphics/libungif"
.endif
.include "../../mk/bsd.pkg.mk"
