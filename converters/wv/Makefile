# $NetBSD: Makefile,v 1.3 2000/08/05 02:39:18 jlam Exp $
#

DISTNAME=		wv-0.5.43
CATEGORIES=		converters
MASTER_SITES=		http://www.csn.ul.ie/~caolan/publink/mswordview/development/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.wvWare.com/

BUILD_DEPENDS+=		autoconf:../../devel/autoconf
DEPENDS+=		libwmf-0.1.17nb1:../../graphics/libwmf
DEPENDS+=		ImageMagick-*:../../graphics/ImageMagick

# not detected by configure, causes conflicts with the one coming with wv
CONFLICTS+=		libgetopt-*

USE_X11=		# defined

WRKSRC=			${WRKDIR}/wv
GNU_CONFIGURE=		# defined

EVAL_PREFIX=		XPMDIR=xpm
CONFIGURE_ARGS+=	--with-Magick=${LOCALBASE}
CONFIGURE_ARGS+=	--with-png=${LOCALBASE}
CONFIGURE_ARGS+=	--with-ttf=${LOCALBASE}
CONFIGURE_ARGS+=	--with-wmf=${LOCALBASE}
CONFIGURE_ARGS+=	--with-xpm=${XPMDIR}
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
MAKE_ENV+=		RM="${RM}"

CPPFLAGS+=		-I${LOCALBASE}/include		# png.h

pre-patch:
	${FIND} ${WRKSRC} -name "*.orig" -exec ${RM} {} \;

pre-configure:
	cd ${WRKSRC} && autoconf

post-install:
	${TOUCH} ${PREFIX}/share/wv/ttf/.directory
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/wv
	cd ${WRKSRC} && ${INSTALL_DATA} COPYING CREDITS INSTALL KNOWN-BUGS \
		README Documentation/XML_Tags ${PREFIX}/share/doc/wv

.include "../../mk/bsd.pkg.mk"
