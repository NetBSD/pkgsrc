# $NetBSD: Makefile,v 1.14 2023/09/07 12:07:18 adam Exp $

DISTNAME=	build-1.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/build/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/build
COMMENT=	Simple, correct PEP517 package builder
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-packaging>=19.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pyproject_hooks-[0-9]*:../../devel/py-pyproject_hooks

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=4.6:../../devel/py-importlib-metadata
.endif
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=1.0.0:../../textproc/py-tomli
.endif

# Generated setup.py; don't use wheel.mk as it depends on py-build.
pre-configure:
	${CP} ${FILESDIR}/setup.py ${WRKSRC}/

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pyproject-build pyproject-build-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
