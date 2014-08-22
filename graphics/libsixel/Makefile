# $NetBSD: Makefile,v 1.3 2014/08/22 10:25:09 obache Exp $

DISTNAME=		libsixel-1.0.0
CATEGORIES=		graphics
MASTER_SITES=		-${HOMEPAGE:Q}/archive/v${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		https://github.com/saitoha/libsixel
COMMENT=		DEC SIXEL graphics codec encoder/decoder and converter
LICENSE=		mit AND public-domain

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	libsixel.pc.in

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
