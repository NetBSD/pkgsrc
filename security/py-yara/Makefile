# $NetBSD: Makefile,v 1.13 2022/11/28 18:57:19 adam Exp $

.include "../../security/yara/Makefile.common"

DISTNAME=	yara-python-${YARA_VERSION}
PKGNAME=	${PYPKGPREFIX}-yara-${YARA_VERSION}
CATEGORIES=	security python
GITHUB_PROJECT=	yara-python

COMMENT=	Yara Python bindings
LICENSE=	apache-2.0

PYSETUPBUILDARGS=	--dynamic-linking

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} tests.py

.include "../../security/yara/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
