# $NetBSD: Makefile,v 1.25 2016/02/21 18:36:12 khorben Exp $
#

DISTNAME=	PDFViewer-0.0.2
PKGNAME=	deforaos-pdfviewer-0.0.2
CATEGORIES=	print
MASTER_SITES=	http://www.defora.org/os/download/download/4431/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop PDF viewer

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
AUTO_MKDIRS=	yes

.include "../../mk/bsd.prefs.mk"

.if ${PKGMANDIR} != "share/man"
post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/pdfviewer.html ${DESTDIR}${PREFIX}/${PKGMANDIR}/html1/pdfviewer.html
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/pdfviewer.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/pdfviewer.1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/html1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/man1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man
.endif

.include "options.mk"

.include "../../print/poppler-glib/buildlink3.mk"
.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
