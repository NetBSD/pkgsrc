# $NetBSD: Makefile,v 1.18 2025/12/28 08:15:02 adam Exp $

.include "../../security/yara/Makefile.common"

DISTNAME=	yara_python-4.5.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_python//}
CATEGORIES=	security python
GITHUB_PROJECT=	yara-python
GITHUB_TAG=	v${PKGVERSION_NOREV}

COMMENT=	Yara Python bindings
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} tests.py

.include "../../security/yara/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
