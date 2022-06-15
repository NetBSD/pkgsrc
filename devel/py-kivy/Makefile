# $NetBSD: Makefile,v 1.3 2022/06/15 08:34:57 spz Exp $

DISTNAME=	Kivy-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=K/Kivy/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://kivy.org/
COMMENT=	Library for rapid development of multitouch applications
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
BUILD_DEPENDS+=	${PYPKGPREFIX}-kivy-garden-[0-9]*:../../devel/py-kivy-garden
# not mentioned, but used
DEPENDS+=	${PYPKGPREFIX}-enchant>=1.6.5:../../textproc/py-enchant
DEPENDS+=	${PYPKGPREFIX}-game-[0-9]*:../../devel/py-game
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	27

pre-configure:
	${CHMOD} -R go-w ${WRKSRC}

.include "../../devel/py-cython/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
