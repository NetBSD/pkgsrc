# $NetBSD: Makefile,v 1.23 2005/10/10 14:03:36 jmmv Exp $

DISTNAME=	gnome-base-2.10.2
PKGREVISION=	1
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
#DEPENDS+=	pkg-config>=0.18.1:../../devel/pkg-config
#DEPENDS+=	intltool>=0.33:../../textproc/intltool
DEPENDS+=	startup-notification>=0.8:../../x11/startup-notification
DEPENDS+=	glib2>=2.6.5:../../devel/glib2
DEPENDS+=	atk>=1.9.1:../../devel/atk
DEPENDS+=	pango>=1.8.1:../../devel/pango
DEPENDS+=	gtk2+>=2.6.8:../../x11/gtk2
DEPENDS+=	libIDL>=0.8.5:../../net/libIDL
DEPENDS+=	ORBit2>=2.12.2:../../net/ORBit2
DEPENDS+=	libxml2>=2.6.19:../../textproc/libxml2
DEPENDS+=	libxslt>=1.1.14:../../textproc/libxslt
DEPENDS+=	GConf2>=2.10.1:../../devel/GConf2
DEPENDS+=	GConf2-ui>=2.10.1:../../devel/GConf2-ui
DEPENDS+=	libbonobo>=2.10.0:../../devel/libbonobo
DEPENDS+=	gnome-mime-data>=2.4.2:../../databases/gnome-mime-data
DEPENDS+=	libaudiofile>=0.2.6:../../audio/libaudiofile
DEPENDS+=	esound>=0.2.36:../../audio/esound
DEPENDS+=	gnome-vfs2>=2.10.1:../../sysutils/gnome-vfs2
DEPENDS+=	gnome-vfs2-cdda>=2.10.1:../../audio/gnome-vfs2-cdda
DEPENDS+=	gnome-vfs2-smb>=2.10.1:../../net/gnome-vfs2-smb
DEPENDS+=	libgnome>=2.10.1:../../devel/libgnome
DEPENDS+=	libglade2>=2.5.1:../../devel/libglade2
DEPENDS+=	libart2>=2.3.17:../../graphics/libart2
DEPENDS+=	libgnomecanvas>=2.10.2:../../graphics/libgnomecanvas
DEPENDS+=	libbonoboui>=2.10.0:../../devel/libbonoboui
DEPENDS+=	gnome-keyring>=0.4.3:../../security/gnome-keyring
DEPENDS+=	libgnomeui>=2.10.1:../../devel/libgnomeui
DEPENDS+=	gnome-icon-theme>=2.10.1:../../graphics/gnome-icon-theme
DEPENDS+=	libgnomeprint>=2.10.3:../../print/libgnomeprint
DEPENDS+=	libgnomeprintui>=2.10.2:../../print/libgnomeprintui
DEPENDS+=	libgtop2>=2.10.2:../../sysutils/libgtop2
DEPENDS+=	librsvg2>=2.12.6:../../graphics/librsvg2
DEPENDS+=	libxklavier>=2.0:../../x11/libxklavier
DEPENDS+=	libgtkhtml>=2.6.3:../../www/libgtkhtml
DEPENDS+=	libsoup-devel>=2.2.3:../../net/libsoup-devel
DEPENDS+=	libwnck>=2.10.2:../../devel/libwnck
DEPENDS+=	gail>=1.8.4:../../devel/gail
DEPENDS+=	gtkhtml36>=3.5.7:../../www/gtkhtml36
DEPENDS+=	gtk2-engines>=2.6.3:../../x11/gtk2-engines
DEPENDS+=	scrollkeeper>=0.3.14:../../textproc/scrollkeeper
DEPENDS+=	gnome-desktop>=2.10.2:../../x11/gnome-desktop
DEPENDS+=	gnome-menus>=2.10.2:../../sysutils/gnome-menus
DEPENDS+=	eel2>=2.10.1:../../devel/eel2
DEPENDS+=	nautilus>=2.10.1:../../sysutils/nautilus
DEPENDS+=	metacity>=2.10.2:../../wm/metacity
DEPENDS+=	gstreamer>=0.8.10:../../multimedia/gstreamer
DEPENDS+=	gst-plugins>=0.8.10:../../multimedia/gst-plugins
DEPENDS+=	gnome2-control-center>=2.10.2:../../x11/gnome2-control-center
DEPENDS+=	evolution-data-server>=1.2.3:../../mail/evolution-data-server
DEPENDS+=	gnome-panel>=2.10.2:../../x11/gnome-panel
DEPENDS+=	gucharmap>=1.4.3:../../fonts/gucharmap
DEPENDS+=	gnome-applets>=2.10.1:../../x11/gnome2-applets
DEPENDS+=	gnome-themes>=2.10.2:../../x11/gnome-themes
DEPENDS+=	gnome-backgrounds>=2.10.1:../../graphics/gnome-backgrounds
DEPENDS+=	vte>=0.11.13:../../x11/vte
DEPENDS+=	gnome2-terminal>=2.10.0:../../x11/gnome2-terminal
DEPENDS+=	gnome-session>=2.10.0:../../x11/gnome-session
# Not really part of GNOME, but we need it.
DEPENDS+=	xscreensaver>=4.16:../../x11/xscreensaver

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
