# $NetBSD: Makefile,v 1.1.1.1 2004/01/24 22:53:39 jmmv Exp $

DISTNAME=	gnome-base-2.4.1
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for basic components of the GNOME desktop

DEPENDS+=	gdm>=2.4.4.7:../../x11/gdm
DEPENDS+=	gnome-panel>=2.4.1:../../x11/gnome-panel
DEPENDS+=	gnome-session>=2.4.1:../../x11/gnome-session
DEPENDS+=	gnome2-control-center>=2.4.0:../../x11/gnome2-control-center
DEPENDS+=	gnome2-terminal>=2.4.1:../../x11/gnome2-terminal
DEPENDS+=	gnome-vfs2>=2.4.1:../../sysutils/gnome-vfs2
DEPENDS+=	metacity>=2.6.3:../../wm/metacity
DEPENDS+=	nautilus>=2.4.1:../../sysutils/nautilus
DEPENDS+=	xscreensaver>=4.14nb1:../../x11/xscreensaver
DEPENDS+=	yelp>=2.4.2:../../misc/yelp

USE_X11=	yes
USE_BUILDLINK2=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
