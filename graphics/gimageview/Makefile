# $NetBSD: Makefile,v 1.3 2003/01/10 07:40:12 cjep Exp $
#

DISTNAME=	gimageview-0.2.10
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkmmviewer/}

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://gtkmmviewer.sourceforge.net/
COMMENT=	GTK+ based image viewer with tabbed browsing

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_GNU_GETTEXT=	YES
USE_X11BASE=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--with-gtk2
CONFIGURE_ARGS+=	--with-imlib-prefix=${BUILDLINK_PREFIX.imlib2}
CONFIGURE_ARGS+=	--disable-xinetest

.include "../../graphics/imlib2/buildlink2.mk"
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../devel/pth/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../graphics/mng/buildlink2.mk"
.include "../../graphics/librsvg2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
