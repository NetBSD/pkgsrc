# $NetBSD: Makefile,v 1.27 2022/08/11 05:08:40 gutteridge Exp $
#

DISTNAME=	Camera-0.3.0
PKGNAME=	deforaos-camera-0.3.0
PKGREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	https://ftp.defora.org/pub/DeforaOS/Apps/Desktop/src/Camera/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.defora.org/
COMMENT=	DeforaOS desktop camera
LICENSE=	2-clause-bsd

USE_TOOLS+=	pkg-config
USE_TOOLS+=	xgettext

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
AUTO_MKDIRS=	yes

.include "../../mk/bsd.prefs.mk"

.if ${PKGMANDIR} != "share/man"
post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/camera.html ${DESTDIR}${PREFIX}/${PKGMANDIR}/html1/camera.html
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/gallery.html ${DESTDIR}${PREFIX}/${PKGMANDIR}/html1/gallery.html
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/camera.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/camera.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/gallery.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/gallery.1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/html1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/man1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man
.endif

.include "options.mk"

.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
