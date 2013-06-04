# $NetBSD: Makefile,v 1.12 2013/06/04 22:16:12 tron Exp $
#

DISTNAME=	xye-0.9.1
PKGREVISION=	7
CATEGORIES=	games
MASTER_SITE_SOURCEFORGE_NEW= http://downloads.sourceforge.net/project/
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_NEW:=xye/xye/0.9.1/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xye.sourceforge.net/
COMMENT=	Kye clone

WRKSRC=		${WRKDIR}/xye-0.9.1
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-docdir=${PREFIX}/share/doc
USE_LANGUAGES=	c c++

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
