# $NetBSD: Makefile,v 1.3 2002/03/04 14:36:54 martti Exp $

DISTNAME=	gtkam-0.1.2
PKGREVISION=	1
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
