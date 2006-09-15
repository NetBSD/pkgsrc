# $NetBSD: Makefile,v 1.62 2006/09/15 15:25:26 jmmv Exp $

DISTNAME=	gnome-2.16.0
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for the GNU Network Object Model Environment

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
DEPENDS+=	gnome-base>=2.16.0:../../meta-pkgs/gnome-base
DEPENDS+=	at-spi>=1.7.11:../../devel/at-spi
DEPENDS+=	libgail-gnome>=1.1.3:../../devel/libgail-gnome
DEPENDS+=	gtksourceview>=1.8.0:../../x11/gtksourceview
DEPENDS+=	zenity>=2.16.0:../../x11/zenity
DEPENDS+=	gdm>=2.16.0:../../x11/gdm
DEPENDS+=	gnome-screensaver>=2.16.0:../../x11/gnome-screensaver
DEPENDS+=	fast-user-switch-applet>=2.16.0:../../x11/fast-user-switch-applet
DEPENDS+=	epiphany>=2.16.0:../../www/epiphany
DEPENDS+=	yelp>=2.16.0:../../misc/yelp
DEPENDS+=	bug-buddy>=2.16.0:../../net/bug-buddy
DEPENDS+=	gnome-speech>=0.4.5:../../audio/gnome-speech
DEPENDS+=	dasher>=4.2.0:../../editors/dasher
DEPENDS+=	eog>=2.16.0.1:../../graphics/eog2
DEPENDS+=	file-roller>=2.16.0:../../archivers/file-roller
DEPENDS+=	gcalctool>=5.8.24:../../math/gcalctool
DEPENDS+=	gconf-editor>=2.16.0:../../editors/gconf-editor
DEPENDS+=	gedit>=2.16.0:../../editors/gedit
DEPENDS+=	evince>=0.6.0:../../print/evince
DEPENDS+=	gok>=1.2.0:../../misc/gok
DEPENDS+=	gnome-mag>=0.13.1:../../x11/gnome-mag
DEPENDS+=	gnome-games>=2.15.92:../../games/gnome2-games
#DEPENDS+=	nautilus-cd-burner>=2.16.0:../../sysutils/nautilus-cd-burner
DEPENDS+=	gnome-media>=2.16.1:../../multimedia/gnome2-media
DEPENDS+=	gnome-netstatus>=2.12.0:../../net/gnome-netstatus
DEPENDS+=	gnome2-system-monitor>=2.15.92:../../sysutils/gnome2-system-monitor
DEPENDS+=	gnome-utils>=2.16.0:../../misc/gnome2-utils
DEPENDS+=	gnome-user-docs>=2.16.0:../../misc/gnome-user-docs
DEPENDS+=	vino>=2.13.5:../../net/vino
DEPENDS+=	{totem>=2.16.0,totem-xine>=2.16.0}:../../multimedia/totem
DEPENDS+=	gnome-keyring-manager>=2.16.0:../../security/gnome-keyring-manager
DEPENDS+=	deskbar-applet>=2.16.0:../../misc/deskbar-applet
DEPENDS+=	evolution-webcal>=2.8.0:../../time/evolution-webcal
DEPENDS+=	evolution>=2.8.0:../../mail/evolution
DEPENDS+=	evolution-exchange>=2.8.0:../../mail/evolution-exchange
#DEPENDS+=	gnome-nettool>=2.15.92:../../net/gnome-nettool
#DEPENDS+=	system-tools-backends>=1.4.2:../../sysutils/system-tools-backends
#DEPENDS+=	gnome-system-tools>=2.14.0:../../sysutils/gnome-system-tools
#DEPENDS+=	gnome-volume-manager>=2.15.0:../../sysutils/gnome-volume-manager
#DEPENDS+=	sound-juicer>=2.16.0:../../audio/sound-juicer
#DEPENDS+=	ekiga-2.0.3:../../net/ekiga
#DEPENDS+=	gnome-python-desktop>=2.16.0
#DEPENDS+=	gnome-power-manager-2.16.0.tar.bz2
#DEPENDS+=	gnome-sharp-2.16.0.tar.bz2
#DEPENDS+=	gnome-vfs-monikers-2.15.3.tar.bz2
#DEPENDS+=	orca-1.0.0.tar.bz2
#DEPENDS+=	tomboy-0.4.0.tar.bz2

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
