# $NetBSD: Makefile,v 1.21 2012/09/15 10:04:43 obache Exp $
#

DISTNAME=	six-0.5.3
PKGREVISION=	17
CATEGORIES=	games
MASTER_SITES=	http://six.retes.hu/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://six.retes.hu/
COMMENT=	Hex, a board game with very simple rules

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
SET_LIBDIR=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
