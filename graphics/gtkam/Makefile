# $NetBSD: Makefile,v 1.2 2002/02/28 14:52:18 martti Exp $

DISTNAME=	gtkam-0.1.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gphoto/}

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.gphoto.org/gphoto2/
COMMENT=	Download and view files from various digital cameras

BUILD_USES_MSGFMT=	yes

USE_X11BASE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-nls
CPPFLAGS+=		-I${LOCALBASE}/include -DHAVE_CONFIG_H -I${WRKSRC}

BUILDLINK_DEPENDS.gdk-pixbuf=   gdk-pixbuf>=0.9.0

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../graphics/gdk-pixbuf/buildlink.mk"
.include "../../graphics/gphoto2/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
