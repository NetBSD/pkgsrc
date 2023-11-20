# $NetBSD: Makefile,v 1.5 2023/11/20 06:36:47 wiz Exp $

DISTNAME=	Kivy-2.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=K/Kivy/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://kivy.org/
COMMENT=	Library for rapid development of multitouch applications
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
TOOL_DEPENDS+=	${PYPKGPREFIX}-kivy-garden-[0-9]*:../../devel/py-kivy-garden
# not mentioned, but used
DEPENDS+=	${PYPKGPREFIX}-enchant>=1.6.5:../../textproc/py-enchant
DEPENDS+=	${PYPKGPREFIX}-game-[0-9]*:../../devel/py-game
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
TEST_DEPENDS+=	${PYPKGPREFIX}-test-benchmark-[0-9]*:../../devel/py-test-benchmark

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	27

pre-configure:
	${CHMOD} -R go-w ${WRKSRC}

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
