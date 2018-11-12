# $NetBSD: Makefile,v 1.44 2018/11/12 03:51:09 ryoon Exp $

DISTNAME=		blib-1.0.2
PKGREVISION=		33
CATEGORIES=		devel graphics
MASTER_SITES=		http://sven.gimp.org/blinkenlights/old/

MAINTAINER=		salo@NetBSD.org
HOMEPAGE=		http://www.blinkenlights.de/
COMMENT=		Blinkenlights library

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

SHLIBTOOL_OVERRIDE=	# empty
PKGCONFIG_OVERRIDE+=	blib-directfb.pc.in
PKGCONFIG_OVERRIDE+=	blib-gtk.pc.in
PKGCONFIG_OVERRIDE+=	blib.pc.in

CONFIGURE_ARGS+=	--enable-gtk-doc=no

# XXX: fix this for GNU/Linux, provide appropriate PLIST.
CONFIGURE_ARGS+=	--disable-directfb

CFLAGS.SunOS+=		-Du_int16_t=uint16_t
CFLAGS.SunOS+=		-Du_int32_t=uint32_t

post-extract:
	${TOUCH} ${WRKSRC}/modules/libtool

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
