# $NetBSD: Makefile,v 1.40 2022/08/11 05:09:14 gutteridge Exp $

DISTNAME=	Browser-0.5.5
PKGNAME=	deforaos-browser-0.5.5
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	https://ftp.defora.org/pub/DeforaOS/Apps/Desktop/src/Browser/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.defora.org/
COMMENT=	DeforaOS desktop file manager and desktop handler
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
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/browser.html ${DESTDIR}${PREFIX}/${PKGMANDIR}/html1/browser.html
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/copy.html ${DESTDIR}${PREFIX}/${PKGMANDIR}/html1/copy.html
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/delete.html ${DESTDIR}${PREFIX}/${PKGMANDIR}/html1/delete.html
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/desktop.html ${DESTDIR}${PREFIX}/${PKGMANDIR}/html1/desktop.html
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/desktopctl.html ${DESTDIR}${PREFIX}/${PKGMANDIR}/html1/desktopctl.html
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/move.html ${DESTDIR}${PREFIX}/${PKGMANDIR}/html1/move.html
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/open.html ${DESTDIR}${PREFIX}/${PKGMANDIR}/html1/open.html
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/properties.html ${DESTDIR}${PREFIX}/${PKGMANDIR}/html1/properties.html
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/view.html ${DESTDIR}${PREFIX}/${PKGMANDIR}/html1/view.html
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/browser.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/browser.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/copy.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/copy.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/delete.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/delete.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/desktop.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/desktop.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/desktopctl.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/desktopctl.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/move.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/move.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/open.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/open.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/properties.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/properties.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/view.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/view.1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/html1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/man1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man
.endif

.include "options.mk"

.include "../../devel/deforaos-configure/deforaos-configure.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk-doc+=	gtk-doc>=1.32nb9
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
