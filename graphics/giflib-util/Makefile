# $NetBSD: Makefile,v 1.5 2013/05/31 12:41:06 wiz Exp $
#

.include "../../graphics/giflib/Makefile.common"

PKGNAME=	giflib-util-4.1.6
PKGREVISION=	2

COMMENT=	GIF image format utility

CONFLICTS+=	libungif-[0-9]*

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
