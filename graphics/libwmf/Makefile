# $NetBSD: Makefile,v 1.1.1.1 2000/02/27 18:33:38 wiz Exp $
#

DISTNAME=	libwmf-0.1.17
CATEGORIES=	graphics devel
MASTER_SITES=	http://www.csn.ul.ie/~caolan/publink/libwmf/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.csn.ul.ie/~caolan/docs/libwmf.html

DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	png>=1.0.3:../../graphics/png
DEPENDS+=	freetype-*:../../graphics/freetype

# uses own gd, which has some extra functionality
CONFLICTS+=	gd-1.7.3:../../graphics/gd

CONFIGURE_ARGS+=	--with-png="${LOCALBASE}"
CONFIGURE_ARGS+=	--with-ttf="${LOCALBASE}"

WRKSRC=		${WRKDIR}/libwmf
GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libwmf
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libwmf/pics
	cd ${WRKSRC} && ${INSTALL_DATA} doc/*.html doc/*.gif \
		COPYING CREDITS README ${PREFIX}/share/doc/libwmf
	${INSTALL_DATA} ${WRKSRC}/doc/pics/weave.jpg \
		${PREFIX}/share/doc/libwmf/pics
	${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
