# $NetBSD: Makefile,v 1.37 2007/04/17 17:48:47 drochner Exp $

DISTNAME=	gnome-base-2.18.1
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for basic components of the GNOME desktop

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
DEPENDS+=	glib2>=2.12.3:../../devel/glib2
DEPENDS+=	atk>=1.18.0:../../devel/atk
DEPENDS+=	pango>=1.16.0:../../devel/pango
DEPENDS+=	gtk2+>=2.10.3:../../x11/gtk2
DEPENDS+=	libIDL>=0.8.8:../../net/libIDL
DEPENDS+=	ORBit2>=2.14.3:../../net/ORBit2
DEPENDS+=	libxml2>=2.6.26:../../textproc/libxml2
DEPENDS+=	libxslt>=1.1.17:../../textproc/libxslt
DEPENDS+=	GConf2>=2.18.0:../../devel/GConf2
DEPENDS+=	GConf2-ui>=2.18.0:../../devel/GConf2-ui
DEPENDS+=	libbonobo>=2.18.0:../../devel/libbonobo
DEPENDS+=	libaudiofile>=0.2.6:../../audio/libaudiofile
DEPENDS+=	esound>=0.2.36:../../audio/esound
DEPENDS+=	gnome-vfs2>=2.18.1:../../sysutils/gnome-vfs2
DEPENDS+=	gnome-vfs2-cdda>=2.18.1:../../audio/gnome-vfs2-cdda
DEPENDS+=	gnome-vfs2-smb>=2.18.1:../../net/gnome-vfs2-smb
DEPENDS+=	libgnome>=2.18.0:../../devel/libgnome
DEPENDS+=	libglade2>=2.6.0:../../devel/libglade2
DEPENDS+=	libart2>=2.3.17:../../graphics/libart2
DEPENDS+=	libgnomecanvas>=2.14.0:../../graphics/libgnomecanvas
DEPENDS+=	libbonoboui>=2.18.0:../../devel/libbonoboui
DEPENDS+=	gnome-keyring>=0.8.1:../../security/gnome-keyring
DEPENDS+=	libgnomeui>=2.18.1:../../devel/libgnomeui
DEPENDS+=	gnome-icon-theme>=2.18.0:../../graphics/gnome-icon-theme
DEPENDS+=	libgnomeprint>=2.18.0:../../print/libgnomeprint
DEPENDS+=	libgnomeprintui>=2.18.0:../../print/libgnomeprintui
DEPENDS+=	libgtop2>=2.14.2:../../sysutils/libgtop2
DEPENDS+=	librsvg2>=2.16.0:../../graphics/librsvg2
DEPENDS+=	libxklavier>=3.0:../../x11/libxklavier
DEPENDS+=	libsoup-devel>=2.2.96:../../net/libsoup-devel
DEPENDS+=	libwnck>=2.18.0:../../devel/libwnck
DEPENDS+=	gail>=1.18.0:../../devel/gail
DEPENDS+=	gtkhtml314>=3.14.1:../../www/gtkhtml314
DEPENDS+=	gtk2-engines>=2.10.1:../../x11/gtk2-engines
DEPENDS+=	scrollkeeper>=0.3.14:../../textproc/scrollkeeper
DEPENDS+=	gnome-desktop>=2.18.1:../../x11/gnome-desktop
DEPENDS+=	gnome-menus>=2.18.0:../../sysutils/gnome-menus
DEPENDS+=	eel2>=2.18.0.1:../../devel/eel2
DEPENDS+=	nautilus>=2.18.1:../../sysutils/nautilus
DEPENDS+=	metacity>=2.18.2:../../wm/metacity
DEPENDS+=	gstreamer0.10>=0.10.12:../../multimedia/gstreamer0.10
DEPENDS+=	gst-plugins0.10-base>=0.10.12:../../multimedia/gst-plugins0.10-base
DEPENDS+=	gst-plugins0.10-good>=0.10.5:../../multimedia/gst-plugins0.10-good
DEPENDS+=	gst-plugins0.10-esound>=0.10.5:../../audio/gst-plugins0.10-esound
DEPENDS+=	gst-plugins0.10-oss>=0.10.5:../../audio/gst-plugins0.10-oss
DEPENDS+=	evolution-data-server>=1.10.1:../../mail/evolution-data-server
DEPENDS+=	gnome2-control-center>=2.18.1:../../x11/gnome2-control-center
DEPENDS+=	gnome-panel>=2.18.1:../../x11/gnome-panel
DEPENDS+=	gucharmap>=1.10.0:../../fonts/gucharmap
DEPENDS+=	gnome-applets>=2.18.0:../../x11/gnome2-applets
DEPENDS+=	gnome-themes>=2.18.1:../../x11/gnome-themes
DEPENDS+=	gnome-backgrounds>=2.15.92:../../graphics/gnome-backgrounds
DEPENDS+=	vte>=0.16.1:../../x11/vte
DEPENDS+=	gnome2-terminal>=2.18.0:../../x11/gnome2-terminal
DEPENDS+=	gnome-session>=2.18.0:../../x11/gnome-session

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
