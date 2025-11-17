# $NetBSD: Makefile,v 1.29 2025/11/17 11:01:10 wiz Exp $

DISTNAME=	libmpeg2-0.5.1
PKGNAME=	libmpeg2-0.5.1
CATEGORIES=	multimedia
MASTER_SITES=	http://libmpeg2.sourceforge.net/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libmpeg2.sourceforge.net/
COMMENT=	Library for decoding mpeg-2 and mpeg-1 video streams

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	libmpeg2/convert/libmpeg2convert.pc.in
PKGCONFIG_OVERRIDE+=	libmpeg2/libmpeg2.pc.in

CONFIG_GUESS_OVERRIDE+=	.auto/config.guess
CONFIG_SUB_OVERRIDE+=	.auto/config.sub

CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--disable-sdl

CONFIGURE_ENV.Darwin+=	ac_cv_header_altivec_h=no

.include "../../mk/bsd.pkg.mk"
