# $NetBSD: Makefile,v 1.20 2014/11/07 19:39:30 adam Exp $
#

DISTNAME=	holtz-1.3.1
PKGREVISION=	18
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=holtz/}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://holtz.sourceforge.net/
COMMENT=	Engine for the abstract strategy games Zèrtz and Dvonn
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
