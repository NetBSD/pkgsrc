# $NetBSD: Makefile,v 1.59.2.1 2012/10/03 12:08:08 spz Exp $

DISTNAME=	libgdiplus-2.10
PKGREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/libgdiplus/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/
COMMENT=	Implementation of the GDI+ API

PKG_DESTDIR_SUPPORT=	user-destdir

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
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/giflib.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
