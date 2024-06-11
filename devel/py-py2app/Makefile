# $NetBSD: Makefile,v 1.17 2024/06/11 06:36:41 adam Exp $

DISTNAME=	py2app-0.28.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/py2app/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ronaldoussoren/py2app
COMMENT=	Create standalone macOS applications with Python
LICENSE=	mit

ONLY_FOR_PLATFORM=	Darwin-*-*

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-altgraph>=0.17.3:../../graphics/py-altgraph
DEPENDS+=	${PYPKGPREFIX}-modulegraph>=0.19.6:../../devel/py-modulegraph
DEPENDS+=	${PYPKGPREFIX}-macholib>=1.16.2:../../devel/py-macholib
TEST_DEPENDS+=	${PYPKGPREFIX}-pyobjc-core-[0-9]*:../../devel/py-pyobjc-core

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} py2applet py2applet-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
