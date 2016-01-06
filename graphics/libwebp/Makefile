# $NetBSD: Makefile,v 1.18 2016/01/06 10:33:59 adam Exp $

DISTNAME=	libwebp-0.5.0
CATEGORIES=	graphics
MASTER_SITES=	http://downloads.webmproject.org/releases/webp/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://developers.google.com/speed/webp/
COMMENT=	WebP image format library and tools
LICENSE=	modified-bsd

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

.include "../../mk/compiler.mk"
# fix PR pkg/45934
.if (!empty(MACHINE_PLATFORM:MSunOS-*-i386) || !empty(MACHINE_PLATFORM:MMirBSD-*-i386)) && !empty(CC_VERSION:Mgcc-[23]*)
CPPFLAGS += -D__pic__
.endif

PKGCONFIG_OVERRIDE+=	src/libwebp.pc.in

.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
