# $NetBSD: Makefile,v 1.5 2011/01/13 13:37:17 wiz Exp $
#

DISTNAME=	qrencode-3.0.3
PKGREVISION=	2
CATEGORIES=	converters
MASTER_SITES=	http://megaui.net/fukuchi/works/qrencode/

MAINTAINER=	alaric@kitten-technologies.co.uk
HOMEPAGE=	http://megaui.net/fukuchi/works/qrencode/index.en.html
COMMENT=	QR Code generator

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+= c c++
USE_LIBTOOL=	yes

MAKE_JOBS_SAFE=		no

# The tests are not actually installed anyway, and at least
# one of these tests requires SDL.
CONFIGURE_ARGS+= --without-tests

PKGCONFIG_OVERRIDE+=	libqrencode.pc.in

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
