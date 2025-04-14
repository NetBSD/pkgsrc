# $NetBSD: Makefile,v 1.16 2025/04/14 05:17:12 adam Exp $

.include "../../security/yara/Makefile.common"

DISTNAME=	yara_python-${YARA_VERSION}
PKGNAME=	${PYPKGPREFIX}-yara-${YARA_VERSION}
PKGREVISION=	1
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
