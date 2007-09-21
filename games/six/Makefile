# $NetBSD: Makefile,v 1.3 2007/09/21 13:03:45 wiz Exp $
#

DISTNAME=	six-0.5.3
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://six.retes.hu/download/

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	http://six.retes.hu/
COMMENT=	Hex, a board game with very simple rules

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
