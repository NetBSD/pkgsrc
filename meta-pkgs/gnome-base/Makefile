# $NetBSD: Makefile,v 1.16 2005/02/26 17:27:44 jmmv Exp $

DISTNAME=	gnome-base-2.8.3
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
#DEPENDS+=	pkgconfig>=0.15.0:../../devel/pkgconfig
#DEPENDS+=	intltool>=0.33:../../textproc/intltool
DEPENDS+=	startup-notification>=0.8:../../x11/startup-notification
DEPENDS+=	glib2>=2.4.8:../../devel/glib2
DEPENDS+=	atk>=1.8.0:../../devel/atk
DEPENDS+=	pango>=1.6.0:../../devel/pango
DEPENDS+=	gtk2+>=2.4.14:../../x11/gtk2
DEPENDS+=	libIDL>=0.8.5:../../net/libIDL
DEPENDS+=	ORBit2>=2.12.1:../../net/ORBit2
DEPENDS+=	libxml2>=2.6.17:../../textproc/libxml2
DEPENDS+=	libxslt>=1.1.12:../../textproc/libxslt
DEPENDS+=	GConf2>=2.8.1:../../devel/GConf2
DEPENDS+=	GConf2-ui>=2.8.1:../../devel/GConf2-ui
DEPENDS+=	libbonobo>=2.8.1:../../devel/libbonobo
DEPENDS+=	gnome-mime-data>=2.4.2:../../databases/gnome-mime-data
DEPENDS+=	libaudiofile>=0.2.6:../../audio/libaudiofile
DEPENDS+=	esound>=0.2.35:../../audio/esound
DEPENDS+=	gnome-vfs2>=2.8.4:../../sysutils/gnome-vfs2
DEPENDS+=	gnome-vfs2-cdda>=2.8.4:../../audio/gnome-vfs2-cdda
DEPENDS+=	gnome-vfs2-smb>=2.8.4:../../net/gnome-vfs2-smb
DEPENDS+=	libgnome>=2.8.1:../../devel/libgnome
DEPENDS+=	libglade2>=2.4.2:../../devel/libglade2
DEPENDS+=	libart2>=2.3.17:../../graphics/libart2
DEPENDS+=	libgnomecanvas>=2.8.0:../../graphics/libgnomecanvas
DEPENDS+=	libbonoboui>=2.8.1:../../devel/libbonoboui
DEPENDS+=	gnome-keyring>=0.4.1:../../security/gnome-keyring
DEPENDS+=	libgnomeui>=2.8.1:../../devel/libgnomeui
DEPENDS+=	gnome-icon-theme>=2.8.0:../../graphics/gnome-icon-theme
DEPENDS+=	libgnomeprint>=2.8.2:../../print/libgnomeprint
DEPENDS+=	libgnomeprintui>=2.8.2:../../print/libgnomeprintui
DEPENDS+=	libgtop2>=2.8.3:../../sysutils/libgtop2
DEPENDS+=	librsvg2>=2.8.1:../../graphics/librsvg2
DEPENDS+=	librsvg2-gtk2>=2.8.1:../../graphics/librsvg2-gtk2
DEPENDS+=	libxklavier>=1.04:../../x11/libxklavier
DEPENDS+=	libgtkhtml>=2.6.3:../../www/libgtkhtml
DEPENDS+=	libsoup-devel>=2.2.2:../../net/libsoup-devel
DEPENDS+=	libwnck>=2.8.1:../../devel/libwnck
DEPENDS+=	gail>=1.8.2:../../devel/gail
DEPENDS+=	gtkhtml3>=3.2.5:../../www/gtkhtml3
DEPENDS+=	gtk2-engines>=2.2.0:../../x11/gtk2-engines
DEPENDS+=	scrollkeeper>=0.3.14:../../textproc/scrollkeeper
DEPENDS+=	gnome2-pixmaps>=2.8.1:../../graphics/gnome2-pixmaps
DEPENDS+=	gnome-desktop>=2.8.1:../../x11/gnome-desktop
DEPENDS+=	eel2>=2.8.2:../../devel/eel2
DEPENDS+=	nautilus>=2.8.2:../../sysutils/nautilus
DEPENDS+=	metacity>=2.8.8:../../wm/metacity
DEPENDS+=	gstreamer>=0.8.9:../../multimedia/gstreamer
DEPENDS+=	gst-plugins>=0.8.7:../../multimedia/gst-plugins
DEPENDS+=	gnome2-control-center>=2.8.2:../../x11/gnome2-control-center
DEPENDS+=	evolution-data-server>=1.0.4:../../mail/evolution-data-server
DEPENDS+=	gnome-panel>=2.8.3:../../x11/gnome-panel
DEPENDS+=	gnome-applets>=2.8.2:../../x11/gnome2-applets
DEPENDS+=	gnome-themes>=2.8.2:../../x11/gnome-themes
DEPENDS+=	vte>=0.11.11:../../x11/vte
DEPENDS+=	gnome2-terminal>=2.8.2:../../x11/gnome2-terminal
DEPENDS+=	gnome-session>=2.8.1:../../x11/gnome-session
# Not really part of GNOME, but we need it.
DEPENDS+=	xscreensaver>=4.16:../../x11/xscreensaver

USE_X11=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_BUILDLINK=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
