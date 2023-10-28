# $NetBSD: Makefile,v 1.8 2023/10/28 19:57:14 wiz Exp $

DISTNAME=	fido2-1.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fido2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developers.yubico.com/python-fido2/
COMMENT=	Yubico FIDO U2F and FIDO 2.0 USB Python library
LICENSE=	2-clause-bsd AND apache-2.0 AND mpl-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-cryptography>=0:../../security/py-cryptography
# optional
DEPENDS+=	${PYPKGPREFIX}-scard>=2.0.0:../../devel/py-scard
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=7.0:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
