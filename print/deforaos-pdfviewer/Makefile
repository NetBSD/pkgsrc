# $NetBSD: Makefile,v 1.2 2013/01/26 21:38:40 adam Exp $
#

DISTNAME=	PDFViewer-0.0.1
PKGNAME=	deforaos-pdfviewer-0.0.1
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://www.defora.org/os/download/download/3686/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop PDF viewer

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}

.include "options.mk"

.include "../../x11/gtk2/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
