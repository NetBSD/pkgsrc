# $NetBSD: Makefile,v 1.50 2026/07/02 10:42:04 ryoon Exp $

DISTNAME=	libwebp-1.6.0
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	https://storage.googleapis.com/downloads.webmproject.org/releases/webp/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://developers.google.com/speed/webp/
COMMENT=	WebP image format library and tools
LICENSE=	modified-bsd

CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON
# Disable SDL2 explicitly to fix build when devel/SDL2 is already installed.
CMAKE_CONFIGURE_ARGS+=	-DWEBP_BUILD_VWEBP=OFF

.include "options.mk"

.include "../../mk/compiler.mk"
# fix PR pkg/45934
.if ${MACHINE_PLATFORM:MSunOS-*-i386} && ${CC_VERSION:Mgcc-[23]*}
CPPFLAGS+=	-D__pic__
.endif

PKGCONFIG_OVERRIDE+=	sharpyuv/libsharpyuv.pc.in
PKGCONFIG_OVERRIDE+=	src/demux/libwebpdemux.pc.in
PKGCONFIG_OVERRIDE+=	src/libwebp.pc.in
PKGCONFIG_OVERRIDE+=	src/libwebpdecoder.pc.in
PKGCONFIG_OVERRIDE+=	src/mux/libwebpmux.pc.in

INSTALLATION_DIRS+=	share/doc/${PKGBASE}

# Needed to comply with the BSD license and redistribution
post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../devel/cmake/build.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
