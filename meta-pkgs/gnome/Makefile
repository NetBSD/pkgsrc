# $NetBSD: Makefile,v 1.25 2004/01/24 22:55:07 jmmv Exp $

DISTNAME=	gnome-2.4.1
PKGREVISION=	3
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for the GNU Network Object Model Environment

DEPENDS+=	balsa>=2.0.10:../../mail/balsa2
DEPENDS+=	eog>=2.5.1:../../graphics/eog2
DEPENDS+=	file-roller>=2.4.2:../../archivers/file-roller
DEPENDS+=	gcalctool>=4.2.83:../../math/gcalctool
DEPENDS+=	gconf-editor>=2.4.0:../../editors/gconf-editor
DEPENDS+=	gedit>=2.4.1:../../editors/gedit
DEPENDS+=	ggv>=2.4.0.2:../../print/ggv2
DEPENDS+=	glade2>=2.0.0:../../devel/glade2
DEPENDS+=	gnome-applets>=2.4.1:../../x11/gnome2-applets
DEPENDS+=	gnome-base>=2.4.1:../../meta-pkgs/gnome-base
DEPENDS+=	gnome-audio>=2.0.0:../../audio/gnome-audio
DEPENDS+=	gnome-games>=2.4.1:../../games/gnome2-games
DEPENDS+=	gnome-icon-theme>=1.0.9:../../graphics/gnome-icon-theme
DEPENDS+=	gnome-media>=2.4.1.1:../../audio/gnome2-media
DEPENDS+=	gnome-themes>=2.4.1:../../x11/gnome-themes
DEPENDS+=	gnome2-user-docs>=2.4.1:../../misc/gnome2-user-docs
DEPENDS+=	gnome2-system-monitor>=2.4.0:../../sysutils/gnome2-system-monitor
DEPENDS+=	gnome-utils>=2.4.1:../../misc/gnome2-utils
DEPENDS+=	gtk2-extras>=2.2.4:../../meta-pkgs/gtk2-extras
DEPENDS+=	vera-ttf>=1.10:../../fonts/vera-ttf

USE_X11=	yes
USE_BUILDLINK2=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
