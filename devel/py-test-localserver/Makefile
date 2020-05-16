# $NetBSD: Makefile,v 1.5 2020/05/16 16:30:16 adam Exp $

DISTNAME=	pytest-localserver-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-localserver/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/pytest-dev/pytest-localserver/
COMMENT=	Py.test plugin to test server connections locally
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-werkzeug>=0.10:../../www/py-werkzeug
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests

PYTHON_VERSIONED_DEPENDENCIES=	test:test

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC}/tests && pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
