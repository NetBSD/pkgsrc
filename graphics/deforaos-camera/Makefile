# $NetBSD: Makefile,v 1.20 2018/11/14 22:21:36 kleink Exp $
#

DISTNAME=	Camera-0.2.0
PKGNAME=	deforaos-camera-0.2.0
PKGREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	https://www.defora.org/os/download/download/4419/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.defora.org/
COMMENT=	DeforaOS desktop camera
LICENSE=	gnu-gpl-v3

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
