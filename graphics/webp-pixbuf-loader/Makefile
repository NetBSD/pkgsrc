# $NetBSD: Makefile,v 1.3 2023/08/13 00:34:47 tsutsui Exp $

DISTNAME=	webp-pixbuf-loader-0.2.4
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=aruiz/}
GITHUB_PROJECT=	${DISTNAME:S/-${PKGVERSION_NOREV}//}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/aruiz/webp-pixbuf-loader
COMMENT=	WebP Image format GdkPixbuf loader
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	pkg-config
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output
# For Darwin
MAKE_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/output

_BUILDING_GTK2= yes
.include "../../graphics/gdk-pixbuf2/loaders.mk"

.include "../../devel/meson/build.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
