# $NetBSD: Makefile,v 1.7 2000/11/11 17:49:24 tron Exp $
#

DISTNAME=		wv-0.6.0
CATEGORIES=		converters
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=wvware/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.wvWare.com/

DEPENDS+=		libwmf-0.1.17nb1:../../graphics/libwmf
DEPENDS+=		ImageMagick>=5.2.2:../../graphics/ImageMagick

# not detected by configure, causes conflicts with the one coming with wv
CONFLICTS+=		libgetopt-*

USE_X11=		YES
USE_XPM=		YES

WRKSRC=			${WRKDIR}/wv
GNU_CONFIGURE=		YES

EVAL_PREFIX=		XPMDIR=xpm
CONFIGURE_ARGS+=	--with-Magick=${LOCALBASE}
CONFIGURE_ARGS+=	--with-png=${LOCALBASE}
CONFIGURE_ARGS+=	--with-ttf=${LOCALBASE}
CONFIGURE_ARGS+=	--with-wmf=${LOCALBASE}
CONFIGURE_ARGS+=	--with-xpm=${XPMDIR}
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
MAKE_ENV+=		RM="${RM} -f"

CPPFLAGS+=		-I${LOCALBASE}/include
CPPFLAGS+=		-I${LOCALBASE}/include/magick
CPPFLAGS+=		-I${LOCALBASE}/include/libwmf
MAKE_ENV+=		CPPFLAGS="${CPPFLAGS}"

pre-patch:
	${FIND} ${WRKSRC} -name "*.orig" -exec ${RM} {} \;

post-install:
	${TOUCH} ${PREFIX}/share/wv/ttf/.directory
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/wv
	cd ${WRKSRC} && ${INSTALL_DATA} COPYING CREDITS INSTALL KNOWN-BUGS \
		README Documentation/XML_Tags ${PREFIX}/share/doc/wv

.include "../../mk/bsd.pkg.mk"
