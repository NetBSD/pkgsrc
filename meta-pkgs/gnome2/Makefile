# $NetBSD: Makefile,v 1.12 2003/12/13 00:45:24 wiz Exp $

DISTNAME=	gnome-2.2.6
PKGREVISION=	1
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for the GNU Network Object Model Environment

DEPENDS+=	balsa>=2.0.10:../../mail/balsa2
DEPENDS+=	eog>=2.2.0nb3:../../graphics/eog2
DEPENDS+=	file-roller>=2.2.1nb1:../../archivers/file-roller
DEPENDS+=	gcalctool>=4.2.83:../../math/gcalctool
DEPENDS+=	gconf-editor>=0.3.1nb2:../../editors/gconf-editor
DEPENDS+=	gedit>=2.2.1nb2:../../editors/gedit
DEPENDS+=	gdm>=2.2.0nb2:../../x11/gdm
DEPENDS+=	ggv>=2.0.0:../../print/ggv2
DEPENDS+=	glade2>=2.0.0:../../devel/glade2
DEPENDS+=	gnome-applets>=2.2.1:../../x11/gnome2-applets
DEPENDS+=	gnome-audio>=1.4.0:../../audio/gnome-audio
DEPENDS+=	gnome-games>=2.2.1:../../games/gnome2-games
DEPENDS+=	gnome-icon-theme>=1.0.2:../../graphics/gnome-icon-theme
DEPENDS+=	gnome-media>=2.2.1:../../audio/gnome2-media
DEPENDS+=	gnome-panel>=2.2.1:../../x11/gnome-panel
DEPENDS+=	gnome-session>=2.2.1:../../x11/gnome-session
DEPENDS+=	gnome-themes>=2.2:../../x11/gnome-themes
DEPENDS+=	gnome2-user-docs>=2.0.6:../../misc/gnome2-user-docs
DEPENDS+=	gnome2-terminal>=2.0.2nb1:../../x11/gnome2-terminal
DEPENDS+=	gnome-utils>=2.2.1:../../misc/gnome2-utils
DEPENDS+=	gnome-vfs2>=2.2.4:../../sysutils/gnome-vfs2
DEPENDS+=	gtk2-engines>=2.2.0:../../x11/gtk2-engines
DEPENDS+=	gtkmm>=2.2.1:../../x11/gtkmm
DEPENDS+=	nautilus>=2.2.3.1:../../sysutils/nautilus
DEPENDS+=	yelp>=2.2:../../misc/yelp

USE_X11=	yes
USE_BUILDLINK2=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
