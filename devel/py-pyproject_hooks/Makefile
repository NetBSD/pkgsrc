# $NetBSD: Makefile,v 1.1 2023/02/14 17:42:54 adam Exp $

DISTNAME=	pyproject_hooks-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyproject_hooks/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pyproject-hooks.readthedocs.io/
COMMENT=	Wrappers to call pyproject.toml-based build backend hooks
LICENSE=	mit

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} != 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=1.1.0:../../textproc/py-tomli
.endif

# Generated setup.py; don't use wheel.mk as py-build depends on this package.
pre-configure:
	${CP} ${FILESDIR}/setup.py ${WRKSRC}/

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
