# $NetBSD: Makefile,v 1.49 2018/09/02 21:32:43 wiz Exp $

DISTNAME=	PDFViewer-0.0.2
PKGNAME=	deforaos-pdfviewer-0.0.2
PKGREVISION=	22
CATEGORIES=	print
MASTER_SITES=	https://www.defora.org/os/download/download/4431/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.defora.org/
COMMENT=	DeforaOS desktop PDF viewer

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

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
