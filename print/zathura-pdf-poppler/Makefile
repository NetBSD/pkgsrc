# $NetBSD: Makefile,v 1.1 2016/02/14 14:03:09 leot Exp $
#

DISTNAME=	zathura-pdf-poppler-0.2.6
CATEGORIES=	print
MASTER_SITES=	http://pwmt.org/projects/zathura/plugins/download/

MAINTAINER=	degroote@NetBSD.org
HOMEPAGE=	http://pwmt.org/projects/zathura/
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
