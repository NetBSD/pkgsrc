# $NetBSD: Makefile,v 1.37 2004/04/01 19:17:24 jmmv Exp $

DISTNAME=	gnome-2.6.0
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for the GNU Network Object Model Environment

DEPENDS+=	bug-buddy>=2.6.0:../../net/bug-buddy
DEPENDS+=	eog>=2.6.0:../../graphics/eog2
DEPENDS+=	epiphany>=1.2.2:../../www/epiphany
DEPENDS+=	file-roller>=2.6.0:../../archivers/file-roller
DEPENDS+=	gcalctool>=4.3.51:../../math/gcalctool
DEPENDS+=	gconf-editor>=2.6.0:../../editors/gconf-editor
DEPENDS+=	gedit>=2.6.0:../../editors/gedit
DEPENDS+=	ggv>=2.6.0:../../print/ggv2
DEPENDS+=	gnome-accessibility>=2.6.0:../../meta-pkgs/gnome-accessibility
DEPENDS+=	gnome-applets>=2.6.0:../../x11/gnome2-applets
DEPENDS+=	gnome-base>=2.6.0:../../meta-pkgs/gnome-base
DEPENDS+=	gnome-games>=2.6.0:../../games/gnome2-games
DEPENDS+=	gnome-media>=2.6.0:../../multimedia/gnome2-media
DEPENDS+=	gnome-netstatus>=2.6.0:../../net/gnome-netstatus
DEPENDS+=	gnome-themes>=2.6.0:../../x11/gnome-themes
DEPENDS+=	gnome2-user-docs>=2.6.0:../../misc/gnome2-user-docs
DEPENDS+=	gnome2-system-monitor>=2.6.0:../../sysutils/gnome2-system-monitor
DEPENDS+=	gnome-utils>=2.6.0:../../misc/gnome2-utils
DEPENDS+=	gpdf>=0.131:../../print/gpdf
DEPENDS+=	gstreamer>=0.8.0:../../multimedia/gstreamer
DEPENDS+=	gst-plugins>=0.8.0:../../multimedia/gst-plugins
DEPENDS+=	gucharmap>=1.4.0:../../fonts/gucharmap
DEPENDS+=	gtk2-extras>=2.4.0:../../meta-pkgs/gtk2-extras
DEPENDS+=	nautilus-cd-burner>=2.6.0:../../sysutils/nautilus-cd-burner
DEPENDS+=	nautilus-media>=0.8.0:../../multimedia/nautilus-media
DEPENDS+=	vera-ttf>=1.10:../../fonts/vera-ttf
DEPENDS+=	zenity>=2.6.0:../../x11/zenity

USE_X11=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_BUILDLINK=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
