# $NetBSD: Makefile,v 1.14 2019/02/13 15:16:00 tnn Exp $
#

DISTNAME=	qrencode-4.0.2
CATEGORIES=	converters
MASTER_SITES=	https://fukuchi.org/works/qrencode/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	alaric@kitten-technologies.co.uk
HOMEPAGE=	https://fukuchi.org/works/qrencode/
COMMENT=	QR Code generator
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

# The tests are not actually installed anyway, and at least
# one of these tests requires SDL.
CONFIGURE_ARGS+= --without-tests

PKGCONFIG_OVERRIDE+=	libqrencode.pc.in

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
