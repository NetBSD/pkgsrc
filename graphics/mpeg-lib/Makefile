# $NetBSD: Makefile,v 1.8 1998/07/14 19:29:27 tv Exp $

DISTNAME=	mpeg_lib-1.2.1
PKGNAME=	mpeg-1.2.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.mni.mcgill.ca/pub/mpeg/ \
		ftp://ftp.fu-berlin.de/unix/X11/graphics/gimp/libs/ \
		ftp://ftp.gimp.org/pub/gimp/libs/

MAINTAINER=	tron@netbsd.org

BUILD_DEPENDS=	${PREFIX}/bin/libtool:../../devel/libtool

GNU_CONFIGURE=	yes
MAKE_ENV=	LIBTOOL=${PREFIX}/bin/libtool

WRKSRC=		${WRKDIR}/mpeg_lib

do-install:
	cd ${WRKSRC} && \
		${PREFIX}/bin/libtool --mode=install ${INSTALL_DATA} \
			libmpeg.la ${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/mpeg.h ${PREFIX}/include/

.include "../../mk/bsd.pkg.mk"
