# $NetBSD: Makefile,v 1.13 2016/09/09 21:07:23 richard Exp $

DISTNAME=	libv4l-0.4.3
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://people.atrpms.net/~hdegoede/

MAINTAINER=	tech-multimedia@NetBSD.org
HOMEPAGE=	http://people.atrpms.net/~hdegoede/
COMMENT=	Video4Linux userspace library
LICENSE=	gnu-gpl-v2

USE_GCC_RUNTIME=	yes

USE_TOOLS+=	gmake

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "NetBSD" || ${OPSYS} == "DragonFly") \
	&& !exists(/usr/include/sys/videoio.h)
PLIST.needs_videoio=	yes
INSTALLATION_DIRS+=	include/sys

pre-configure:
	${MKDIR} ${BUILDLINK_DIR}/include/sys
	cp ${FILESDIR}/videoio.h ${BUILDLINK_DIR}/include/sys
	cp ${FILESDIR}/videodev.h ${BUILDLINK_DIR}/include

post-install:
	${INSTALL_DATA} ${FILESDIR}/videoio.h ${DESTDIR}${PREFIX}/include/sys
.elif !exists(/usr/include/linux/videodev.h)
pre-configure:
	${MKDIR} ${BUILDLINK_DIR}/include/linux
	cp ${FILESDIR}/videodev.h ${BUILDLINK_DIR}/include/linux
	${LN} -sf ${BUILDLINK_DIR}/include/linux/videodev.h \
		${BUILDLINK_DIR}/include/
.endif

PLIST_VARS=	needs_videoio

CPPFLAGS.SunOS+=	-D_XOPEN_SOURCE=500

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
