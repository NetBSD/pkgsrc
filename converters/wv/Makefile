# $NetBSD: Makefile,v 1.1.1.1 2000/02/27 22:09:18 wiz Exp $
#

DISTNAME=	wv-0.5.43
CATEGORIES=	converters
MASTER_SITES=	http://www.csn.ul.ie/~caolan/publink/mswordview/development/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.wvWare.com/

DEPENDS+=	libwmf-0.1.17:../../graphics/libwmf
DEPENDS+=	ImageMagick-*:../../graphics/ImageMagick

# not detected by configure, causes conflicts with the one coming with wv
CONFLICTS+=	libgetopt-*:../../devel/libgetopt

MAKE_ENV+=	RM="${RM}"

WRKSRC=		${WRKDIR}/wv
GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/wv
	cd ${WRKSRC} && ${INSTALL_DATA} COPYING CREDITS INSTALL KNOWN-BUGS \
		README Documentation/XML_Tags ${PREFIX}/share/doc/wv

.include "../../mk/bsd.pkg.mk"
