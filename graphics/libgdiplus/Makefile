# $NetBSD: Makefile,v 1.88 2021/12/08 16:02:11 adam Exp $

DISTNAME=	libgdiplus-6.1
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://download.mono-project.com/sources/libgdiplus/

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	https://www.mono-project.com/
COMMENT=	Implementation of the GDI+ API
LICENSE=	mit

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		autoconf gmake pkg-config
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
PKGCONFIG_OVERRIDE+=	libgdiplus.pc.in
PKGCONFIG_OVERRIDE+=	cairo/src/cairo.pc.in
PKGCONFIG_OVERRIDE+=	cairo/src/cairo-backend.pc.in
GNU_CONFIGURE=		yes

BUILDLINK_TRANSFORM+=		rm:-Werror

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
