# $NetBSD: Makefile,v 1.11 2024/06/11 11:44:53 adam Exp $

DISTNAME=	stone-3.3.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/stone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dropbox/stone
COMMENT=	Interface description language (IDL) for APIs
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-test-runner>=5.3.2:../../devel/py-test-runner
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-ply>=3.4:../../devel/py-ply
DEPENDS+=	${PYPKGPREFIX}-six>=1.12.0:../../lang/py-six
# doesn't work:
# E   ModuleNotFoundError: No module named 'test.backend_test_util'
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# https://github.com/dropbox/stone/issues/266
post-extract:
	${ECHO} 'ply>= 3.4' > ${WRKSRC}/requirements.txt
	${ECHO} 'six>= 1.12.0' >> ${WRKSRC}/requirements.txt

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} stone stone-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
