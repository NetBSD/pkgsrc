# $NetBSD: Makefile,v 1.1.1.1 2003/04/25 06:39:19 rh Exp $

DISTNAME=	gnome-2.2
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	meta-package for the GNU Network Object Model Environment

DEPENDS+=	gdm>=2.2.0nb2:../../x11/gdm
DEPENDS+=	ggv>=2.0.0:../../print/ggv2
DEPENDS+=	glade2>=2.0.0:../../devel/glade2
DEPENDS+=	gnome-applets>=2.2.1:../../x11/gnome2-applets
DEPENDS+=	gnome-audio>=1.4.0:../../audio/gnome-audio
DEPENDS+=	gnome-games>=2.2.1:../../games/gnome2-games
DEPENDS+=	gnome-media>=2.2.1:../../audio/gnome2-media
DEPENDS+=	gnome-panel>=2.2.1:../../x11/gnome-panel
DEPENDS+=	gnome-session>=2.2.1:../../x11/gnome-session
DEPENDS+=	gnome-utils>=2.2.1:../../misc/gnome2-utils
DEPENDS+=	gtk2-engines>=2.2.0:../../x11/gtk2-engines
DEPENDS+=	gtkmm>=2.2.1:../../x11/gtkmm
#DEPENDS+=	evolution>=1.4:../../mail/evolution2

USE_X11=	yes
USE_BUILDLINK2=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
