# $NetBSD: Makefile,v 1.14 2022/10/31 08:26:13 adam Exp $

DISTNAME=	py2app-0.28.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/py2app/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/ronaldoussoren/py2app
COMMENT=	Create standalone Mac OS X applications with Python
LICENSE=	mit

ONLY_FOR_PLATFORM=	Darwin-*-*

DEPENDS+=	${PYPKGPREFIX}-altgraph>=0.16:../../graphics/py-altgraph
DEPENDS+=	${PYPKGPREFIX}-modulegraph>=0.19.3:../../devel/py-modulegraph
DEPENDS+=	${PYPKGPREFIX}-macholib>=1.16:../../devel/py-macholib
TEST_DEPENDS+=	${PYPKGPREFIX}-pyobjc-core-[0-9]*:../../devel/py-pyobjc-core

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} py2applet py2applet-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
