# $NetBSD: Makefile,v 1.3 2009/01/12 12:44:11 wiz Exp $

DISTNAME=	gnome-mobile-2.24.1.91
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for mobile support for the GNOME desktop

META_PACKAGE=	yes

# see http://ftp.gnome.org/pub/GNOME/mobile/2.24/2.24.2/sources/

# unpackaged
#DEPENDS+=	GConf-dbus>=2.16.0:../../*/GConf-dbus
DEPENDS+=	atk>=1.24.0:../../devel/atk
# unpackaged
#DEPENDS+=	evolution-data-server-dbus>=2.20.0:../../*/evolution-data-server-dbus
DEPENDS+=	glib2>=2.18.3:../../devel/glib2
DEPENDS+=	gst-plugins0.10-base>=0.10.21:../../multimedia/gst-plugins0.10-base
DEPENDS+=	gstreamer0.10>=0.10.21:../../multimedia/gstreamer0.10
DEPENDS+=	gtk2+>=2.14.5:../../x11/gtk2
DEPENDS+=	gtk-doc>=1.10:../../textproc/gtk-doc
DEPENDS+=	intltool>=0.40.5:../../textproc/intltool
DEPENDS+=	pango>=1.22.3:../../devel/pango

.include "../../mk/bsd.pkg.mk"
