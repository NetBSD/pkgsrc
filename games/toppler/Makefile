# $NetBSD: Makefile,v 1.1 2013/01/05 22:17:04 wiz Exp $
#

DISTNAME=	toppler-1.1.6
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=toppler/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://toppler.sourceforge.net/
COMMENT=	Tower Toppler/Nebulous clone
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

.include "../../devel/SDL/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
