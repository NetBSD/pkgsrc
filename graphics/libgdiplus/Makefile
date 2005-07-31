# $NetBSD: Makefile,v 1.21 2005/07/31 19:23:00 recht Exp $
#

DISTNAME=	libgdiplus-1.1.8
CATEGORIES=	graphics
MASTER_SITES=	http://go-mono.com/sources/libgdiplus-1.1/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/
COMMENT=	Implementation of the GDI+ API

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		autoconf gmake
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	libgdiplus.pc.in
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-glitz

pre-configure:
	cd ${WRKSRC}; autoheader; autoconf

BUILDLINK_DEPENDS.freetype2+=	freetype2>=2.1.5
BUILDLINK_DEPENDS.Xft2+=	Xft2>=2.1.2
BUILDLINK_DEPENDS.Xrender+=	Xrender>=0.8

BUILDLINK_TRANSFORM+=		rm:-Werror

.include "../../devel/pkg-config/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
#.include "../../graphics/glitz/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
