# $NetBSD: Makefile,v 1.12 2000/08/05 02:36:37 jlam Exp $
#

DISTNAME=		libwmf-0.1.17nb1
CATEGORIES=		graphics devel
MASTER_SITES=		http://www.csn.ul.ie/~caolan/publink/libwmf/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.csn.ul.ie/~caolan/docs/libwmf.html

BUILD_DEPENDS+=		autoconf:../../devel/autoconf
DEPENDS+=		freetype-lib>=1.3.1:../../graphics/freetype-lib
DEPENDS+=		png>=1.0.6:../../graphics/png
DEPENDS+=		xpm-3.4k:../../graphics/xpm

WRKSRC=			${WRKDIR}/libwmf
USE_X11=		# defined

GNU_CONFIGURE=		# defined

EVAL_PREFIX+=		XPMDIR=xpm
CONFIGURE_ARGS+=	--includedir="${PREFIX}/include/libwmf"
CONFIGURE_ARGS+=	--with-png="${LOCALBASE}"
CONFIGURE_ARGS+=	--with-ttf="${LOCALBASE}"
CONFIGURE_ARGS+=	--with-xpm="${XPMDIR}"
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

CPPFLAGS+=		-I${LOCALBASE}/include			# png.h

INCLUDEDIR=		${PREFIX}/include/libwmf
HTMLDIR=		${PREFIX}/share/doc/html/libwmf

pre-configure:
	cd ${WRKSRC} && autoconf

pre-install:
	${INSTALL_DATA_DIR} ${INCLUDEDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/myxpm.h ${INCLUDEDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}/pics
	cd ${WRKSRC}; ${INSTALL_DATA} doc/*.html doc/*.gif \
		COPYING CREDITS README ${HTMLDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} doc/pics/weave.jpg \
		${HTMLDIR}/pics

.include "../../mk/bsd.pkg.mk"
