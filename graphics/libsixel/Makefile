# $NetBSD: Makefile,v 1.16 2014/12/20 04:59:19 obache Exp $

DISTNAME=		libsixel-1.4.3
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
