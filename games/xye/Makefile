# $NetBSD: Makefile,v 1.1.1.1 2008/06/23 16:56:39 drochner Exp $
#

DISTNAME=	xye-source-0.8.0
PKGNAME=	xye-0.8.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xye/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xye.sourceforge.net/
COMMENT=	Kye clone

WRKSRC=		${WRKDIR}/xye-0.8.0
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-docdir=${PREFIX}/share/doc
USE_LANGUAGES=	c c++

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
