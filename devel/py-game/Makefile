# $NetBSD: Makefile,v 1.18 2011/01/11 15:34:18 drochner Exp $
#

DISTNAME=		pygame-1.8.1release
PKGNAME=		${PYPKGPREFIX}-game-1.8.1
PKGREVISION=		6
CATEGORIES=		devel
MASTER_SITES=		http://pygame.org/ftp/

MAINTAINER=		recht@NetBSD.org
HOMEPAGE=		http://pygame.org/
COMMENT=		Set of Python modules designed for writing games
LICENSE=		gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

# XXX
post-extract:
	${CHMOD} go+r ${WRKSRC}/lib/*

post-install:
	${CHMOD} 644 ${DESTDIR}${PREFIX}/${PYINC}/pygame/*.h
	${CHMOD} 644 ${DESTDIR}${PREFIX}/${PYSITELIB}/pygame/*.bmp
	${CHMOD} 644 ${DESTDIR}${PREFIX}/${PYSITELIB}/pygame/*.ico
	${CHMOD} 644 ${DESTDIR}${PREFIX}/${PYSITELIB}/pygame/*.icns
	${CHMOD} 644 ${DESTDIR}${PREFIX}/${PYSITELIB}/pygame/*.ttf
	${CHMOD} 644 ${DESTDIR}${PREFIX}/${PYSITELIB}/pygame/*.tiff

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
