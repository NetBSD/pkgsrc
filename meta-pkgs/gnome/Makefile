# $NetBSD: Makefile,v 1.56 2006/01/24 07:32:21 wiz Exp $

DISTNAME=	gnome-2.12.2
PKGREVISION=	1
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
DEPENDS+=	gnome-base>=2.12.2:../../meta-pkgs/gnome-base
DEPENDS+=	at-spi>=1.6.6:../../devel/at-spi
DEPENDS+=	libgail-gnome>=1.1.2:../../devel/libgail-gnome
#DEPENDS+=	gtk-doc>=1.4:../../textproc/gtk-doc
DEPENDS+=	gtksourceview>=1.4.2:../../x11/gtksourceview
DEPENDS+=	gdm>=2.8.0.7:../../x11/gdm
DEPENDS+=	epiphany>=1.8.3:../../www/epiphany
DEPENDS+=	yelp>=2.12.2:../../misc/yelp
DEPENDS+=	zenity>=2.12.1:../../x11/zenity
DEPENDS+=	bug-buddy>=2.12.1:../../net/bug-buddy
DEPENDS+=	gnome-speech>=0.3.9:../../audio/gnome-speech
DEPENDS+=	dasher>=3.2.18:../../editors/dasher
DEPENDS+=	eog>=2.12.0:../../graphics/eog2
DEPENDS+=	file-roller>=2.12.2:../../archivers/file-roller
DEPENDS+=	gcalctool>=5.6.31:../../math/gcalctool
DEPENDS+=	gconf-editor>=2.12.0:../../editors/gconf-editor
DEPENDS+=	gedit>=2.12.1:../../editors/gedit
DEPENDS+=	evince>=0.4.0:../../print/evince
DEPENDS+=	gok>=1.0.5:../../misc/gok
DEPENDS+=	gnome-mag>=0.12.2:../../x11/gnome-mag
DEPENDS+=	gnopernicus>=0.11.7:../../x11/gnopernicus
DEPENDS+=	gnome-games>=2.12.2:../../games/gnome2-games
DEPENDS+=	nautilus-cd-burner>=2.12.2:../../sysutils/nautilus-cd-burner
DEPENDS+=	gnome-media>=2.12.0:../../multimedia/gnome2-media
DEPENDS+=	gnome-netstatus>=2.12.0:../../net/gnome-netstatus
DEPENDS+=	gnome2-system-monitor>=2.12.1:../../sysutils/gnome2-system-monitor
DEPENDS+=	gnome-utils>=2.12.2:../../misc/gnome2-utils
DEPENDS+=	gnome2-user-docs>=2.8.1:../../misc/gnome2-user-docs
DEPENDS+=	vino>=2.12.0:../../net/vino
DEPENDS+=	{totem>=1.2.0,totem-xine>=1.2.0}:../../multimedia/totem
DEPENDS+=	evolution-webcal>=2.4.1:../../time/evolution-webcal
DEPENDS+=	evolution>=2.4.1:../../mail/evolution
DEPENDS+=	evolution-exchange>=2.4.1:../../mail/evolution-exchange
#DEPENDS+=	gnome-keyring-manager>=2.12.0:../../security/gnome-keyring-manager
#DEPENDS+=	gnome-nettool>=1.4.1:../../net/gnome-nettool
#DEPENDS+=	system-tools-backends>=1.4.1:../../sysutils/system-tools-backends
#DEPENDS+=	gnome-system-tools>=1.4.1:../../sysutils/gnome-system-tools
#DEPENDS+=	gnome-volume-manager>=1.5.4:../../sysutils/gnome-volume-manager
#DEPENDS+=	gnomemeeting>=1.2.2:../../net/gnomemeeting
#DEPENDS+=	sound-juicer>=2.12.3:../../audio/sound-juicer

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
