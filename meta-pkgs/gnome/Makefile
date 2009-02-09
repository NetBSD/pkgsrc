# $NetBSD: Makefile,v 1.113 2009/02/09 22:56:25 joerg Exp $

DISTNAME=	gnome-2.24.2.90
PKGREVISION=		1
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for the GNOME desktop

META_PACKAGE=	yes

.include "../../lang/python/pyversion.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnome
PKG_SUPPORTED_OPTIONS=	pulseaudio
PKG_SUGGESTED_OPTIONS=	pulseaudio
.include "../../mk/bsd.options.mk"

# see http://ftp.gnome.org/pub/GNOME/desktop/2.24/2.24.3/sources/

DEPENDS+=	alacarte>=0.11.6:../../x11/alacarte
DEPENDS+=	bug-buddy>=2.24.2:../../net/bug-buddy
DEPENDS+=	cheese>=2.24.3:../../graphics/cheese
DEPENDS+=	dasher>=4.9.0:../../editors/dasher
DEPENDS+=	deskbar-applet>=2.24.3:../../misc/deskbar-applet
DEPENDS+=	eel>=2.24.1:../../devel/eel
# needs opal->ffmpeg->lame, which has a special license
#DEPENDS+=	ekiga>=3.0.2:../../net/ekiga
DEPENDS+=	empathy>=2.24.1:../../chat/empathy
DEPENDS+=	eog>=2.24.3.1:../../graphics/eog
DEPENDS+=	epiphany>=2.24.3:../../www/epiphany
DEPENDS+=	evince>=2.24.2:../../print/evince
DEPENDS+=	evolution>=2.24.3:../../mail/evolution
DEPENDS+=	evolution-data-server>=2.24.3:../../mail/evolution-data-server
DEPENDS+=	evolution-exchange>=2.24.3:../../mail/evolution-exchange
DEPENDS+=	evolution-webcal>=2.24.0:../../time/evolution-webcal
DEPENDS+=	file-roller>=2.24.3:../../archivers/file-roller
DEPENDS+=	gcalctool>=5.24.3:../../math/gcalctool
DEPENDS+=	gconf-editor>=2.24.1:../../editors/gconf-editor
# too old
#DEPENDS+=	gdm>=2.24.1:../../x11/gdm
DEPENDS+=	gdm-[0-9]*:../../x11/gdm
DEPENDS+=	gedit>=2.24.3:../../editors/gedit
DEPENDS+=	gnome-applets>=2.24.3.1:../../x11/gnome-applets
DEPENDS+=	gnome-backgrounds>=2.24.0:../../graphics/gnome-backgrounds
DEPENDS+=	gnome-control-center>=2.24.0.1:../../x11/gnome-control-center
DEPENDS+=	gnome-desktop>=2.24.3:../../x11/gnome-desktop
DEPENDS+=	gnome-desktop-sharp>=2.24.0:../../x11/gnome-desktop-sharp
DEPENDS+=	gnome-doc-utils>=0.14.2:../../textproc/gnome-doc-utils
DEPENDS+=	gnome-games>=2.24.3:../../games/gnome-games
DEPENDS+=	gnome-icon-theme>=2.24.0:../../graphics/gnome-icon-theme
DEPENDS+=	gnome-keyring>=2.24.1:../../security/gnome-keyring
.if ${X11_TYPE} != "native" || exists(${X11BASE}/lib/libXdamage.so)
DEPENDS+=	gnome-mag>=0.15.4:../../x11/gnome-mag
.endif
DEPENDS+=	gnome-media>=2.24.0.1:../../multimedia/gnome-media
DEPENDS+=	gnome-menus>=2.24.2:../../sysutils/gnome-menus
DEPENDS+=	gnome-netstatus>=2.12.2:../../net/gnome-netstatus
DEPENDS+=	gnome-nettool>=2.22.1:../../net/gnome-nettool
DEPENDS+=	gnome-panel>=2.24.3:../../x11/gnome-panel
.if ${X11_TYPE} != "native" || exists(${X11BASE}/lib/pkgconfig/xrender.pc)
DEPENDS+=	gnome-power-manager>=2.24.2:../../sysutils/gnome-power-manager
.endif
DEPENDS+=	${PYPKGPREFIX}-gnome2-desktop>=2.24.1:../../x11/py-gnome2-desktop
DEPENDS+=	gnome-screensaver>=2.24.1:../../x11/gnome-screensaver
DEPENDS+=	gnome-session>=2.24.3:../../x11/gnome-session
DEPENDS+=	gnome-settings-daemon>=2.24.1:../../sysutils/gnome-settings-daemon
DEPENDS+=	gnome-sharp>=2.24.0:../../x11/gnome-sharp
DEPENDS+=	gnome-speech>=0.4.22:../../audio/gnome-speech
DEPENDS+=	gnome-system-monitor>=2.24.3:../../sysutils/gnome-system-monitor
DEPENDS+=	gnome-system-tools>=2.22.1:../../sysutils/gnome-system-tools
DEPENDS+=	gnome-terminal>=2.24.3:../../x11/gnome-terminal
DEPENDS+=	gnome-themes>=2.24.3:../../x11/gnome-themes
DEPENDS+=	gnome-user-docs>=2.24.2:../../misc/gnome-user-docs
DEPENDS+=	gnome-utils>=2.24.1:../../misc/gnome-utils
DEPENDS+=	gnome-volume-manager>=2.24.0:../../sysutils/gnome-volume-manager
DEPENDS+=	gok>=2.24.0:../../misc/gok
DEPENDS+=	gst-plugins0.10-base>=0.10.21:../../multimedia/gst-plugins0.10-base
DEPENDS+=	gst-plugins0.10-good>=0.10.10:../../multimedia/gst-plugins0.10-good
.if !empty(PKG_OPTIONS:Mpulseaudio)
DEPENDS+=	gst-plugins0.10-pulse>=0.10.11:../../audio/gst-plugins0.10-pulse
.endif
DEPENDS+=	gstreamer0.10>=0.10.21:../../multimedia/gstreamer0.10
DEPENDS+=	gtk2-engines>=2.16.1:../../x11/gtk2-engines
DEPENDS+=	gtkhtml314>=3.24.3:../../www/gtkhtml314
DEPENDS+=	gtksourceview2>=2.4.2:../../x11/gtksourceview2
DEPENDS+=	gucharmap>=2.24.3:../../fonts/gucharmap
DEPENDS+=	gvfs>=1.0.3:../../sysutils/gvfs
DEPENDS+=	hamster-applet>=2.24.3:../../time/hamster-applet
DEPENDS+=	libgail-gnome>=1.20.1:../../devel/libgail-gnome
DEPENDS+=	libgnomekbd>=2.24.0:../../x11/libgnomekbd
DEPENDS+=	libgnomeprint>=2.18.5:../../print/libgnomeprint
DEPENDS+=	libgnomeprintui>=2.18.3:../../print/libgnomeprintui
DEPENDS+=	libgtop>=2.24.3:../../sysutils/libgtop
DEPENDS+=	libgweather>=2.24.3:../../devel/libgweather
DEPENDS+=	liboobs>=2.22.0:../../sysutils/liboobs
DEPENDS+=	librsvg>=2.22.3:../../graphics/librsvg
DEPENDS+=	libsoup24>=2.24.3:../../net/libsoup24
DEPENDS+=	libwnck>=2.24.2:../../devel/libwnck
DEPENDS+=	metacity>=2.24.0:../../wm/metacity
.if ${X11_TYPE} != "native" || exists(${X11BASE}/lib/pkgconfig/xtst.pc)
DEPENDS+=	mousetweaks>=2.24.3:../../misc/mousetweaks
.endif
DEPENDS+=	nautilus>=2.24.2:../../sysutils/nautilus
DEPENDS+=	nautilus-cd-burner>=2.24.0:../../sysutils/nautilus-cd-burner
.if ${X11_TYPE} != "native" || exists(${X11BASE}/lib/libXdamage.so)
DEPENDS+=	orca>=2.24.3:../../misc/orca
.endif
DEPENDS+=	${PYPKGPREFIX}-gtksourceview>=2.4.0:../../x11/py-gtksourceview
DEPENDS+=	seahorse>=2.24.1:../../security/seahorse
DEPENDS+=	seahorse-plugins>=2.24.1:../../security/seahorse-plugins
DEPENDS+=	sound-juicer>=2.24.0:../../audio/sound-juicer
#DEPENDS+=	sound-theme-freedesktop>=0.2:../../audio/sound-theme-freedesktop
DEPENDS+=	swfdec-gnome>=2.24.0:../../multimedia/swfdec-gnome
DEPENDS+=	tomboy>=0.12.2:../../editors/tomboy
DEPENDS+=	totem>=2.24.3:../../multimedia/totem
DEPENDS+=	totem-pl-parser>=2.24.3:../../multimedia/totem-pl-parser
# packaged in wip, doesn't work
#DEPENDS+=	vinagre>=2.24.2:../../*/vinagre
DEPENDS+=	vino>=2.24.1:../../net/vino
DEPENDS+=	vte>=0.17.4:../../x11/vte
DEPENDS+=	yelp>=2.24.0:../../misc/yelp
DEPENDS+=	zenity>=2.24.1:../../x11/zenity

.include "../../mk/bsd.pkg.mk"
