# $NetBSD: Makefile,v 1.7 2003/02/05 05:06:35 jlam Exp $

DISTNAME=	gimageview-0.2.13
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkmmviewer/}

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://gtkmmviewer.sourceforge.net/
COMMENT=	GTK+ based image viewer with tabbed browsing

DEPENDS+=	gnome1-dirs>=1.0:../../misc/gnome1-dirs

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_X11=		YES
BUILDLINK_DEPENDS.libwmf= libwmf>=0.2.8

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

#CONFIGURE_ARGS+=	--with-imlib-prefix=${BUILDLINK_PREFIX.imlib2}
CONFIGURE_ARGS+=	--disable-xinetest

# don't need both -- gimageview prefers gdk-pixbuf, so do we
#.include "../../graphics/imlib/buildlink2.mk"
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../graphics/mng/buildlink2.mk"
.include "../../textproc/libxml/buildlink2.mk"
.include "../../graphics/librsvg/buildlink2.mk"
.include "../../graphics/libwmf/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
