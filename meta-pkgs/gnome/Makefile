# $NetBSD: Makefile,v 1.105 2008/12/04 16:47:59 wiz Exp $

DISTNAME=	gnome-2.24.1.96
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for the GNOME desktop

META_PACKAGE=	yes

.include "../../lang/python/pyversion.mk"

# see http://ftp.gnome.org/pub/GNOME/desktop/2.24/2.24.2/sources/

DEPENDS+=	alacarte>=0.11.6:../../x11/alacarte
DEPENDS+=	bug-buddy>=2.24.2:../../net/bug-buddy
DEPENDS+=	cheese>=2.24.2:../../graphics/cheese
DEPENDS+=	dasher>=4.9.0:../../editors/dasher
DEPENDS+=	deskbar-applet>=2.24.2:../../misc/deskbar-applet
DEPENDS+=	eel>=2.24.1:../../devel/eel
DEPENDS+=	ekiga>=3.0.1:../../net/ekiga
DEPENDS+=	empathy>=2.24.1:../../chat/empathy
DEPENDS+=	eog>=2.24.2:../../graphics/eog
DEPENDS+=	epiphany>=2.24.2.1:../../www/epiphany
DEPENDS+=	evince>=2.24.2:../../print/evince
DEPENDS+=	evolution>=2.24.2:../../mail/evolution
DEPENDS+=	evolution-data-server>=2.24.2:../../mail/evolution-data-server
DEPENDS+=	evolution-exchange>=2.24.2:../../mail/evolution-exchange
DEPENDS+=	evolution-webcal>=2.24.0:../../time/evolution-webcal
DEPENDS+=	file-roller>=2.24.2:../../archivers/file-roller
DEPENDS+=	gcalctool>=5.24.2:../../math/gcalctool
DEPENDS+=	gconf-editor>=2.24.1:../../editors/gconf-editor
# too old
#DEPENDS+=	gdm>=2.24.1:../../x11/gdm
DEPENDS+=	gdm-[0-9]*:../../x11/gdm
DEPENDS+=	gedit>=2.24.2:../../editors/gedit
DEPENDS+=	gnome-applets>=2.24.2:../../x11/gnome-applets
DEPENDS+=	gnome-backgrounds>=2.24.0:../../graphics/gnome-backgrounds
DEPENDS+=	gnome-control-center>=2.24.0.1:../../x11/gnome-control-center
DEPENDS+=	gnome-desktop>=2.24.2:../../x11/gnome-desktop
DEPENDS+=	gnome-desktop-sharp>=2.24.0:../../x11/gnome-desktop-sharp
DEPENDS+=	gnome-doc-utils>=0.14.0:../../textproc/gnome-doc-utils
DEPENDS+=	gnome-games>=2.24.2:../../games/gnome-games
DEPENDS+=	gnome-icon-theme>=2.24.0:../../graphics/gnome-icon-theme
DEPENDS+=	gnome-keyring>=2.24.1:../../security/gnome-keyring
DEPENDS+=	gnome-mag>=0.15.4:../../x11/gnome-mag
DEPENDS+=	gnome-media>=2.24.0.1:../../multimedia/gnome-media
DEPENDS+=	gnome-menus>=2.24.2:../../sysutils/gnome-menus
DEPENDS+=	gnome-netstatus>=2.12.2:../../net/gnome-netstatus
DEPENDS+=	gnome-nettool>=2.22.1:../../net/gnome-nettool
DEPENDS+=	gnome-panel>=2.24.2:../../x11/gnome-panel
DEPENDS+=	gnome-power-manager>=2.24.2:../../sysutils/gnome-power-manager
DEPENDS+=	${PYPKGPREFIX}-gnome2-desktop>=2.24.0:../../x11/py-gnome2-desktop
DEPENDS+=	gnome-screensaver>=2.24.1:../../x11/gnome-screensaver
DEPENDS+=	gnome-session>=2.24.2:../../x11/gnome-session
DEPENDS+=	gnome-settings-daemon>=2.24.1:../../sysutils/gnome-settings-daemon
DEPENDS+=	gnome-sharp>=2.24.0:../../x11/gnome-sharp
DEPENDS+=	gnome-speech>=0.4.22:../../audio/gnome-speech
DEPENDS+=	gnome-system-monitor>=2.24.1:../../sysutils/gnome-system-monitor
DEPENDS+=	gnome-system-tools>=2.22.1:../../sysutils/gnome-system-tools
DEPENDS+=	gnome-terminal>=2.24.2:../../x11/gnome-terminal
DEPENDS+=	gnome-themes>=2.24.1:../../x11/gnome-themes
DEPENDS+=	gnome-user-docs>=2.24.0:../../misc/gnome-user-docs
DEPENDS+=	gnome-utils>=2.24.1:../../misc/gnome-utils
DEPENDS+=	gnome-volume-manager>=2.24.0:../../sysutils/gnome-volume-manager
DEPENDS+=	gok>=2.24.0:../../misc/gok
DEPENDS+=	gst-plugins0.10-base>=0.10.21:../../multimedia/gst-plugins0.10-base
DEPENDS+=	gst-plugins0.10-good>=0.10.10:../../multimedia/gst-plugins0.10-good
DEPENDS+=	gstreamer0.10>=0.10.21:../../multimedia/gstreamer0.10
DEPENDS+=	gtk2-engines>=2.16.1:../../x11/gtk2-engines
DEPENDS+=	gtkhtml314>=3.24.2:../../www/gtkhtml314
DEPENDS+=	gtksourceview2>=2.4.1:../../x11/gtksourceview2
DEPENDS+=	gucharmap>=2.24.2:../../fonts/gucharmap
DEPENDS+=	gvfs>=1.0.3:../../sysutils/gvfs
DEPENDS+=	hamster-applet>=2.24.2:../../time/hamster-applet
DEPENDS+=	libgail-gnome>=1.20.1:../../devel/libgail-gnome
DEPENDS+=	libgnomekbd>=2.24.0:../../x11/libgnomekbd
DEPENDS+=	libgnomeprint>=2.18.5:../../print/libgnomeprint
DEPENDS+=	libgnomeprintui>=2.18.3:../../print/libgnomeprintui
DEPENDS+=	libgtop>=2.24.0:../../sysutils/libgtop
DEPENDS+=	libgweather>=2.24.2:../../devel/libgweather
DEPENDS+=	liboobs>=2.22.0:../../sysutils/liboobs
DEPENDS+=	librsvg>=2.22.3:../../graphics/librsvg
DEPENDS+=	libsoup24>=2.24.2.1:../../net/libsoup24
DEPENDS+=	libwnck>=2.24.2:../../devel/libwnck
DEPENDS+=	metacity>=2.24.0:../../wm/metacity
DEPENDS+=	mousetweaks>=2.24.2:../../misc/mousetweaks
DEPENDS+=	nautilus>=2.24.2:../../sysutils/nautilus
DEPENDS+=	nautilus-cd-burner>=2.24.0:../../sysutils/nautilus-cd-burner
DEPENDS+=	orca>=2.24.2:../../misc/orca
DEPENDS+=	${PYPKGPREFIX}-gtksourceview>=2.4.0:../../x11/py-gtksourceview
DEPENDS+=	seahorse>=2.24.1:../../security/seahorse
DEPENDS+=	seahorse-plugins>=2.24.1:../../security/seahorse-plugins
DEPENDS+=	sound-juicer>=2.24.0:../../audio/sound-juicer
DEPENDS+=	sound-theme-freedesktop>=0.2:../../audio/sound-theme-freedesktop
DEPENDS+=	swfdec-gnome>=2.24.0:../../multimedia/swfdec-gnome
DEPENDS+=	tomboy>=0.12.1:../../editors/tomboy
DEPENDS+=	totem>=2.24.3:../../multimedia/totem
DEPENDS+=	totem-pl-parser>=2.24.2:../../multimedia/totem-pl-parser
# packaged in wip, doesn't work
#DEPENDS+=	vinagre>=2.24.1:../../*/vinagre
DEPENDS+=	vino>=2.24.1:../../net/vino
DEPENDS+=	vte>=0.17.4:../../x11/vte
DEPENDS+=	yelp>=2.24.0:../../misc/yelp
DEPENDS+=	zenity>=2.24.0:../../x11/zenity

.include "../../mk/bsd.pkg.mk"
