# $NetBSD: Makefile,v 1.16 2000/11/16 18:25:23 wiz Exp $
#

DISTNAME=		libwmf-0.1.20
CATEGORIES=		graphics devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=wvware/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.wvware.com/libwmf.html

DEPENDS+=		freetype-lib>=1.3.1:../../graphics/freetype-lib
DEPENDS+=		png>=1.0.6:../../graphics/png

USE_X11=		YES
USE_XPM=		YES
GNU_CONFIGURE=		YES
EVAL_PREFIX+=		XPMDIR=xpm
CONFIGURE_ARGS+=	--includedir="${PREFIX}/include/libwmf"
CONFIGURE_ARGS+=	--with-png="${LOCALBASE}"
CONFIGURE_ARGS+=	--with-ttf="${LOCALBASE}"
CONFIGURE_ARGS+=	--with-xpm="${XPMDIR}"
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

CPPFLAGS+=		-I${LOCALBASE}/include			# png.h
INCLUDEDIR=		${PREFIX}/include/libwmf
HTMLDIR=		${PREFIX}/share/doc/html/libwmf
WRKSRC=			${WRKDIR}/libwmf

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
