# $NetBSD: Makefile,v 1.12 2004/06/28 19:36:31 jmmv Exp $

DISTNAME=	gnome-base-2.6.2
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for basic components of the GNOME desktop

DEPENDS+=	gdm>=2.6.0.3:../../x11/gdm
DEPENDS+=	gnome-icon-theme>=1.2.3:../../graphics/gnome-icon-theme
DEPENDS+=	gnome-panel>=2.6.2:../../x11/gnome-panel
DEPENDS+=	gnome-session>=2.6.2:../../x11/gnome-session
DEPENDS+=	gnome2-control-center>=2.6.1nb1:../../x11/gnome2-control-center
DEPENDS+=	gnome2-terminal>=2.6.1:../../x11/gnome2-terminal
DEPENDS+=	gnome-vfs2>=2.6.1.1:../../sysutils/gnome-vfs2
DEPENDS+=	metacity>=2.8.1:../../wm/metacity
DEPENDS+=	nautilus>=2.6.3:../../sysutils/nautilus
DEPENDS+=	xscreensaver>=4.16:../../x11/xscreensaver
DEPENDS+=	yelp>=2.6.1:../../misc/yelp

USE_X11=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_BUILDLINK=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
