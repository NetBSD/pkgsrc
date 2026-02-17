# $NetBSD: Makefile,v 1.21 2026/02/17 14:08:35 adam Exp $

DISTNAME=	py2app-0.28.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/py2app/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ronaldoussoren/py2app
COMMENT=	Create standalone macOS applications with Python
LICENSE=	mit

ONLY_FOR_PLATFORM=	Darwin-*-*

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-altgraph>=0.17.5:../../graphics/py-altgraph
DEPENDS+=	${PYPKGPREFIX}-modulegraph>=0.19.7:../../devel/py-modulegraph
DEPENDS+=	${PYPKGPREFIX}-macholib>=1.16.4:../../devel/py-macholib
DEPENDS+=	${PYPKGPREFIX}-packaging>0:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-pyobjc-core-[0-9]*:../../devel/py-pyobjc-core

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} py2applet py2applet-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
