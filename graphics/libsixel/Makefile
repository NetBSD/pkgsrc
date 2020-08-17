# $NetBSD: Makefile,v 1.53 2020/08/17 20:19:04 leot Exp $

DISTNAME=		libsixel-1.8.6
PKGREVISION=		5
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_GITHUB:=saitoha/}
GITHUB_PROJECT=		libsixel
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		tsutsui@NetBSD.org
HOMEPAGE=		https://saitoha.github.io/libsixel/
COMMENT=		DEC SIXEL graphics codec encoder/decoder and converter
LICENSE=		mit AND public-domain

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ARGS+=	--disable-python

PKGCONFIG_OVERRIDE+=	libsixel.pc.in

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
