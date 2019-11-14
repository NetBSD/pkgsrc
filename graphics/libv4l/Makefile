# $NetBSD: Makefile,v 1.18 2019/11/14 15:25:59 wiz Exp $

DISTNAME=	libv4l-0.4.3
PKGREVISION=	4
CATEGORIES=	graphics
#MASTER_SITES=	http://people.atrpms.net/~hdegoede/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://people.atrpms.net/~hdegoede/
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

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang) || !empty(CC_VERSION:Mgcc-[6-9]*)
CPPFLAGS.SunOS+=	-D_XOPEN_SOURCE=600
.else
CPPFLAGS.SunOS+=	-D_XOPEN_SOURCE=500
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
