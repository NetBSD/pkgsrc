# $NetBSD: Makefile,v 1.17 2025/07/16 10:27:19 adam Exp $

.include "../../security/yara/Makefile.common"

DISTNAME=	yara_python-${YARA_VERSION}
PKGNAME=	${PYPKGPREFIX}-yara-${YARA_VERSION}
CATEGORIES=	security python
GITHUB_PROJECT=	yara-python

COMMENT=	Yara Python bindings
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} tests.py

.include "../../security/yara/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
