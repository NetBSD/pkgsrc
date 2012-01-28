# $NetBSD: Makefile,v 1.26 2012/01/28 17:27:29 wiz Exp $
#

DISTNAME=		pygame-1.8.1release
PKGNAME=		${PYPKGPREFIX}-game-1.8.1
PKGREVISION=		11
CATEGORIES=		devel
MASTER_SITES=		http://pygame.org/ftp/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pygame.org/
COMMENT=		Set of Python modules designed for writing games
LICENSE=		gnu-lgpl-v2.1

DEPENDS+=		${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy

PKG_DESTDIR_SUPPORT=	user-destdir

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

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-no-integrated-as
.endif

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../multimedia/smpeg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
