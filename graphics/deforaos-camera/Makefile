# $NetBSD: Makefile,v 1.7 2014/05/05 00:47:55 ryoon Exp $
#

DISTNAME=	Camera-0.0.1
PKGNAME=	deforaos-camera-0.0.1
PKGREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://www.defora.org/os/download/download/4284/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop camera
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_TOOLS+=	xgettext

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
AUTO_MKDIRS=	yes

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/camera.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/camera.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/gallery.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/gallery.1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/man1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man

.include "options.mk"

.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
