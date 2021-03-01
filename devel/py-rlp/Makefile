# $NetBSD: Makefile,v 1.8 2021/03/01 11:57:20 mef Exp $

DISTNAME=	rlp-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rlp/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/ethereum/pyrlp
COMMENT=	Package for Recursive Length Prefix encoding and decoding
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-eth-utils>=1.0.2:../../finance/py-eth-utils
DEPENDS+=	${PYPKGPREFIX}-markdown-[0-9]*:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-certifi-[0-9]*:../../security/py-certifi

TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=5.19.0:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=5.4.3:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-tox>=2.9.1:../../devel/py-tox

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
