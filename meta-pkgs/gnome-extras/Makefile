# $NetBSD: Makefile,v 1.16 2004/06/28 19:36:31 jmmv Exp $

DISTNAME=	gnome-extras-2.6.2
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for applications related to the GNOME desktop

DEPENDS+=	abiword>=2.0.2:../../editors/abiword
DEPENDS+=	balsa>=2.0.10:../../mail/balsa2
DEPENDS+=	conglomerate>=0.7.12:../../editors/conglomerate
DEPENDS+=	epiphany-extensions>=0.8.2:../../www/epiphany-extensions
DEPENDS+=	evolution>=1.4.6:../../mail/evolution
DEPENDS+=	gaim>=0.77:../../chat/gaim
DEPENDS+=	glade2>=2.0.0:../../devel/glade2
DEPENDS+=	gnome>=2.6.2:../../meta-pkgs/gnome
DEPENDS+=	gnome-audio>=2.0.0:../../audio/gnome-audio
DEPENDS+=	gnome-themes-extras>=0.6:../../x11/gnome-themes-extras
DEPENDS+=	gqview>=1.4.3:../../graphics/gqview
DEPENDS+=	mergeant>=0.12.1:../../databases/mergeant
DEPENDS+=	pan>=0.14.2:../../news/pan
DEPENDS+=	rhythmbox>=0.8.5:../../audio/rhythmbox
DEPENDS+=	seahorse>=0.7.3nb11:../../security/seahorse
DEPENDS+=	xcdroast>=0.98a15:../../sysutils/xcdroast
DEPENDS+=	xchat>=2.0.9:../../chat/xchat2

USE_X11=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_BUILDLINK=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
