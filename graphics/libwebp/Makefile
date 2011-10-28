# $NetBSD: Makefile,v 1.1.1.1 2011/10/28 13:48:00 ryoon Exp $
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

PKGCONFIG_OVERRIDE+=	src/libwebp.pc.in

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
