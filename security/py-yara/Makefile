# $NetBSD: Makefile,v 1.14 2024/06/11 10:29:51 adam Exp $

.include "../../security/yara/Makefile.common"

DISTNAME=	yara_python-${YARA_VERSION}
PKGNAME=	${PYPKGPREFIX}-yara-${YARA_VERSION}
CATEGORIES=	security python
GITHUB_PROJECT=	yara-python

COMMENT=	Yara Python bindings
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} tests.py

.include "../../security/yara/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
