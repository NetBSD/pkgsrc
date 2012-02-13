# $NetBSD: Makefile,v 1.2 2012/02/13 13:58:26 ryoon Exp $
#

DISTNAME=	libwebp-0.1.3
CATEGORIES=	graphics
MASTER_SITES=	http://webp.googlecode.com/files/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://code.google.com/speed/webp/index.html
COMMENT=	WebP image format library and tools
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

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
