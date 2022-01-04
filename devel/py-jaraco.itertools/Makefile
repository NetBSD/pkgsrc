# $NetBSD: Makefile,v 1.3 2022/01/04 20:53:13 wiz Exp $

DISTNAME=	jaraco.itertools-5.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jaraco.itertools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/jaraco.itertools
COMMENT=	Additional itertools in the spirit of stdlib's itertools
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=1.15.0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-inflect-[0-9]*:../../lang/py-inflect

# testing pytest >=3.5, pytest-checkdocs>=1.2.3, pytest-flake8, pytest-black-multipy, pytest-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_VERSIONED_DEPENDENCIES+=	more-itertools

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
