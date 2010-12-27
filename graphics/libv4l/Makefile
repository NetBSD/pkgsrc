# $NetBSD: Makefile,v 1.6 2010/12/27 04:58:10 obache Exp $

DISTNAME=	libv4l-0.4.3
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://people.atrpms.net/~hdegoede/

MAINTAINER=	tech-multimedia@NetBSD.org
HOMEPAGE=	http://people.atrpms.net/~hdegoede/
COMMENT=	Video4Linux userspace library

PKG_DESTDIR_SUPPORT=	user-destdir

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
	${MKDIR} ${BUILDLINK_DIR}/include
	cp ${FILESDIR}/videodev.h ${BUILDLINK_DIR}/include/videodev.h
.endif

PLIST_VARS=	needs_videoio

.include "../../mk/bsd.pkg.mk"
