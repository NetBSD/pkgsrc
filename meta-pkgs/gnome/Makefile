# $NetBSD: Makefile,v 1.45 2005/01/04 23:49:23 jmmv Exp $

DISTNAME=	gnome-2.8.2
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
DEPENDS+=	gnome-base>=2.8.2:../../meta-pkgs/gnome-base
DEPENDS+=	at-spi>=1.6.1:../../devel/at-spi
DEPENDS+=	libgail-gnome>=1.1.0:../../devel/libgail-gnome
#DEPENDS+=	gtk-doc>=1.2:../../textproc/gtk-doc
DEPENDS+=	gtksourceview>=1.1.1:../../x11/gtksourceview
DEPENDS+=	gdm>=2.6.0.6:../../x11/gdm
DEPENDS+=	epiphany>=1.4.6:../../www/epiphany
DEPENDS+=	yelp>=2.6.5:../../misc/yelp
DEPENDS+=	zenity>=2.8.2:../../x11/zenity
DEPENDS+=	bug-buddy>=2.8.0:../../net/bug-buddy
DEPENDS+=	gnome-speech>=0.3.5:../../audio/gnome-speech
DEPENDS+=	dasher>=3.2.11:../../editors/dasher
DEPENDS+=	eog>=2.8.2:../../graphics/eog2
DEPENDS+=	file-roller>=2.8.3:../../archivers/file-roller
DEPENDS+=	gal2>=2.2.4:../../devel/gal2
DEPENDS+=	gcalctool>=4.4.20:../../math/gcalctool
DEPENDS+=	gconf-editor>=2.8.2:../../editors/gconf-editor
DEPENDS+=	gedit>=2.8.2:../../editors/gedit
DEPENDS+=	ggv>=2.8.1:../../print/ggv2
DEPENDS+=	gok>=0.11.16:../../misc/gok
DEPENDS+=	gnome-mag>=0.11.11:../../x11/gnome-mag
DEPENDS+=	gnopernicus>=0.9.18:../../x11/gnopernicus
DEPENDS+=	gpdf>=2.8.1:../../print/gpdf
DEPENDS+=	gucharmap>=1.4.2:../../fonts/gucharmap
DEPENDS+=	gnome-games>=2.8.2:../../games/gnome2-games
DEPENDS+=	gnome-media>=2.8.0:../../multimedia/gnome2-media
DEPENDS+=	gnome-netstatus>=2.8.0:../../net/gnome-netstatus
DEPENDS+=	gnome2-system-monitor>=2.8.1:../../sysutils/gnome2-system-monitor
DEPENDS+=	gnome-utils>=2.8.1:../../misc/gnome2-utils
DEPENDS+=	gnome2-user-docs>=2.8.1:../../misc/gnome2-user-docs
DEPENDS+=	nautilus-cd-burner>=2.8.6:../../sysutils/nautilus-cd-burner
DEPENDS+=	nautilus-media>=0.8.1:../../multimedia/nautilus-media
DEPENDS+=	vino>=2.8.1:../../net/vino
DEPENDS+=	evolution-webcal>=2.0.1:../../time/evolution-webcal
DEPENDS+=	evolution>=2.0.3:../../mail/evolution
#DEPENDS+=	gnome-nettool>=0.99.3:../../net/gnome-nettool
#DEPENDS+=	gnome-system-tools>=1.0.2:../../sysutils/gnome-system-tools
#DEPENDS+=	gnome-volume-manager>=1.0.2:../../sysutils/gnome-volume-manager
#DEPENDS+=	gnomemeeting>=1.0.2:../../net/gnomemeeting
#DEPENDS+=	ximian-connector>=2.0.3:../../mail/ximian-connector

USE_X11=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_BUILDLINK=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
