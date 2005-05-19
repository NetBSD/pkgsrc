# $NetBSD: Makefile,v 1.49 2005/05/19 21:13:51 jmmv Exp $

DISTNAME=	gnome-2.10.1
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
DEPENDS+=	gnome-base>=2.10.1:../../meta-pkgs/gnome-base
DEPENDS+=	at-spi>=1.6.3:../../devel/at-spi
DEPENDS+=	libgail-gnome>=1.1.0:../../devel/libgail-gnome
#DEPENDS+=	gtk-doc>=1.3:../../textproc/gtk-doc
DEPENDS+=	gtksourceview>=1.2.0:../../x11/gtksourceview
DEPENDS+=	gdm>=2.6.0.9:../../x11/gdm
DEPENDS+=	epiphany>=1.6.2:../../www/epiphany
DEPENDS+=	yelp>=2.6.5:../../misc/yelp
DEPENDS+=	zenity>=2.10.0:../../x11/zenity
DEPENDS+=	bug-buddy>=2.10.0:../../net/bug-buddy
DEPENDS+=	gnome-speech>=0.3.6:../../audio/gnome-speech
DEPENDS+=	dasher>=3.2.15:../../editors/dasher
DEPENDS+=	eog>=2.10.0:../../graphics/eog2
DEPENDS+=	file-roller>=2.10.2:../../archivers/file-roller
DEPENDS+=	gal2>=2.4.2:../../devel/gal2
DEPENDS+=	gcalctool>=5.5.42:../../math/gcalctool
DEPENDS+=	gconf-editor>=2.10.0:../../editors/gconf-editor
DEPENDS+=	gedit>=2.10.2:../../editors/gedit
DEPENDS+=	ggv>=2.8.4:../../print/ggv2
DEPENDS+=	gok>=1.0.3:../../misc/gok
DEPENDS+=	gnome-mag>=0.12.0:../../x11/gnome-mag
DEPENDS+=	gnopernicus>=0.10.6:../../x11/gnopernicus
DEPENDS+=	gpdf>=2.10.0:../../print/gpdf
DEPENDS+=	gnome-games>=2.10.1:../../games/gnome2-games
DEPENDS+=	gnome-media>=2.10.2:../../multimedia/gnome2-media
DEPENDS+=	gnome-netstatus>=2.10.0:../../net/gnome-netstatus
DEPENDS+=	gnome2-system-monitor>=2.10.1:../../sysutils/gnome2-system-monitor
DEPENDS+=	gnome-utils>=2.10.1:../../misc/gnome2-utils
DEPENDS+=	gnome2-user-docs>=2.8.1:../../misc/gnome2-user-docs
DEPENDS+=	nautilus-cd-burner>=2.10.1:../../sysutils/nautilus-cd-burner
DEPENDS+=	vino>=2.10.0:../../net/vino
DEPENDS+=	{totem>=1.0.1,totem-xine>=1.0.1}:../../multimedia/totem
DEPENDS+=	evolution-webcal>=2.2.1:../../time/evolution-webcal
DEPENDS+=	evolution>=2.2.2:../../mail/evolution
DEPENDS+=	ximian-connector>=2.2.2:../../mail/ximian-connector
#DEPENDS+=	gnome-nettool>=1.2.0:../../net/gnome-nettool
#DEPENDS+=	system-tools-backends>=1.2.0:../../sysutils/system-tools-backends
#DEPENDS+=	gnome-system-tools>=1.2.0:../../sysutils/gnome-system-tools
#DEPENDS+=	gnome-volume-manager>=1.2.1:../../sysutils/gnome-volume-manager
#DEPENDS+=	gnomemeeting>=1.2.1:../../net/gnomemeeting
#DEPENDS+=	sound-juicer>=2.10.1:../../audio/sound-juicer

USE_X11=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
