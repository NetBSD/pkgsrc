# $NetBSD: Makefile,v 1.2 2006/01/24 07:32:21 wiz Exp $
#

DISTNAME=	matchbox-0.9.5
PKGREVISION=	1
CATEGORIES=	meta-pkgs x11 wm
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://projects.o-hand.com/matchbox/
COMMENT=	The Matchbox window manager environment

DEPENDS+=	libmatchbox-[0-9]*:../../devel/libmatchbox
DEPENDS+=	matchbox-wm-[0-9]*:../../wm/matchbox-wm
DEPENDS+=	matchbox-common-[0-9]*:../../x11/matchbox-common
DEPENDS+=	matchbox-desktop-[0-9]*:../../x11/matchbox-desktop
DEPENDS+=	matchbox-nest-[0-9]*:../../x11/matchbox-nest
DEPENDS+=	matchbox-panel-[0-9]*:../../x11/matchbox-panel
DEPENDS+=	matchbox-panel-manager-[0-9]*:../../x11/matchbox-panel-manager
DEPENDS+=	matchbox-themes-extra-[0-9]*:../../x11/matchbox-themes-extra

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
