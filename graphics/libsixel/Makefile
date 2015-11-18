# $NetBSD: Makefile,v 1.21 2015/11/18 14:19:50 ryoon Exp $

DISTNAME=		libsixel-1.4.11
PKGREVISION=		2
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_GITHUB:=saitoha/}
GITHUB_PROJECT=		libsixel
GITHUB_TAG=		v${PKGVERSION_NOREV}

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
