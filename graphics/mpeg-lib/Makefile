# $NetBSD: Makefile,v 1.10 1998/07/26 14:36:43 tv Exp $

DISTNAME=	mpeg_lib-1.2.1
PKGNAME=	mpeg-1.2.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.mni.mcgill.ca/pub/mpeg/ \
		ftp://ftp.fu-berlin.de/unix/X11/graphics/gimp/libs/ \
		ftp://ftp.gimp.org/pub/gimp/libs/

MAINTAINER=	tron@netbsd.org

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	libmpeg.la

WRKSRC=		${WRKDIR}/mpeg_lib

do-install:
	cd ${WRKSRC} && \
		${LIBTOOL} ${INSTALL_DATA} libmpeg.la ${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/mpeg.h ${PREFIX}/include/

.include "../../mk/bsd.pkg.mk"
