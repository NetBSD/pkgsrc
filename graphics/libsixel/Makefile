# $NetBSD: Makefile,v 1.9 2014/09/27 12:27:39 obache Exp $

DISTNAME=		libsixel-1.0.3
CATEGORIES=		graphics
MASTER_SITES=		-https://github.com/saitoha/libsixel/archive/v${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://saitoha.github.io/libsixel/
COMMENT=		DEC SIXEL graphics codec encoder/decoder and converter
LICENSE=		mit AND public-domain

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	libsixel.pc.in

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
