# $NetBSD: Makefile,v 1.32 2013/10/25 22:24:58 wiz Exp $

DISTNAME=	pygame-1.9.1release
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/release//}
CATEGORIES=	games
MASTER_SITES=	http://www.pygame.org/ftp/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.pygame.org/
COMMENT=	Set of Python modules designed for writing games
LICENSE=	gnu-lgpl-v2.1

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-no-integrated-as
.endif

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
