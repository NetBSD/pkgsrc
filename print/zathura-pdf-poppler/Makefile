# $NetBSD: Makefile,v 1.43 2020/03/08 16:51:06 wiz Exp $

DISTNAME=	zathura-pdf-poppler-0.2.9
PKGREVISION=	14
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
