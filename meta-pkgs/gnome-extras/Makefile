# $NetBSD: Makefile,v 1.1.1.1 2004/01/24 22:59:47 jmmv Exp $

DISTNAME=	gnome-extras-2.4.1
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for applications related to the GNOME desktop

DEPENDS+=	abiword>=2.0.2:../../editors/abiword
DEPENDS+=	conglomerate>=0.7.6:../../editors/conglomerate
DEPENDS+=	evolution>=1.4.5:../../mail/evolution
DEPENDS+=	gaim>=0.75:../../chat/gaim
DEPENDS+=	gnome>=2.4.1:../../meta-pkgs/gnome
DEPENDS+=	gqview>=1.3.8:../../graphics/gqview-devel
DEPENDS+=	mergeant>=0.12.1:../../databases/mergeant
DEPENDS+=	pan>=0.14.2:../../news/pan
DEPENDS+=	seahorse>=0.7.3:../../security/seahorse
DEPENDS+=	rhythmbox>=0.6.5:../../audio/rhythmbox
DEPENDS+=	xcdroast>=0.98a15:../../sysutils/xcdroast
DEPENDS+=	xchat>=2.0.7:../../chat/xchat2

USE_X11=	yes
USE_BUILDLINK2=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
