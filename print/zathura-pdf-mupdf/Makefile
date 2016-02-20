# $NetBSD: Makefile,v 1.3 2016/02/20 17:30:21 leot Exp $
#

DISTNAME=	zathura-pdf-mupdf-0.3.0
CATEGORIES=	print
MASTER_SITES=	http://pwmt.org/projects/zathura/plugins/download/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	http://pwmt.org/projects/zathura-pdf-mupdf/
COMMENT=	Add PDF support to zathura using mupdf rendering engine
LICENSE=	zlib

CONFLICTS+=	zathura-pdf-poppler-[0-9]*

USE_TOOLS+=	pkg-config gmake
USE_LIBTOOL=	yes

CPPFLAGS+=	-D_XOPEN_SOURCE=600

MAKE_ENV+=	MUPDF_LIB="-lmupdf -lmujs"

.include "../../graphics/cairo/buildlink3.mk"
.include "../../print/mupdf/buildlink3.mk"
.include "../../print/zathura/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
