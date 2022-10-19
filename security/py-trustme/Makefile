# $NetBSD: Makefile,v 1.14 2022/10/19 13:56:33 nia Exp $

DISTNAME=	trustme-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/trustme/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-trio/trustme
COMMENT=	Number on quality TLS certs while you wait
LICENSE=	apache-2.0 OR mit

DEPENDS+=	${PYPKGPREFIX}-idna-[0-9]*:../../www/py-idna
TEST_DEPENDS+=	${PYPKGPREFIX}-service_identity-[0-9]*:../../security/py-service_identity
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
