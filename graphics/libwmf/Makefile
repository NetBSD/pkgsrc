# $NetBSD: Makefile,v 1.10 2000/08/04 22:07:21 jlam Exp $
#

DISTNAME=		libwmf-0.1.17
CATEGORIES=		graphics devel
MASTER_SITES=		http://www.csn.ul.ie/~caolan/publink/libwmf/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.csn.ul.ie/~caolan/docs/libwmf.html

BUILD_DEPENDS+=		autoreconf:../../devel/autoconf
DEPENDS+=		freetype-lib>=1.3.1:../../graphics/freetype-lib
DEPENDS+=		png>=1.0.6:../../graphics/png
DEPENDS+=		xpm-3.4k:../../graphics/xpm

# uses own gd, which has some extra functionality
CONFLICTS+=		gd-1.7.3:../../graphics/gd

WRKSRC=			${WRKDIR}/libwmf
USE_X11=		YES

GNU_CONFIGURE=		YES

EVAL_PREFIX+=		XPMDIR=xpm
CONFIGURE_ARGS+=	--with-png="${LOCALBASE}"
CONFIGURE_ARGS+=	--with-ttf="${LOCALBASE}"
CONFIGURE_ARGS+=	--with-xpm="${XPMDIR}"
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

CPPFLAGS+=		-I${LOCALBASE}/include/freetype		# freetype.h
CPPFLAGS+=		-I${LOCALBASE}/include			# png.h
CPPFLAGS+=		-I${XPMDIR}/include			# xpm.h

pre-configure:
	cd ${WRKSRC} && autoreconf

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
