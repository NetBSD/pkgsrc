# $NetBSD: Makefile,v 1.63 2026/05/24 06:17:51 adam Exp $

DISTNAME=	paramiko-5.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/paramiko/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.paramiko.org/
COMMENT=	SSH2 protocol library
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-invoke>=2.0:../../sysutils/py-invoke
DEPENDS+=	${PYPKGPREFIX}-nacl>=1.5:../../security/py-nacl
TEST_DEPENDS+=	${PYPKGPREFIX}-icecream>=2.1:../../misc/py-icecream
TEST_DEPENDS+=	${PYPKGPREFIX}-test-relaxed>=2:../../devel/py-test-relaxed
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=3:../../devel/py-test-xdist

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../lang/python/wheel.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	bcrypt cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
