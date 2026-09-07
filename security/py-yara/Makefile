# $NetBSD: Makefile,v 1.19 2026/09/07 10:57:26 adam Exp $

.include "../../security/yara/Makefile.common"

DISTNAME=	yara_python-4.5.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_python//}
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
