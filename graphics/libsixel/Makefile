# $NetBSD: Makefile,v 1.2 2014/08/08 13:31:24 obache Exp $

DISTNAME=		libsixel-0.28.0
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
