# $NetBSD: Makefile,v 1.20 2020/11/20 18:25:07 wiz Exp $

LIBV4L_VERS=	1.20.0
DISTNAME=	v4l-utils-${LIBV4L_VERS}
CATEGORIES=	graphics
PKGNAME=	libv4l-${LIBV4L_VERS}
MASTER_SITES=	https://www.linuxtv.org/downloads/v4l-utils/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://people.atrpms.net/~hdegoede/
COMMENT=	Video4Linux userspace library
LICENSE=	gnu-gpl-v2

FORTIFY_SUPPORTED=	no
GNU_CONFIGURE=		yes
USE_GCC_RUNTIME=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

CONFIGURE_ARGS+=	--disable-libdvbv5
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--disable-v4l-utils

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "DragonFly"
NEWHEADER!=	${GREP} V4L2_SEL_TGT_CROP /usr/include/sys/videoio.h > /dev/null 2>&1 || echo "no"
.endif

.if (${OPSYS} == "NetBSD" || ${OPSYS} == "DragonFly") && !exists(/usr/include/sys/videoio.h)
PLIST.needs_videoio=	yes
INSTALLATION_DIRS+=	include/sys

pre-configure:
	${MKDIR} ${BUILDLINK_DIR}/include/sys
	cp ${FILESDIR}/videoio.h ${BUILDLINK_DIR}/include/sys

post-install:
	${INSTALL_DATA} ${FILESDIR}/videoio.h ${DESTDIR}${PREFIX}/include/sys

.elif (${OPSYS} == "NetBSD" || ${OPSYS} == "DragonFly") && ${NEWHEADER} == "no"

pre-configure:
	${MKDIR} ${BUILDLINK_DIR}/include/sys
	cp ${FILESDIR}/videoio.h ${BUILDLINK_DIR}/include/sys

.elif ${OPSYS} == "Linux" && !exists(/usr/include/linux/videodev.h)
pre-configure:
	${MKDIR} ${BUILDLINK_DIR}/include/linux
	cp ${FILESDIR}/videodev.h ${BUILDLINK_DIR}/include/linux
	${LN} -sf ${BUILDLINK_DIR}/include/linux/videodev.h \
		${BUILDLINK_DIR}/include/
	cp ${FILESDIR}/videodev2.h ${BUILDLINK_DIR}/include/linux
	${LN} -sf ${BUILDLINK_DIR}/include/linux/videodev2.h \
		${BUILDLINK_DIR}/include/
.endif

PLIST_VARS=	needs_videoio

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang) || !empty(CC_VERSION:Mgcc-[6-9]*)
CPPFLAGS.SunOS+=	-D_XOPEN_SOURCE=600
.else
CPPFLAGS.SunOS+=	-D_XOPEN_SOURCE=500
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
