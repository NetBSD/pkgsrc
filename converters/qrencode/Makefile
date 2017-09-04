# $NetBSD: Makefile,v 1.13 2017/09/04 18:08:19 wiz Exp $
#

DISTNAME=	qrencode-3.4.4
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

MAKE_JOBS_SAFE=		no

# The tests are not actually installed anyway, and at least
# one of these tests requires SDL.
CONFIGURE_ARGS+= --without-tests

PKGCONFIG_OVERRIDE+=	libqrencode.pc.in

.include "options.mk"

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
