# $NetBSD: Makefile,v 1.25 2004/02/20 17:49:45 jmmv Exp $

DISTNAME=	gimageview-0.2.24
PKGREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkmmviewer/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://gtkmmviewer.sourceforge.net/
COMMENT=	GTK+ based image viewer with tabbed browsing

DEPENDS+=	gnome2-dirs>=1.0:../../misc/gnome2-dirs

USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
USE_X11=		YES

CONFIGURE_ARGS+=	--disable-xinetest
CONFIGURE_ARGS+=	--with-gtk2

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../graphics/libwmf/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
