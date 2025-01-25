# $NetBSD: Makefile,v 1.30 2025/01/25 11:47:31 adam Exp $

DISTNAME=	pydantic-2.10.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydantic/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pydantic/pydantic
COMMENT=	Data validation and settings management using python type hints
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-fancy-pypi-readme>=22.5.0:../../devel/py-hatch-fancy-pypi-readme
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-annotated-types>=0.6.0:../../lang/py-annotated-types
DEPENDS+=	${PYPKGPREFIX}-pydantic-core>=2.27.2:../../devel/py-pydantic-core
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.12.2:../../devel/py-typing-extensions
TEST_DEPENDS+=	${PYPKGPREFIX}-cloudpickle-[0-9]*:../../converters/py-cloudpickle
TEST_DEPENDS+=	${PYPKGPREFIX}-dirty-equals-[0-9]*:../../devel/py-dirty-equals
TEST_DEPENDS+=	${PYPKGPREFIX}-email_validator>=2.0.0:../../mail/py-email_validator
TEST_DEPENDS+=	${PYPKGPREFIX}-faker>=18.13.0:../../devel/py-faker
TEST_DEPENDS+=	${PYPKGPREFIX}-jsonschema>=4.23.0:../../textproc/py-jsonschema
TEST_DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
TEST_DEPENDS+=	${PYPKGPREFIX}-rich-[0-9]*:../../comms/py-rich
TEST_DEPENDS+=	${PYPKGPREFIX}-test-benchmark>=4.0.0:../../devel/py-test-benchmark
TEST_DEPENDS+=	${PYPKGPREFIX}-test-examples-[0-9]*:../../devel/py-test-examples
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock

USE_LANGUAGES=	# none

# TODO: import cloudpickle and test-examples
pre-test:
	${RM} -f ${WRKSRC}/tests/test_docs.py ${WRKSRC}/tests/test_pickle.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
