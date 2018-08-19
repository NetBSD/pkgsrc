# $NetBSD: Makefile,v 1.141 2018/08/19 20:16:40 wiz Exp $

DISTNAME=	gnome-2.26.2
PKGREVISION=	5
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Meta-package for the GNOME desktop

META_PACKAGE=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-ORBit via py-gnome2

.include "../../lang/python/pyversion.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnome
PKG_SUPPORTED_OPTIONS=	pulseaudio mono
PKG_SUGGESTED_OPTIONS=	pulseaudio
# mono does not work on NetBSD/arm yet
.if ${OPSYS} != "SunOS" && (${OPSYS} != "NetBSD" || empty(MACHINE_ARCH:M*arm*))
PKG_SUGGESTED_OPTIONS+=	mono
.endif
.include "../../mk/bsd.options.mk"

# see http://ftp.gnome.org/pub/GNOME/desktop/2.26/2.26.2/sources/

DEPENDS+=	alacarte>=0.12.1:../../x11/alacarte
DEPENDS+=	brasero>=2.26.2:../../sysutils/brasero
DEPENDS+=	bug-buddy>=2.26.0:../../net/bug-buddy
DEPENDS+=	cheese>=2.26.2:../../graphics/cheese
DEPENDS+=	dasher>=4.10.1:../../editors/dasher
DEPENDS+=	deskbar-applet>=2.26.2:../../misc/deskbar-applet
# needs opal->ffmpeg->lame, which has a special license
#DEPENDS+=	ekiga>=3.2.1:../../net/ekiga
DEPENDS+=	empathy>=2.26.2:../../chat/empathy
DEPENDS+=	eog>=2.26.2<3:../../graphics/eog
DEPENDS+=	epiphany>=2.26.2:../../www/epiphany
DEPENDS+=	evince>=2.26.2<3:../../print/evince
DEPENDS+=	evolution>=2.26.2:../../mail/evolution
DEPENDS+=	evolution-data-server>=2.26.2:../../mail/evolution-data-server
DEPENDS+=	evolution-exchange>=2.26.2:../../mail/evolution-exchange
# XXX: unpackaged
#DEPENDS+=	evolution-mapi>=0.27.1:../../mail/evolution-mapi
DEPENDS+=	evolution-webcal>=2.26.0:../../time/evolution-webcal
DEPENDS+=	file-roller>=2.26.2:../../archivers/file-roller
DEPENDS+=	gcalctool>=5.26.2:../../math/gcalctool
DEPENDS+=	gconf-editor>=2.26.0:../../editors/gconf-editor
#DEPENDS+=	gdm>=2.26.1:../../x11/gdm
DEPENDS+=	gdm>=2.20.10:../../x11/gdm
DEPENDS+=	gedit>=2.26.2<3:../../editors/gedit
DEPENDS+=	gio-fam>=2.26.1:../../sysutils/gio-fam
DEPENDS+=	gnome-applets>=2.26.1:../../x11/gnome-applets
DEPENDS+=	gnome-backgrounds>=2.24.1:../../graphics/gnome-backgrounds
DEPENDS+=	gnome-control-center>=2.26.0:../../x11/gnome-control-center
DEPENDS+=	gnome-desktop>=2.26.2:../../x11/gnome-desktop
.if !empty(PKG_OPTIONS:Mmono)
DEPENDS+=	gnome-desktop-sharp>=2.26.0:../../x11/gnome-desktop-sharp
.endif
DEPENDS+=	gnome-doc-utils>=0.16.1:../../textproc/gnome-doc-utils
DEPENDS+=	gnome-games>=2.26.2:../../games/gnome-games
DEPENDS+=	gnome-icon-theme>=2.26.0:../../graphics/gnome-icon-theme
DEPENDS+=	gnome-keyring>=2.26.1:../../security/gnome-keyring
.if ${X11_TYPE} != "native" || exists(${X11BASE}/lib/libXdamage.so)
DEPENDS+=	gnome-mag>=0.15.6:../../x11/gnome-mag
.endif
DEPENDS+=	gnome-media>=2.26.0:../../multimedia/gnome-media
DEPENDS+=	gnome-menus>=2.26.1:../../sysutils/gnome-menus
DEPENDS+=	gnome-netstatus>=2.26.0:../../net/gnome-netstatus
DEPENDS+=	gnome-nettool>=2.26.1:../../net/gnome-nettool
DEPENDS+=	gnome-panel>=2.26.2:../../x11/gnome-panel
.if ${X11_TYPE} != "native" || exists(${X11BASE}/lib/pkgconfig/xrender.pc)
#DEPENDS+=	gnome-power-manager>=2.26.1:../../sysutils/gnome-power-manager
DEPENDS+=	gnome-power-manager>=2.24.2:../../sysutils/gnome-power-manager
.endif
DEPENDS+=	${PYPKGPREFIX}-gnome2-desktop>=2.26.0:../../x11/py-gnome2-desktop
DEPENDS+=	gnome-screensaver>=2.26.1:../../x11/gnome-screensaver
DEPENDS+=	gnome-session>=2.26.1:../../x11/gnome-session
DEPENDS+=	gnome-settings-daemon>=2.26.1:../../sysutils/gnome-settings-daemon
.if !empty(PKG_OPTIONS:Mmono)
DEPENDS+=	gnome-sharp>=2.24.1:../../x11/gnome-sharp
.endif
DEPENDS+=	gnome-speech>=0.4.25:../../audio/gnome-speech
DEPENDS+=	gnome-system-monitor>=2.26.1:../../sysutils/gnome-system-monitor
DEPENDS+=	gnome-system-tools>=2.22.2:../../sysutils/gnome-system-tools
DEPENDS+=	gnome-terminal>=2.26.2:../../x11/gnome-terminal
DEPENDS+=	gnome-themes>=2.26.2:../../x11/gnome-themes
DEPENDS+=	gnome-user-docs>=2.26.2:../../misc/gnome-user-docs
# unpackaged
#DEPENDS+=	gnome-user-share>=2.26.0:../../misc/gnome-user-share
DEPENDS+=	gnome-utils>=2.26.0:../../misc/gnome-utils
DEPENDS+=	gok>=2.26.0:../../misc/gok
DEPENDS+=	gst-plugins0.10-base>=0.10.23:../../multimedia/gst-plugins0.10-base
DEPENDS+=	gst-plugins0.10-good>=0.10.14:../../multimedia/gst-plugins0.10-good
.if !empty(PKG_OPTIONS:Mpulseaudio)
DEPENDS+=	gst-plugins0.10-pulse>=0.10.14:../../audio/gst-plugins0.10-pulse
.endif
DEPENDS+=	gstreamer0.10>=0.10.23:../../multimedia/gstreamer0.10
DEPENDS+=	gtk2-engines>=2.18.2:../../x11/gtk2-engines
DEPENDS+=	gtkhtml314>=3.26.2:../../www/gtkhtml314
DEPENDS+=	gtksourceview2>=2.6.2:../../x11/gtksourceview2
DEPENDS+=	gucharmap>=2.26.2:../../fonts/gucharmap
DEPENDS+=	gvfs>=1.2.3:../../sysutils/gvfs
DEPENDS+=	hamster-applet>=2.26.2:../../time/hamster-applet
DEPENDS+=	libgail-gnome>=1.20.1:../../devel/libgail-gnome
DEPENDS+=	libgnomekbd>=2.26.0:../../x11/libgnomekbd
DEPENDS+=	libgnomeprint>=2.18.6:../../print/libgnomeprint
DEPENDS+=	libgnomeprintui>=2.18.4:../../print/libgnomeprintui
DEPENDS+=	libgtop>=2.26.1:../../sysutils/libgtop
DEPENDS+=	libgweather>=2.26.1:../../devel/libgweather
DEPENDS+=	liboobs>=2.22.0:../../sysutils/liboobs
DEPENDS+=	librsvg>=2.26.0:../../graphics/librsvg
DEPENDS+=	libsoup>=2.26.2:../../net/libsoup
DEPENDS+=	libwnck>=2.26.1:../../devel/libwnck
DEPENDS+=	metacity>=2.26.0:../../wm/metacity
.if ${X11_TYPE} != "native" || exists(${X11BASE}/lib/pkgconfig/xtst.pc)
DEPENDS+=	mousetweaks>=2.26.2:../../misc/mousetweaks
.endif
DEPENDS+=	nautilus>=2.26.3:../../sysutils/nautilus
.if ${X11_TYPE} != "native" || exists(${X11BASE}/lib/libXdamage.so)
DEPENDS+=	orca>=2.26.2:../../misc/orca
.endif
DEPENDS+=	${PYPKGPREFIX}-gtksourceview>=2.6.0:../../x11/py-gtksourceview
DEPENDS+=	seahorse>=2.26.1:../../security/seahorse
DEPENDS+=	seahorse-plugins>=2.26.1:../../security/seahorse-plugins
DEPENDS+=	sound-juicer>=2.26.1:../../audio/sound-juicer
DEPENDS+=	swfdec-gnome>=2.26.0:../../multimedia/swfdec-gnome
.if !empty(PKG_OPTIONS:Mmono)
DEPENDS+=	tomboy>=0.14.2:../../editors/tomboy
.endif
DEPENDS+=	totem>=2.26.2:../../multimedia/totem
DEPENDS+=	totem-pl-parser>=2.26.2:../../multimedia/totem-pl-parser
DEPENDS+=	vinagre>=2.26.2:../../net/vinagre
# compilation errors on NetBSD, see wip/vino
#DEPENDS+=	vino>=2.26.2:../../net/vino
DEPENDS+=	vino>=2.24.1:../../net/vino
DEPENDS+=	vte>=0.20.2<0.32:../../x11/vte
DEPENDS+=	yelp>=2.26.0:../../misc/yelp
DEPENDS+=	zenity>=2.26.0:../../x11/zenity

.include "../../mk/bsd.pkg.mk"
