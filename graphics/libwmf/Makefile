# $NetBSD: Makefile,v 1.22 2001/05/22 09:32:21 wiz Exp $
#

DISTNAME=		libwmf-0.1.21
CATEGORIES=		graphics devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=wvware/}

MAINTAINER=		kei@netbsd.org
HOMEPAGE=		http://www.wvware.com/libwmf.html
COMMENT=		library for reading and converting WMF (Windows Meta Files)

DEPENDS+=		freetype-lib>=1.3.1:../../graphics/freetype-lib
DEPENDS+=		png>=1.0.11:../../graphics/png

USE_X11=		YES
USE_XPM=		YES
GNU_CONFIGURE=		YES
EVAL_PREFIX+=		XPMDIR=xpm
CONFIGURE_ARGS+=	--includedir="${PREFIX}/include/libwmf"
CONFIGURE_ARGS+=	--with-png="${LOCALBASE}"
CONFIGURE_ARGS+=	--with-ttf="${LOCALBASE}"
CONFIGURE_ARGS+=	--with-xpm="${XPMDIR}"

INCLUDEDIR=		${PREFIX}/include/libwmf
HTMLDIR=		${PREFIX}/share/doc/html/libwmf
WRKSRC=			${WRKDIR}/libwmf

post-extract:
	${CHMOD} a-x ${WRKSRC}/doc/*.html

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
