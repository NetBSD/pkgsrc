# $NetBSD: Makefile,v 1.2 2007/09/04 19:36:46 joerg Exp $
#

DISTNAME=	six-0.5.3
PKGREVISION=	1
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
