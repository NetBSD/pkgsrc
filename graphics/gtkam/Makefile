# $NetBSD: Makefile,v 1.1.1.1 2001/07/08 01:48:38 garbled Exp $

DISTNAME=	gtkam-20010707
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.gphoto.org/gphoto2/
COMMENT=	Download and view files from various digital cameras

BUILD_USES_MSGFMT=	yes
DEPENDS+=		gphoto-2*:../../graphics/gphoto2

USE_X11BASE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-nls
CPPFLAGS+=		-I${LOCALBASE}/include -DHAVE_CONFIG_H -I${WRKSRC}

BUILDLINK_DEPENDS.gdk-pixbuf=   gdk-pixbuf>=0.9.0

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../graphics/gdk-pixbuf/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
