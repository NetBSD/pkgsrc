# $NetBSD: Makefile,v 1.10 2004/04/01 19:17:24 jmmv Exp $

DISTNAME=	gnome-base-2.6.0
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for basic components of the GNOME desktop

DEPENDS+=	gdm>=2.6.0.0:../../x11/gdm
DEPENDS+=	gnome-icon-theme>=1.2.0:../../graphics/gnome-icon-theme
DEPENDS+=	gnome-panel>=2.6.0:../../x11/gnome-panel
DEPENDS+=	gnome-session>=2.6.0:../../x11/gnome-session
DEPENDS+=	gnome2-control-center>=2.6.0:../../x11/gnome2-control-center
DEPENDS+=	gnome2-terminal>=2.6.0:../../x11/gnome2-terminal
DEPENDS+=	gnome-vfs2>=2.6.0:../../sysutils/gnome-vfs2
DEPENDS+=	metacity>=2.8.0:../../wm/metacity
DEPENDS+=	nautilus>=2.6.0:../../sysutils/nautilus
DEPENDS+=	xscreensaver>=4.14nb1:../../x11/xscreensaver
DEPENDS+=	yelp>=2.6.0:../../misc/yelp

USE_X11=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_BUILDLINK=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
