# $NetBSD: Makefile,v 1.1 2015/01/22 12:51:00 jmcneill Exp $

DISTNAME=	ioquake3-raspberrypi-20150118
CATEGORIES=	games
MASTER_SITES=	http://www.invisible.ca/packages/distfiles/
EXTRACT_SUFX=	.zip

MAINTAINER=	port-arm@NetBSD.org
HOMEPAGE=	https://github.com/raspberrypi/quake3
COMMENT=	Open source Quake 3 distribution (Raspberry Pi version)
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake pkg-config
BUILD_TARGET=	release
# XXX install target does not work with debug builds
#BUILD_TARGET=	debug

ONLY_FOR_PLATFORM=	NetBSD-*-*arm*

INSTALLATION_DIRS+= lib/ioquake3

WRKSRC=	${WRKDIR}/quake3-master

MAKE_ENV+=	ARCH=rpi
MAKE_ENV+=	USE_SVN=0 USE_CURL=0 USE_OPENAL=0 USE_MUMBLE=0 USE_VOIP=0
MAKE_ENV+=	COPYDIR=${DESTDIR}${PREFIX}/lib/ioquake3

CFLAGS+=	-mfpu=vfp
CFLAGS+=	-I${PREFIX}/include -I${PREFIX}/include/interface/vcos/pthreads
CFLAGS+=	-I${PREFIX}/include/SDL
CFLAGS+=	-DVCMODS_MISC -DVCMODS_OPENGLES -DVCMODS_DEPTH -DVCMODS_REPLACETRIG
LDFLAGS+=	-Wl,-R${PREFIX}/lib -L${PREFIX}/lib
LDFLAGS+=	-lSDL -lpthread -lvchostif -lvcfiled_check -lbcm_host -lkhrn_static -lvchiq_arm -lopenmaxil -lEGL -lGLESv2 -lvcos

do-install:
	cd ${WRKSRC} && ${MAKE_ENV} ${GMAKE} copyfiles COPYDIR=${DESTDIR}${PREFIX}/lib/ioquake3

.include "../../devel/SDL/buildlink3.mk"
.include "../../misc/raspberrypi-userland/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
