# $NetBSD: Makefile,v 1.6 2013/02/02 15:54:11 dholland Exp $
#

DISTNAME=	libwebp-0.2.1
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://webp.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://code.google.com/speed/webp/index.html
COMMENT=	WebP image format library and tools
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../mk/compiler.mk"
# fix PR pkg/45934
.if !empty(MACHINE_PLATFORM:MSunOS-*-i386) && !empty(CC_VERSION:Mgcc-[23]*)
CPPFLAGS += -D__pic__
.endif

PKGCONFIG_OVERRIDE+=	src/libwebp.pc.in

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
