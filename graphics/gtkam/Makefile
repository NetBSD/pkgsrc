# $NetBSD: Makefile,v 1.5.2.1 2002/06/23 18:46:25 jlam Exp $

DISTNAME=	gtkam-0.1.2
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gphoto/}

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.gphoto.org/gphoto2/
COMMENT=	GTK+ application for downloading, saving and manipulating on images from digital cameras

BUILD_USES_MSGFMT=	yes

USE_X11BASE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-nls
CPPFLAGS+=		-I${LOCALBASE}/include -DHAVE_CONFIG_H -I${WRKSRC}

BUILDLINK_DEPENDS.gdk-pixbuf=   gdk-pixbuf>=0.11.0nb1

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../graphics/gdk-pixbuf/buildlink.mk"
.include "../../graphics/gphoto2/buildlink.mk"
.include "../../graphics/libexif/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
