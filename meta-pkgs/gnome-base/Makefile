# $NetBSD: Makefile,v 1.56 2008/10/28 11:03:24 wiz Exp $

DISTNAME=	gnome-base-2.24.0
PKGREVISION=	3
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for basic components of the GNOME desktop

META_PACKAGE=	yes

# The dependencies listed here are in an order such as a package in a line
# can be installed if all the packages listed above it are installed.
#
# Keep this order as it helps in updating the whole GNOME Desktop to a
# newer version.  Note that the list includes all the packages listed as
# part of either the GNOME Desktop and the GNOME Platform; nothing else
# should be included here.
#
# Packages commented out are either because they are just build time
# dependencies or because they are not yet ready to be enabled.
#DEPENDS+=	pkg-config>=0.21:../../devel/pkg-config
#DEPENDS+=	intltool>=0.35.0:../../textproc/intltool
DEPENDS+=	startup-notification>=0.9:../../x11/startup-notification
DEPENDS+=	glib2>=2.18.2:../../devel/glib2
DEPENDS+=	atk>=1.24.0:../../devel/atk
DEPENDS+=	pango>=1.22.1:../../devel/pango
DEPENDS+=	gtk2+>=2.14.4:../../x11/gtk2
DEPENDS+=	libIDL>=0.8.11:../../net/libIDL
DEPENDS+=	ORBit2>=2.14.16:../../net/ORBit2
DEPENDS+=	libxml2>=2.7.2nb1:../../textproc/libxml2
DEPENDS+=	libxslt>=1.1.24nb1:../../textproc/libxslt
DEPENDS+=	GConf>=2.24.0:../../devel/GConf
DEPENDS+=	GConf-ui>=2.24.0:../../devel/GConf-ui
DEPENDS+=	libbonobo>=2.24.0:../../devel/libbonobo
DEPENDS+=	libaudiofile>=0.2.6nb1:../../audio/libaudiofile
DEPENDS+=	esound>=0.2.40:../../audio/esound
DEPENDS+=	gnome-vfs>=2.24.0:../../sysutils/gnome-vfs
DEPENDS+=	gnome-vfs-cdda>=2.24.0:../../audio/gnome-vfs-cdda
DEPENDS+=	gnome-vfs-smb>=2.24.0:../../net/gnome-vfs-smb
DEPENDS+=	libgnome>=2.24.1:../../devel/libgnome
DEPENDS+=	libglade>=2.6.3:../../devel/libglade
DEPENDS+=	libart>=2.3.20:../../graphics/libart
DEPENDS+=	libgnomecanvas>=2.20.1.1nb1:../../graphics/libgnomecanvas
DEPENDS+=	libbonoboui>=2.24.0:../../devel/libbonoboui
DEPENDS+=	gnome-keyring>=2.24.1:../../security/gnome-keyring
DEPENDS+=	libgnomeui>=2.24.0:../../devel/libgnomeui
DEPENDS+=	gnome-icon-theme>=2.24.0:../../graphics/gnome-icon-theme
DEPENDS+=	libgnomeprint>=2.18.5:../../print/libgnomeprint
DEPENDS+=	libgnomeprintui>=2.18.3:../../print/libgnomeprintui
DEPENDS+=	libgtop>=2.20.2:../../sysutils/libgtop
DEPENDS+=	librsvg>=2.22.3:../../graphics/librsvg
DEPENDS+=	libxklavier>=3.7:../../x11/libxklavier
DEPENDS+=	libsoup24>=2.24.1:../../net/libsoup24
DEPENDS+=	libwnck>=2.24.1:../../devel/libwnck
DEPENDS+=	gtkhtml314>=3.24.1:../../www/gtkhtml314
DEPENDS+=	gtk2-engines>=2.14.3:../../x11/gtk2-engines
DEPENDS+=	gnome-desktop>=2.24.1:../../x11/gnome-desktop
DEPENDS+=	gnome-menus>=2.24.1:../../sysutils/gnome-menus
DEPENDS+=	eel>=2.24.1:../../devel/eel
DEPENDS+=	nautilus>=2.24.0:../../sysutils/nautilus
DEPENDS+=	gvfs>=1.0.2:../../sysutils/gvfs
DEPENDS+=	metacity>=2.24.0:../../wm/metacity
DEPENDS+=	gstreamer0.10>=0.10.21nb1:../../multimedia/gstreamer0.10
DEPENDS+=	gst-plugins0.10-base>=0.10.21:../../multimedia/gst-plugins0.10-base
DEPENDS+=	gst-plugins0.10-good>=0.10.10:../../multimedia/gst-plugins0.10-good
DEPENDS+=	gst-plugins0.10-esound>=0.10.10:../../audio/gst-plugins0.10-esound
DEPENDS+=	gst-plugins0.10-oss>=0.10.10:../../audio/gst-plugins0.10-oss
DEPENDS+=	evolution-data-server>=2.24.1:../../mail/evolution-data-server
DEPENDS+=	gnome-control-center>=2.24.0.1nb1:../../x11/gnome-control-center
DEPENDS+=	gnome-panel>=2.24.1:../../x11/gnome-panel
DEPENDS+=	gucharmap>=2.22.3:../../fonts/gucharmap
DEPENDS+=	gnome-applets>=2.24.0.1:../../x11/gnome-applets
DEPENDS+=	gnome-themes>=2.22.2nb1:../../x11/gnome-themes
DEPENDS+=	gnome-backgrounds>=2.24.0:../../graphics/gnome-backgrounds
DEPENDS+=	vte>=0.17.4nb1:../../x11/vte
DEPENDS+=	gnome-terminal>=2.24.1.1:../../x11/gnome-terminal
DEPENDS+=	gnome-session>=2.24.1:../../x11/gnome-session

.include "../../mk/bsd.pkg.mk"
