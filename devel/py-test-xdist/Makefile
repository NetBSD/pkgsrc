# $NetBSD: Makefile,v 1.31 2022/01/13 19:31:22 wiz Exp $

DISTNAME=	pytest-xdist-1.34.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-xdist/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-xdist
COMMENT=	Plugin for distributed testing and loop-on-failing modes
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-execnet>=1.1:../../devel/py-execnet
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-test-forked-[0-9]*:../../devel/py-test-forked
TEST_DEPENDS+=	${PYPKGPREFIX}-filelock-[0-9]*:../../devel/py-filelock

PYTHON_VERSIONED_DEPENDENCIES=	test setuptools_scm:build

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} testing

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
