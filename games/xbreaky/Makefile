# $NetBSD: Makefile,v 1.19 2011/05/24 11:32:54 obache Exp $
#

DISTNAME=	xbreaky-0.0.5
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://xbreaky.sourceforge.net/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://xbreaky.sourceforge.net/
COMMENT=	Breakout game for X11
LICENSE=	gnu-gpl-v2 # or later

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
