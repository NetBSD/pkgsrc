# $NetBSD: Makefile,v 1.26 2018/08/16 13:56:27 wiz Exp $

DISTNAME=	zathura-pdf-poppler-0.2.8
PKGREVISION=	8
CATEGORIES=	print
MASTER_SITES=	https://pwmt.org/projects/zathura/plugins/download/

MAINTAINER=	degroote@NetBSD.org
HOMEPAGE=	https://pwmt.org/projects/zathura/
COMMENT=	Add PDF support to zathura using poppler rendering engine
LICENSE=	zlib

CONFLICTS+=	zathura-pdf-mupdf-[0-9]*

USE_TOOLS+=	pkg-config gmake
USE_LIBTOOL=	yes

.include "../../graphics/cairo/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../print/zathura/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
