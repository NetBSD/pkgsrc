# $NetBSD: Makefile,v 1.39 2019/10/07 09:28:13 prlw1 Exp $

DISTNAME=	zathura-pdf-poppler-0.2.9
PKGREVISION=	10
CATEGORIES=	print
MASTER_SITES=	https://pwmt.org/projects/zathura/plugins/download/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	degroote@NetBSD.org
HOMEPAGE=	https://pwmt.org/projects/zathura/
COMMENT=	Add PDF support to zathura using poppler rendering engine
LICENSE=	zlib

USE_TOOLS+=	pkg-config

.include "../../devel/meson/build.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../print/zathura/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
