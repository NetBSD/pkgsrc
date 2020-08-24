# $NetBSD: Makefile,v 1.6 2020/08/24 08:32:43 wiz Exp $

DISTNAME=	jedi-0.17.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	editors python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jedi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/davidhalter/jedi
COMMENT=	Autocompletion tool for Python that can be used for text editors
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-parso>=0.1.0:../../lang/py-parso
DEPENDS+=	${PYPKGPREFIX}-readline-[0-9]*:../../devel/py-readline
TEST_DEPENDS+=	${PYPKGPREFIX}-colorama-[0-9]*:../../comms/py-colorama
TEST_DEPENDS+=	${PYPKGPREFIX}-docopt-[0-9]*:../../devel/py-docopt

PYTHON_VERSIONED_DEPENDENCIES=	test:test

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-parso

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
