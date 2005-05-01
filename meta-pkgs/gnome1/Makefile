# $NetBSD: Makefile,v 1.11 2005/05/01 12:30:11 wiz Exp $

DISTNAME=	gnome-1.4.2.1
PKGREVISION=	9
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for the GNU Network Object Model Environment

DEPENDS+=	gnome-core>=1.4.2:../../x11/gnome-core
DEPENDS+=	ee>=0.3.12nb3:../../graphics/ee
DEPENDS+=	gdm>=2.2.0nb2:../../x11/gdm1
DEPENDS+=	ggv>=1.0.2nb5:../../print/ggv
DEPENDS+=	glade>=0.6.2nb4:../../devel/glade
DEPENDS+=	gnome-applets>=1.4.0.4nb3:../../x11/gnome-applets
DEPENDS+=	gnome-audio>=1.4.0:../../audio/gnome-audio
DEPENDS+=	gnome-chess>=0.3.3nb4:../../games/gnome-chess
DEPENDS+=	gnome-games>1.4.0:../../games/gnome-games
DEPENDS+=	gnome-media>=1.2.3nb3:../../multimedia/gnome-media
DEPENDS+=	gnome-pim>=1.4.6:../../misc/gnome-pim
DEPENDS+=	gnome-users-guide>=1.2:../../x11/gnome-users-guide
DEPENDS+=	gnome-utils>=1.4.1.2:../../misc/gnome-utils
DEPENDS+=	evolution>=1.2.1:../../mail/evolution12
DEPENDS+=	gtk-->=1.2.10:../../x11/gtk--
DEPENDS+=	gtk-engines>=0.12:../../x11/gtk-engines
DEPENDS+=	gtop>=1.0.13nb2:../../sysutils/gtop
DEPENDS+=	xchat-gnome>=1.8.10nb3:../../chat/xchat-gnome

USE_X11=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../x11/gnome-python/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
