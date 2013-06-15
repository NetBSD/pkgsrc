# $NetBSD: Makefile,v 1.9 2013/06/15 12:33:38 khorben Exp $
#

DISTNAME=	Browser-0.4.12
PKGNAME=	deforaos-browser-0.4.12
CATEGORIES=	sysutils
MASTER_SITES=	http://www.defora.org/os/download/download/4294/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop file and desktop manager

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_TOOLS+=	xgettext

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
AUTO_MKDIRS=	yes

.include "../../mk/bsd.prefs.mk"

.if ${PKGMANDIR} != "share/man"
post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/browser.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/browser.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/copy.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/copy.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/delete.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/delete.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/desktop.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/desktop.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/desktopctl.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/desktopctl.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/move.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/move.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/open.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/open.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/properties.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/properties.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/view.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/view.1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/man1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man
.endif

.include "options.mk"

.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
