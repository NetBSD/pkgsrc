# $NetBSD: Makefile,v 1.2 2002/07/11 19:44:28 wiz Exp $

DISTNAME=	gnome-1.4.0.6
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	meta-package for the GNU Network Object Model Environment

DEPENDS+=	gnome-core>=1.4.0.4nb1:../../x11/gnome-core
DEPENDS+=	ee>=0.3.12:../../graphics/ee
DEPENDS+=	gdm>=2.2.0:../../x11/gdm
DEPENDS+=	ggv>=1.0.1:../../print/ggv
DEPENDS+=	glade>=0.6.2:../../devel/glade
DEPENDS+=	gmc>=4.5.42:../../sysutils/gmc
DEPENDS+=	gnome-applets>1.4.0:../../x11/gnome-applets
DEPENDS+=	gnome-audio>=1.4.0:../../audio/gnome-audio
DEPENDS+=	gnome-chess>=0.2.4:../../games/gnome-chess
DEPENDS+=	gnome-games>1.4.0:../../games/gnome-games
DEPENDS+=	gnome-media>=1.2.0:../../audio/gnome-media
DEPENDS+=	gnome-pim>=1.4.0:../../misc/gnome-pim
DEPENDS+=	gnome-users-guide>=1.2:../../x11/gnome-users-guide
DEPENDS+=	gnome-utils>=1.4.1:../../misc/gnome-utils
DEPENDS+=	evolution>=1.0.2:../../mail/evolution
DEPENDS+=	gnumeric>=0.75:../../math/gnumeric0
DEPENDS+=	gtk-->=1.2.5:../../x11/gtk--
DEPENDS+=	gtk-engines>=0.12:../../x11/gtk-engines
DEPENDS+=	gtop>=1.0.13:../../sysutils/gtop
DEPENDS+=	pan>0.10.0:../../news/pan
DEPENDS+=	xchat>=1.8.7:../../chat/xchat

USE_X11=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../x11/gnome-python/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
