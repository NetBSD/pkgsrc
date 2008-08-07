# $NetBSD: Makefile,v 1.21 2008/08/07 18:23:18 drochner Exp $

DISTNAME=	libmpeg2-0.5.1
PKGNAME=	libmpeg2-0.5.1
CATEGORIES=	multimedia
MASTER_SITES=	http://libmpeg2.sourceforge.net/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libmpeg2.sourceforge.net/
COMMENT=	Library for decoding mpeg-2 and mpeg-1 video streams

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	libmpeg2/convert/libmpeg2convert.pc.in
PKGCONFIG_OVERRIDE+=	libmpeg2/libmpeg2.pc.in

CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--disable-sdl

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
CONFIGURE_ENV+=		ac_cv_header_altivec_h=no
.endif

.include "../../mk/bsd.pkg.mk"
