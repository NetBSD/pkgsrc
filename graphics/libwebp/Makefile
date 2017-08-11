# $NetBSD: Makefile,v 1.24 2017/08/11 16:41:23 nros Exp $

DISTNAME=	libwebp-0.6.0
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://downloads.webmproject.org/releases/webp/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://developers.google.com/speed/webp/
COMMENT=	WebP image format library and tools
LICENSE=	modified-bsd

.include "options.mk"

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--enable-libwebpdemux
CONFIGURE_ARGS+=	--enable-libwebpmux
CONFIGURE_ARGS+=	--enable-libwebpdemux
CONFIGURE_ARGS+=	--enable-libwebpdecoder
CONFIGURE_ARGS+=	--enable-libwebpextras
CONFIGURE_ARGS+=	--disable-gl

.include "../../mk/compiler.mk"
# fix PR pkg/45934
.if (!empty(MACHINE_PLATFORM:MSunOS-*-i386) || !empty(MACHINE_PLATFORM:MMirBSD-*-i386)) && !empty(CC_VERSION:Mgcc-[23]*)
CPPFLAGS += -D__pic__
.endif

PKGCONFIG_OVERRIDE+=	src/libwebp.pc.in
PKGCONFIG_OVERRIDE+=    src/libwebpdecoder.pc.in
PKGCONFIG_OVERRIDE+=    src/demux/libwebpdemux.pc.in
PKGCONFIG_OVERRIDE+=    src/mux/libwebpmux.pc.in

INSTALLATION_DIRS+=	share/doc/${PKGBASE}

#Needed to comply with the BSD license and redistribution
post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
