# $NetBSD: Makefile,v 1.83 2026/04/19 14:56:11 wiz Exp $

DISTNAME=		libsixel-1.8.7-r1
PKGNAME=		${DISTNAME:S/-r/r/}
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_GITHUB:=saitoha/}
GITHUB_PROJECT=		libsixel
#GITHUB_TAG=		v${PKGVERSION_NOREV}
GITHUB_TAG=		v1.8.7-r1

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
