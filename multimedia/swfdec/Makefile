# $NetBSD: Makefile,v 1.10 2009/02/23 18:05:04 wiz Exp $
#

DISTNAME=		swfdec-0.8.4
CATEGORIES=		multimedia
MASTER_SITES=		http://swfdec.freedesktop.org/download/swfdec/0.8/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://swfdec.freedesktop.org/
COMMENT=		Library for rendering Flash(R) animations and games

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE=	swfdec-0.8.pc.in
PKGCONFIG_OVERRIDE=	swfdec-gtk-0.8.pc.in

CONFIGURE_ARGS+=	--with-audio=none
CONFIGURE_ARGS+=	--enable-gtk

.include "../../devel/liboil/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
