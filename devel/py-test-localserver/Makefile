# $NetBSD: Makefile,v 1.2 2017/10/09 08:47:02 wiz Exp $

DISTNAME=	pytest-localserver-0.3.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-localserver/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/pytest-dev/pytest-localserver/
COMMENT=	py.test plugin to test server connections locally
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-werkzeug>=0.10:../../www/py-werkzeug
# Tests
BUILD_DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
BUILD_DEPENDS+=	${PYPKGPREFIX}-test>=2.0.0:../../devel/py-test
BUILD_DEPENDS+=		${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=		# none

do-test:
	cd ${WRKSRC}/tests && py.test-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
