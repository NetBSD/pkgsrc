# $NetBSD: Makefile,v 1.7 2002/10/07 19:33:58 wiz Exp $

DISTNAME=	gtkam-0.1.2
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gphoto/}

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.gphoto.org/gphoto2/
COMMENT=	GTK+ application for downloading, saving and manipulating on images from digital cameras

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_X11BASE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-nls
CPPFLAGS+=		-DHAVE_CONFIG_H -I${WRKSRC}

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../graphics/gphoto2/buildlink2.mk"
.include "../../graphics/libexif/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
