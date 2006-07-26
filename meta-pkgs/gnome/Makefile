# $NetBSD: Makefile,v 1.60 2006/07/26 12:49:06 drochner Exp $

DISTNAME=	gnome-2.14.0
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
DEPENDS+=	gnome-base>=2.14.0:../../meta-pkgs/gnome-base
DEPENDS+=	at-spi>=1.7.6:../../devel/at-spi
DEPENDS+=	libgail-gnome>=1.1.3:../../devel/libgail-gnome
DEPENDS+=	gtksourceview>=1.6.0:../../x11/gtksourceview
DEPENDS+=	zenity>=2.14.0:../../x11/zenity
DEPENDS+=	gdm>=2.14.0nb1:../../x11/gdm
DEPENDS+=	gnome-screensaver>=2.14.0:../../x11/gnome-screensaver
DEPENDS+=	fast-user-switch-applet>=2.14.0:../../x11/fast-user-switch-applet
DEPENDS+=	epiphany>=2.14.0:../../www/epiphany
DEPENDS+=	yelp>=2.14.0:../../misc/yelp
DEPENDS+=	bug-buddy>=2.14.0:../../net/bug-buddy
DEPENDS+=	gnome-speech>=0.3.10:../../audio/gnome-speech
DEPENDS+=	dasher>=4.0.0:../../editors/dasher
DEPENDS+=	eog>=2.14.0:../../graphics/eog2
DEPENDS+=	file-roller>=2.14.0:../../archivers/file-roller
DEPENDS+=	gcalctool>=5.7.32:../../math/gcalctool
DEPENDS+=	gconf-editor>=2.14.0:../../editors/gconf-editor
DEPENDS+=	gedit>=2.14.0:../../editors/gedit
DEPENDS+=	evince>=0.5.2:../../print/evince
DEPENDS+=	gok>=1.0.7:../../misc/gok
DEPENDS+=	gnome-mag>=0.12.4:../../x11/gnome-mag
DEPENDS+=	gnopernicus>=1.0.3:../../x11/gnopernicus
DEPENDS+=	gnome-games>=2.14.0:../../games/gnome2-games
DEPENDS+=	nautilus-cd-burner>=2.14.0.2:../../sysutils/nautilus-cd-burner
DEPENDS+=	gnome-media>=2.14.0:../../multimedia/gnome2-media
DEPENDS+=	gnome-netstatus>=2.12.0:../../net/gnome-netstatus
DEPENDS+=	gnome2-system-monitor>=2.14.0:../../sysutils/gnome2-system-monitor
DEPENDS+=	gnome-utils>=2.14.0:../../misc/gnome2-utils
DEPENDS+=	gnome-user-docs>=2.14.0:../../misc/gnome-user-docs
DEPENDS+=	vino>=2.13.5:../../net/vino
DEPENDS+=	{totem>=1.4.0,totem-xine>=1.4.0}:../../multimedia/totem
DEPENDS+=	gnome-keyring-manager>=2.14.0:../../security/gnome-keyring-manager
DEPENDS+=	deskbar-applet>=2.14.0.1:../../misc/deskbar-applet
DEPENDS+=	evolution-webcal>=2.5.90:../../time/evolution-webcal
DEPENDS+=	evolution>=2.6.0nb2:../../mail/evolution
DEPENDS+=	evolution-exchange>=2.6.0:../../mail/evolution-exchange
#DEPENDS+=	gnome-nettool>=2.13.91:../../net/gnome-nettool
#DEPENDS+=	system-tools-backends>=1.4.2:../../sysutils/system-tools-backends
#DEPENDS+=	gnome-system-tools>=2.14.0:../../sysutils/gnome-system-tools
#DEPENDS+=	gnome-volume-manager>=1.5.15:../../sysutils/gnome-volume-manager
#DEPENDS+=	sound-juicer>=2.14.0:../../audio/sound-juicer
#DEPENDS+=	ekiga-2.0.1:../../net/ekiga
#DEPENDS+=	gnome-python-desktop>=2.14.0

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
