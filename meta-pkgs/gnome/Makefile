# $NetBSD: Makefile,v 1.67 2007/04/19 21:41:41 wiz Exp $

DISTNAME=	gnome-2.18.1
PKGREVISION=	1
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for the GNU Network Object Model Environment

.include "../../lang/python/pyversion.mk"

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
DEPENDS+=	gnome-base>=2.18.1:../../meta-pkgs/gnome-base
DEPENDS+=	at-spi>=1.18.1:../../devel/at-spi
DEPENDS+=	libgail-gnome>=1.1.3:../../devel/libgail-gnome
DEPENDS+=	gtksourceview>=1.8.5:../../x11/gtksourceview
DEPENDS+=	zenity>=2.18.1:../../x11/zenity
DEPENDS+=	gdm>=2.18.1:../../x11/gdm
DEPENDS+=	gnome-screensaver>=2.18.1:../../x11/gnome-screensaver
DEPENDS+=	fast-user-switch-applet>=2.18.0:../../x11/fast-user-switch-applet
DEPENDS+=	epiphany>=2.18.1:../../www/epiphany
DEPENDS+=	yelp>=2.18.1:../../misc/yelp
DEPENDS+=	bug-buddy>=2.18.1:../../net/bug-buddy
DEPENDS+=	gnome-speech>=0.4.11:../../audio/gnome-speech
DEPENDS+=	dasher>=4.4.1:../../editors/dasher
DEPENDS+=	eog>=2.18.1:../../graphics/eog2
DEPENDS+=	file-roller>=2.18.2:../../archivers/file-roller
DEPENDS+=	gcalctool>=5.9.14:../../math/gcalctool
DEPENDS+=	gconf-editor>=2.18.0:../../editors/gconf-editor
DEPENDS+=	gedit>=2.18.1:../../editors/gedit
DEPENDS+=	evince>=0.8.1:../../print/evince
DEPENDS+=	gok>=1.2.3:../../misc/gok
DEPENDS+=	gnome-mag>=0.14.3:../../x11/gnome-mag
DEPENDS+=	gnome-games>=2.18.1:../../games/gnome2-games
#DEPENDS+=	nautilus-cd-burner>=2.18.0:../../sysutils/nautilus-cd-burner
DEPENDS+=	gnome-media>=2.18.0:../../multimedia/gnome2-media
DEPENDS+=	gnome-netstatus>=2.12.1:../../net/gnome-netstatus
#DEPENDS+=	gnome2-system-monitor>=2.18.1.1:../../sysutils/gnome2-system-monitor
DEPENDS+=	gnome-utils>=2.18.1:../../misc/gnome2-utils
DEPENDS+=	gnome-user-docs>=2.18.1:../../misc/gnome-user-docs
DEPENDS+=	vino>=2.18.1:../../net/vino
DEPENDS+=	{totem>=2.18.1,totem-xine>=2.18.1}:../../multimedia/totem
DEPENDS+=	gnome-keyring-manager>=2.18.0:../../security/gnome-keyring-manager
DEPENDS+=	deskbar-applet>=2.18.1:../../misc/deskbar-applet
DEPENDS+=	evolution-webcal>=2.10.0:../../time/evolution-webcal
DEPENDS+=	evolution>=2.10.1:../../mail/evolution
DEPENDS+=	evolution-exchange>=2.10.1:../../mail/evolution-exchange
#DEPENDS+=	gnome-nettool>=2.18.0:../../net/gnome-nettool
#DEPENDS+=	system-tools-backends>=2.2.1:../../sysutils/system-tools-backends
#DEPENDS+=	gnome-system-tools>=2.18.1:../../sysutils/gnome-system-tools
#DEPENDS+=	gnome-volume-manager>=2.17.0:../../sysutils/gnome-volume-manager
#DEPENDS+=	sound-juicer>=2.16.3:../../audio/sound-juicer
#DEPENDS+=	ekiga>=2.0.9:../../net/ekiga
DEPENDS+=	${PYPKGPREFIX}-gnome2-desktop>=2.18.0:../../x11/py-gnome2-desktop
#DEPENDS+=	gnome-power-manager-2.16.0.tar.bz2
#DEPENDS+=	gnome-sharp-2.16.0.tar.bz2
DEPENDS+=	gnome-vfs-monikers>=2.15.3:../../sysutils/gnome-vfs-monikers
#DEPENDS+=	orca-1.0.0.tar.bz2
#DEPENDS+=	tomboy-0.4.0.tar.bz2

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
