# $NetBSD: Makefile,v 1.9 2020/05/16 08:57:58 adam Exp $

DISTNAME=	pytest-flake8-1.0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-flake8/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tholo/pytest-flake8
COMMENT=	Plugin plugin to check FLAKE8 requirements
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-flake8>=3.5:../../devel/py-flake8

PYTHON_VERSIONED_DEPENDENCIES=	test

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
