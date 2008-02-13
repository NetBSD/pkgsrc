# $NetBSD: Makefile,v 1.30 2008/02/13 14:26:23 kefren Exp $

DISTNAME=	libgdiplus-${MONO_VERSION}
CATEGORIES=	graphics
MASTER_SITES=	http://go-mono.com/sources/libgdiplus/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/
COMMENT=	Implementation of the GDI+ API

.include "../../lang/mono/Makefile.version"

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		autoconf gmake pkg-config
USE_LIBTOOL=		yes
USE_LANGUAGES+=		c c++
PKGCONFIG_OVERRIDE+=	libgdiplus.pc.in
PKGCONFIG_OVERRIDE+=	cairo/src/cairo.pc.in
PKGCONFIG_OVERRIDE+=	cairo/src/cairo-backend.pc.in
GNU_CONFIGURE=		yes

BUILDLINK_API_DEPENDS.freetype2+=	freetype2>=2.1.5
BUILDLINK_API_DEPENDS.Xft2+=	Xft2>=2.1.2
BUILDLINK_API_DEPENDS.Xrender+=	Xrender>=0.8

BUILDLINK_TRANSFORM+=		rm:-Werror

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glitz/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
