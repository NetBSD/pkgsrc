# $NetBSD: Makefile,v 1.12 2013/12/28 23:03:39 tron Exp $

DISTNAME=	libwebp-0.3.1
CATEGORIES=	graphics
MASTER_SITES=	http://webp.googlecode.com/files/
#EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://code.google.com/speed/webp/index.html
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

.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
