# $NetBSD: Makefile,v 1.2 2000/02/29 06:43:00 jlam Exp $
#

DISTNAME=		libwmf-0.1.17
CATEGORIES=		graphics devel
MASTER_SITES=		http://www.csn.ul.ie/~caolan/publink/libwmf/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.csn.ul.ie/~caolan/docs/libwmf.html

BUILD_DEPENDS+=		${LOCALBASE}/bin/autoconf:../../devel/autoconf
DEPENDS+=		freetype-*:../../graphics/freetype
DEPENDS+=		png>=1.0.3:../../graphics/png
DEPENDS+=		xpm-3.4k:../../graphics/xpm

# uses own gd, which has some extra functionality
CONFLICTS+=		gd-1.7.3:../../graphics/gd

WRKSRC=			${WRKDIR}/libwmf
USE_X11=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-png="${LOCALBASE}"
CONFIGURE_ARGS+=	--with-ttf="${LOCALBASE}"
CONFIGURE_ARGS+=	--with-xpm="${X11BASE}"
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
CPPFLAGS+=		-I${LOCALBASE}/include -I${X11BASE}/include

pre-configure:
	cd ${WRKSRC}; ${LOCALBASE}/bin/autoconf

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
