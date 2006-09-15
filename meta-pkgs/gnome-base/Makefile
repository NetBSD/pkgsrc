# $NetBSD: Makefile,v 1.34 2006/09/15 15:25:27 jmmv Exp $

DISTNAME=	gnome-base-2.16.0
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
DEPENDS+=	startup-notification>=0.8:../../x11/startup-notification
DEPENDS+=	glib2>=2.12.3:../../devel/glib2
DEPENDS+=	atk>=1.12.2:../../devel/atk
DEPENDS+=	pango>=1.14.3:../../devel/pango
DEPENDS+=	gtk2+>=2.10.3:../../x11/gtk2
DEPENDS+=	libIDL>=0.8.7:../../net/libIDL
DEPENDS+=	ORBit2>=2.14.3:../../net/ORBit2
DEPENDS+=	libxml2>=2.6.26:../../textproc/libxml2
DEPENDS+=	libxslt>=1.1.17:../../textproc/libxslt
DEPENDS+=	GConf2>=2.14.0:../../devel/GConf2
DEPENDS+=	GConf2-ui>=2.14.0:../../devel/GConf2-ui
DEPENDS+=	libbonobo>=2.16.0:../../devel/libbonobo
DEPENDS+=	libaudiofile>=0.2.6:../../audio/libaudiofile
DEPENDS+=	esound>=0.2.36:../../audio/esound
DEPENDS+=	gnome-vfs2>=2.16.0:../../sysutils/gnome-vfs2
DEPENDS+=	gnome-vfs2-cdda>=2.16.0:../../audio/gnome-vfs2-cdda
DEPENDS+=	gnome-vfs2-smb>=2.16.0:../../net/gnome-vfs2-smb
DEPENDS+=	libgnome>=2.16.0:../../devel/libgnome
DEPENDS+=	libglade2>=2.6.0:../../devel/libglade2
DEPENDS+=	libart2>=2.3.17:../../graphics/libart2
DEPENDS+=	libgnomecanvas>=2.14.0:../../graphics/libgnomecanvas
DEPENDS+=	libbonoboui>=2.16.0:../../devel/libbonoboui
DEPENDS+=	gnome-keyring>=0.6.0:../../security/gnome-keyring
DEPENDS+=	libgnomeui>=2.16.0:../../devel/libgnomeui
DEPENDS+=	gnome-icon-theme>=2.16.0:../../graphics/gnome-icon-theme
DEPENDS+=	libgnomeprint>=2.12.1:../../print/libgnomeprint
DEPENDS+=	libgnomeprintui>=2.12.1:../../print/libgnomeprintui
DEPENDS+=	libgtop2>=2.14.2:../../sysutils/libgtop2
DEPENDS+=	librsvg2>=2.16.0:../../graphics/librsvg2
DEPENDS+=	libxklavier>=3.0:../../x11/libxklavier
DEPENDS+=	libsoup-devel>=2.2.96:../../net/libsoup-devel
DEPENDS+=	libwnck>=2.16.0:../../devel/libwnck
DEPENDS+=	gail>=1.9.2:../../devel/gail
DEPENDS+=	gtkhtml38>=3.12.0:../../www/gtkhtml38
DEPENDS+=	gtk2-engines>=2.8.0:../../x11/gtk2-engines
DEPENDS+=	scrollkeeper>=0.3.14:../../textproc/scrollkeeper
DEPENDS+=	gnome-desktop>=2.16.0:../../x11/gnome-desktop
DEPENDS+=	gnome-menus>=2.16.0:../../sysutils/gnome-menus
DEPENDS+=	eel2>=2.16.0:../../devel/eel2
DEPENDS+=	nautilus>=2.16.0:../../sysutils/nautilus
DEPENDS+=	metacity>=2.16.0:../../wm/metacity
DEPENDS+=	gstreamer0.10>=0.10.8:../../multimedia/gstreamer0.10
DEPENDS+=	gst-plugins0.10-base>=0.10.7:../../multimedia/gst-plugins0.10-base
DEPENDS+=	gst-plugins0.10-good>=0.10.3:../../multimedia/gst-plugins0.10-good
DEPENDS+=	gst-plugins0.10-esound>=0.10.3:../../audio/gst-plugins0.10-esound
DEPENDS+=	gst-plugins0.10-oss>=0.10.3:../../audio/gst-plugins0.10-oss
DEPENDS+=	evolution-data-server>=1.8.0:../../mail/evolution-data-server
DEPENDS+=	gnome2-control-center>=2.16.0:../../x11/gnome2-control-center
DEPENDS+=	gnome-panel>=2.16.0:../../x11/gnome-panel
DEPENDS+=	gucharmap>=1.8.0:../../fonts/gucharmap
DEPENDS+=	gnome-applets>=2.16.0:../../x11/gnome2-applets
DEPENDS+=	gnome-themes>=2.16.0:../../x11/gnome-themes
DEPENDS+=	gnome-backgrounds>=2.15.92:../../graphics/gnome-backgrounds
DEPENDS+=	vte>=0.14.0:../../x11/vte
DEPENDS+=	gnome2-terminal>=2.16.0:../../x11/gnome2-terminal
DEPENDS+=	gnome-session>=2.16.0:../../x11/gnome-session

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
