# $NetBSD: Makefile,v 1.4 2005/12/11 09:40:38 wiz Exp $
#

DISTNAME=		pygame-1.7.1release
PKGNAME=		${PYPKGPREFIX}-game-1.7.1
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://pygame.org/ftp/

MAINTAINER=		recht@NetBSD.org
HOMEPAGE=		http://pygame.org/
COMMENT=		Set of Python modules designed for writing games

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

PYTHON_VERSIONS_INCOMPATIBLE=	21 20 15

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../math/py-Numeric/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
