# $NetBSD: Makefile,v 1.81 2026/01/07 08:47:23 wiz Exp $

DISTNAME=		libsixel-1.8.7
PKGREVISION=		3
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
CPPFLAGS.SunOS=		-D__EXTENSIONS__

PKGCONFIG_OVERRIDE+=	libsixel.pc.in

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
