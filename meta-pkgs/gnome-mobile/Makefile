# $NetBSD: Makefile,v 1.5 2009/03/22 12:29:04 wiz Exp $

DISTNAME=	gnome-mobile-2.25.99.0
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for mobile support for the GNOME desktop

META_PACKAGE=	yes

# see http://ftp.gnome.org/pub/GNOME/mobile/2.26/2.26.0/sources/

# unpackaged
#DEPENDS+=	GConf-dbus>=2.16.0:../../*/GConf-dbus
DEPENDS+=	atk>=1.26.0:../../devel/atk
# unpackaged
#DEPENDS+=	evolution-data-server-dbus>=2.20.0:../../*/evolution-data-server-dbus
DEPENDS+=	glib2>=2.20.0:../../devel/glib2
DEPENDS+=	gst-plugins0.10-base>=0.10.22:../../multimedia/gst-plugins0.10-base
DEPENDS+=	gstreamer0.10>=0.10.22:../../multimedia/gstreamer0.10
DEPENDS+=	gtk2+>=2.16.0:../../x11/gtk2
DEPENDS+=	gtk-doc>=1.11:../../textproc/gtk-doc
DEPENDS+=	pango>=1.24.0:../../devel/pango

.include "../../mk/bsd.pkg.mk"
