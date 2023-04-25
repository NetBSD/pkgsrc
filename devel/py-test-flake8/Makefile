# $NetBSD: Makefile,v 1.13 2023/04/25 14:34:20 wiz Exp $

DISTNAME=	pytest-flake8-1.0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-flake8/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tholo/pytest-flake8
COMMENT=	Plugin plugin to check FLAKE8 requirements
LICENSE=	modified-bsd

# not declared, but py.io is used as of 1.0.7
DEPENDS+=	${PYPKGPREFIX}-py-[0-9]*:../../devel/py-py

PYTHON_VERSIONED_DEPENDENCIES+=	test
PYTHON_VERSIONED_DEPENDENCIES+=	flake8

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
