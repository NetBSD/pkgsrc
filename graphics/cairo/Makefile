# $NetBSD: Makefile,v 1.38 2006/07/23 01:01:28 minskim Exp $

DISTNAME=	cairo-1.2.0
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/releases/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://cairographics.org/
COMMENT=	Vector graphics library with cross-device output support

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	src/cairo.pc.in src/cairo-backend.pc.in
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-atsui
CONFIGURE_ARGS+=	--disable-xcb
CONFIGURE_ARGS+=	--enable-glitz
CONFIGURE_ARGS+=	--enable-pdf
CONFIGURE_ARGS+=	--enable-ps
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

.if exists(/System/Library/Frameworks/Carbon.framework)
CONFIGURE_ARGS+=	--enable-quartz
PLIST_SUBST+=		QUARTZ=
.else
PLIST_SUBST+=		QUARTZ="@comment "
.endif

BUILDLINK_API_DEPENDS.freetype2+=	freetype2>=2.1.5
BUILDLINK_API_DEPENDS.Xft2+=	Xft2>=2.1.2
BUILDLINK_API_DEPENDS.Xrender+=	Xrender>=0.8
BUILDLINK_API_DEPENDS.glitz+=	glitz>=0.5.1
BUILDLINK_API_DEPENDS.libpixman+=	libpixman>=0.1.5

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mmipspro*)
CFLAGS+=			-c99
.endif

TEST_TARGET=			check

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glitz/buildlink3.mk"
.include "../../graphics/libpixman/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
