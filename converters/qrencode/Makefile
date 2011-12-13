# $NetBSD: Makefile,v 1.7 2011/12/13 21:44:36 ryoon Exp $
#

DISTNAME=	qrencode-3.2.0
CATEGORIES=	converters
MASTER_SITES=	http://fukuchi.org/works/qrencode/

MAINTAINER=	alaric@kitten-technologies.co.uk
HOMEPAGE=	http://fukuchi.org/works/qrencode/index.en.html
COMMENT=	QR Code generator
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

MAKE_JOBS_SAFE=		no

# The tests are not actually installed anyway, and at least
# one of these tests requires SDL.
CONFIGURE_ARGS+= --without-tests

PKGCONFIG_OVERRIDE+=	libqrencode.pc.in

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
