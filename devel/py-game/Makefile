# $NetBSD: Makefile,v 1.11 2008/11/10 23:10:34 wiz Exp $
#

DISTNAME=		pygame-1.8.1release
PKGNAME=		${PYPKGPREFIX}-game-1.8.1
CATEGORIES=		devel
MASTER_SITES=		http://pygame.org/ftp/

MAINTAINER=		recht@NetBSD.org
HOMEPAGE=		http://pygame.org/
COMMENT=		Set of Python modules designed for writing games

PKG_DESTDIR_SUPPORT=	user-destdir

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../math/py-Numeric/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
