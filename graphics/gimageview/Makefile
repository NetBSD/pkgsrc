# $NetBSD: Makefile,v 1.13 2003/11/12 01:31:49 salo Exp $

DISTNAME=	gimageview-0.2.24
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkmmviewer/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://gtkmmviewer.sourceforge.net/
COMMENT=	GTK+ based image viewer with tabbed browsing

DEPENDS+=	gnome2-dirs>=1.0:../../misc/gnome2-dirs

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_X11=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--disable-xinetest
CONFIGURE_ARGS+=	--with-gtk2

.include "../../mk/pthread.buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../graphics/mng/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../graphics/librsvg2/buildlink2.mk"
.include "../../graphics/libwmf/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
