# $NetBSD: Makefile,v 1.60 2026/05/24 06:11:24 adam Exp $

DISTNAME=	fabric-3.2.3
CATEGORIES=	sysutils net python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Fabric/}

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	https://fabfile.org/
COMMENT=	Simple Pythonic remote deployment tool
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-decorator>=5:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-deprecated>=1.2:../../devel/py-deprecated
DEPENDS+=	${PYPKGPREFIX}-invoke>=2.0:../../sysutils/py-invoke
DEPENDS+=	${PYPKGPREFIX}-paramiko>=2.4:../../security/py-paramiko
TEST_DEPENDS+=	${PYPKGPREFIX}-icecream>=2.1:../../misc/py-icecream
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-relaxed>=2.0.1:../../devel/py-test-relaxed

USE_LANGUAGES=		# none

PYTHON_SELF_CONFLICT=	yes

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
