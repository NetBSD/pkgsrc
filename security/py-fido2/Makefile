#	$NetBSD: Makefile,v 1.5 2023/03/12 14:01:04 wiz Exp $

DISTNAME=	fido2-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=Yubico/}
GITHUB_PROJECT=	python-fido2
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developers.yubico.com/python-fido2/
COMMENT=	Yubico FIDO U2F and FIDO 2.0 USB Python library
LICENSE=	2-clause-bsd AND apache-2.0 AND mpl-2.0

DEPENDS+=	${PYPKGPREFIX}-scard>=0:../../devel/py-scard
DEPENDS+=	${PYPKGPREFIX}-cryptography>=0:../../security/py-cryptography
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=2:../../devel/py-test
TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1:../../devel/py-poetry-core

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/${PYSITELIB}/fido2/hid/*.orig

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
