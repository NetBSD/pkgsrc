# $NetBSD: Makefile,v 1.8 2012/10/03 00:20:16 asau Exp $
#

DISTNAME=	qrencode-3.2.0
CATEGORIES=	converters
MASTER_SITES=	http://fukuchi.org/works/qrencode/

MAINTAINER=	alaric@kitten-technologies.co.uk
HOMEPAGE=	http://fukuchi.org/works/qrencode/index.en.html
COMMENT=	QR Code generator
LICENSE=	gnu-lgpl-v2.1

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
