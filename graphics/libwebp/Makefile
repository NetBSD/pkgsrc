# $NetBSD: Makefile,v 1.37 2022/07/18 19:06:44 adam Exp $

DISTNAME=	libwebp-1.2.3
CATEGORIES=	graphics
MASTER_SITES=	https://storage.googleapis.com/downloads.webmproject.org/releases/webp/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://developers.google.com/speed/webp/
COMMENT=	WebP image format library and tools
LICENSE=	modified-bsd

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-gl
CONFIGURE_ARGS+=	--disable-sdl
CONFIGURE_ARGS+=	--enable-libwebpdecoder
CONFIGURE_ARGS+=	--enable-libwebpextras
CONFIGURE_ARGS+=	--enable-libwebpdemux
CONFIGURE_ARGS+=	--enable-libwebpmux

.include "options.mk"

.include "../../mk/compiler.mk"
# fix PR pkg/45934
.if (!empty(MACHINE_PLATFORM:MSunOS-*-i386) || !empty(MACHINE_PLATFORM:MMirBSD-*-i386)) && !empty(CC_VERSION:Mgcc-[23]*)
CPPFLAGS+=	-D__pic__
.endif

PKGCONFIG_OVERRIDE+=	src/demux/libwebpdemux.pc.in
PKGCONFIG_OVERRIDE+=	src/libwebp.pc.in
PKGCONFIG_OVERRIDE+=	src/libwebpdecoder.pc.in
PKGCONFIG_OVERRIDE+=	src/mux/libwebpmux.pc.in

INSTALLATION_DIRS+=	share/doc/${PKGBASE}

# Needed to comply with the BSD license and redistribution
post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
